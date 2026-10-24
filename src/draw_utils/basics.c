/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre_lepercq <pierre_lepercq@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 23:54:39 by pierre_lepe       #+#    #+#             */
/*   Updated: 2026/10/24 12:32:05 by pierre_lepe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "stdio.h"

void	draw_pixel(t_frame f, t_vec2 pos, t_color color)
{
	char	*dst;
	t_color	bg_color;

	dst = f.addr;
	dst += pos.y * f.line_length;
	dst += pos.x * (f.bits_per_pixel / 8);
	bg_color = hex_to_color(*(uint32_t*)dst);
	//bg_color = color_blend(bg_color, color);
	//if (bg_color.r > 0 || bg_color.g > 0 || bg_color.b > 0)
	//	printf("COLOR : %i, %i, %i, %i\n", bg_color.a, bg_color.r, bg_color.g, bg_color.b);
	*(uint32_t*)dst = color_to_hex(color_blend(bg_color, color));
}

void    draw_line(t_frame f, t_vec2 pos1, t_vec2 pos2, t_color color)
{
    t_vec2  delta;
	int		i;
    int		step;
	float	inc_x;
	float	inc_y;

    delta = vec2(pos2.x - pos1.x, pos2.y - pos1.y);
    if (abs(delta.x) > abs(delta.y))
		step = abs(delta.x);
	else
		step = abs(delta.y);
	inc_x = delta.x / step;
	inc_y = delta.y / step;
	i = 0;
	while (i < step)
	{
		draw_pixel(f, vec2(pos1.x + (i * inc_x), pos1.y + (i * inc_y)), color);
		i++;
	}
	draw_pixel(f, vec2(pos1.x + (i * inc_x), pos1.y + (i * inc_y)), color);
}

void	draw_rect2(t_frame f, t_vec2 pos1, t_vec2 pos2, t_color color)
{
	draw_line(f, pos1, vec2(pos1.x, pos2.y), color);
	draw_line(f, pos1, vec2(pos2.x, pos1.y), color);
	draw_line(f, pos2, vec2(pos1.x, pos2.y), color);
	draw_line(f, pos2, vec2(pos2.x, pos1.y), color);
}

void	draw_rect(t_frame f, t_vec2 pos1, t_vec2 pos2, t_color color)
{
	t_vec2	min;
	t_vec2	max;

	min = min_pos(pos1, pos2);
	max = max_pos(pos1, pos2);
	while (min.y <= max.y)
	{
		draw_line(f, min, vec2(pos2.x, min.y), color);
		min.y++;
	}
}

void	draw_circle(t_frame f, t_vec2 pos, int radius, t_color color)
{
	t_vec2	px;
	float	hyp;

	px.x = 0;
	px.y = radius;
	while (px.x < px.y)
	{
		hyp = pow(px.x, 2) + pow(px.y - 0.5, 2);
		if (hyp > pow(radius, 2))
			px.y--;
		draw_pixel(f, vec2(pos.x + px.x, pos.y + px.y), color);
		draw_pixel(f, vec2(pos.x - px.x, pos.y + px.y), color);
		draw_pixel(f, vec2(pos.x + px.x, pos.y - px.y), color);
		draw_pixel(f, vec2(pos.x - px.x, pos.y - px.y), color);
		draw_pixel(f, vec2(pos.x + px.y, pos.y + px.x), color);
		draw_pixel(f, vec2(pos.x + px.y, pos.y - px.x), color);
		draw_pixel(f, vec2(pos.x - px.y, pos.y + px.x), color);
		draw_pixel(f, vec2(pos.x - px.y, pos.y - px.x), color);
		px.x++;
	}
}
