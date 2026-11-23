/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 01:39:32 by pierre_lepe       #+#    #+#             */
/*   Updated: 2026/11/23 18:44:33 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_rect(t_frame f, t_vec2 pos, t_vec2 size, t_color c)
{
	t_vec2	end;

	end = vec2(pos.x + size.x, pos.y + size.y);
	draw_line(f, pos, vec2(pos.x, end.y), c);
	draw_line(f, pos, vec2(end.x, pos.y), c);
	draw_line(f, end, vec2(pos.x, end.y), c);
	draw_line(f, end, vec2(end.x, pos.y), c);
}

void	draw_fillrect(t_frame f, t_vec2 pos, t_vec2 size, t_color c)
{
	t_vec2	px;

	px = vec2(0, 0);
	while (px.y <= size.y)
	{
		px.x = 0;
		while (px.x <= size.x)
		{
			draw_pixel(f, vec2_add(pos, px), c);
			px.x++;
		}
		px.y++;
	}
}
