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