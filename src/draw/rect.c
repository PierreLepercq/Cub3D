/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre_lepercq <pierre_lepercq@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 01:39:32 by pierre_lepe       #+#    #+#             */
/*   Updated: 2026/11/02 02:56:19 by pierre_lepe      ###   ########.fr       */
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
    int     y;

    y = 0;
	while (y <= size.y)
	{
		draw_line(
            f,
            vec2(pos.x, pos.y + y),
            vec2(pos.x + size.x, pos.y + y),
            c
        );
		y++;
	}
}
