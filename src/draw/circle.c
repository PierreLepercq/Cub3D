/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre_lepercq <pierre_lepercq@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 01:40:05 by pierre_lepe       #+#    #+#             */
/*   Updated: 2026/11/02 03:23:03 by pierre_lepe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

//	Bresenham's mid-point circle algorithm
void	draw_circle(t_frame f, t_vec2 pos, int r, t_color c)
{
	t_vec2	px;
	float	hyp;

	px.x = 0;
	px.y = r;
	while (px.x < px.y)
	{
		hyp = pow(px.x, 2) + pow(px.y - 0.5, 2);
		if (hyp > pow(r, 2))
			px.y--;
		draw_pixel(f, vec2(pos.x + px.x, pos.y + px.y), c);
		draw_pixel(f, vec2(pos.x - px.x, pos.y + px.y), c);
		draw_pixel(f, vec2(pos.x + px.x, pos.y - px.y), c);
		draw_pixel(f, vec2(pos.x - px.x, pos.y - px.y), c);
		draw_pixel(f, vec2(pos.x + px.y, pos.y + px.x), c);
		draw_pixel(f, vec2(pos.x + px.y, pos.y - px.x), c);
		draw_pixel(f, vec2(pos.x - px.y, pos.y + px.x), c);
		draw_pixel(f, vec2(pos.x - px.y, pos.y - px.x), c);
		px.x++;
	}
}

void	draw_circle_aa(t_frame f, t_vec2 pos, int r, int thickness, t_color c)
{
	t_vec2	px;
    float   dist;
    float   alpha;

	px = vec2(pos.x - r - thickness, pos.y - r - thickness);
	while (px.x <= pos.x + r + thickness)
    {
        while(px.y <= pos.y + r + thickness)
        {
            dist = vec2_len(vec2_sub(px, pos));
			alpha = (255 - (float)c.a) / 255;
			alpha *= thickness + 0.5f - fabsf(dist - r);
			if (alpha > 1)
				alpha = 1;
            if (alpha > 0)
            {
                alpha = (1 - alpha) * 255;
                draw_pixel(f, px, argb(alpha, c.r, c.g, c.b));
            }
            px.y++;
        }
        px.y = 0;
        px.x++;
    }
}

//	Bresenham's mid-point circle algorithm
void	draw_fillcircle(t_frame f, t_vec2 pos, int r, t_color c)
{
	t_vec2	px;
	float	hyp;

	px.x = 1;
	px.y = r;
	draw_pixel(f, pos, c);
    draw_line(f, vec2(pos.x, pos.y + 1), vec2(pos.x, pos.y + r), c);
	draw_line(f, vec2(pos.x, pos.y - 1), vec2(pos.x, pos.y - r), c);
    draw_line(f, vec2(pos.x + 1, pos.y), vec2(pos.x + r, pos.y), c);
	draw_line(f, vec2(pos.x - 1, pos.y), vec2(pos.x - r, pos.y), c);
	while (px.x < px.y)
	{
		hyp = pow(px.x, 2) + pow(px.y - 0.5, 2);
		if (hyp > pow(r, 2))
			px.y--;
		draw_line(f, vec2(pos.x + px.x, pos.y + px.y), vec2(pos.x + px.x, pos.y + px.x + 1), c);
		draw_line(f, vec2(pos.x - px.x, pos.y + px.y), vec2(pos.x - px.x, pos.y + px.x + 1), c);
		draw_line(f, vec2(pos.x + px.x, pos.y - px.y), vec2(pos.x + px.x, pos.y - px.x - 1), c);
		draw_line(f, vec2(pos.x - px.x, pos.y - px.y), vec2(pos.x - px.x, pos.y - px.x - 1), c);
		draw_line(f, vec2(pos.x + px.y, pos.y + px.x), vec2(pos.x + px.x, pos.y + px.x), c);
		draw_line(f, vec2(pos.x + px.y, pos.y - px.x), vec2(pos.x + px.x, pos.y - px.x), c);
		draw_line(f, vec2(pos.x - px.y, pos.y + px.x), vec2(pos.x - px.x, pos.y + px.x), c);
		draw_line(f, vec2(pos.x - px.y, pos.y - px.x), vec2(pos.x - px.x, pos.y - px.x), c);
		px.x++;
	}
}

void	draw_fillcircle_aa(t_frame f, t_vec2 pos, int r, t_color c)
{
	t_vec2	px;
    float   dist;
    float   alpha;

	px = vec2(pos.x - r - 1, pos.y - r - 1);
	while (px.x <= pos.x + r + 1)
    {
        while(px.y <= pos.y + r + 1)
        {
            dist = vec2_len(vec2_sub(px, pos));
            alpha = (r + 0.5 - dist - ( 2. / 2.));
            if (alpha > 1.0f)
                alpha = 1.0f;
            if (alpha > 0.0f)
            {
                alpha *= (255 - (float)c.a) / 255;
                alpha = (1 - alpha) * 255;
                draw_pixel(f, px, argb(alpha, c.r, c.g, c.b));
            }
            px.y++;
        }
        px.y = 0;
        px.x++;
    }
}
