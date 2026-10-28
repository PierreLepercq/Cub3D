/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillbasics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre_lepercq <pierre_lepercq@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 11:53:16 by pierre_lepe       #+#    #+#             */
/*   Updated: 2026/10/24 13:47:02 by pierre_lepe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <stdio.h>

void	draw_fillrect(t_frame f, t_vec2 pos, t_vec2 size, t_color color)
{
    int     y;

    y = 0;
	while (y <= size.y)
	{
		draw_line(
            f,
            vec2(pos.x, pos.y + y),
            vec2(pos.x + size.x, pos.y + y),
            color
        );
		y++;
	}
}

void	draw_fillcircle(t_frame f, t_vec2 pos, int radius, t_color color)
{
	t_vec2	px;
    float   dist;
    float   alpha;

	px = vec2(pos.x - radius - 1, pos.y - radius - 1);
	while (px.x <= pos.x + radius + 1)
    {
        while(px.y <= pos.y + radius + 1)
        {
            dist = vec2_len(vec2_sub(px, pos));
            alpha = (radius + 0.5 - dist);
            if (alpha > 1.0f)
                alpha = 1.0f;
            if (alpha > 0.0f)
            {
                alpha *= (255 - (float)color.a) / 255;
                alpha = (1 - alpha) * 255;
                draw_pixel(f, px, argb(alpha, color.r, color.g, color.b));
            }
            px.y++;
        }
        px.y = 0;
        px.x++;
    }
}
