/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre_lepercq <pierre_lepercq@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 23:54:39 by pierre_lepe       #+#    #+#             */
/*   Updated: 2026/10/24 13:57:21 by pierre_lepe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "stdio.h"

void	draw_pixel(t_frame f, t_vec2 pos, t_color color)
{
	char	*dst;
	t_color	bg_color;

	if (pos.x < 0 || pos.x > f.size.x || \
		pos.y < 0 || pos.y > f.size.y)
		return ;
	dst = f.addr;
	dst += pos.y * f.line_length;
	dst += pos.x * (f.bits_per_pixel / 8);
	bg_color = hex_to_color(*(uint32_t*)dst);
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

void	draw_rect(t_frame f, t_vec2 pos, t_vec2 size, t_color color)
{
	t_vec2	end;

	end = vec2(pos.x + size.x, pos.y + size.y);
	draw_line(f, pos, vec2(pos.x, end.y), color);
	draw_line(f, pos, vec2(end.x, pos.y), color);
	draw_line(f, end, vec2(pos.x, end.y), color);
	draw_line(f, end, vec2(end.x, pos.y), color);
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
