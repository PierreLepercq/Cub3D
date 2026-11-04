/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 01:38:27 by pierre_lepe       #+#    #+#             */
/*   Updated: 2026/11/04 15:49:48 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_pixel(t_frame f, t_vec2 pos, t_color c)
{
	char	*dst;
	t_color	bg_color;

	if (pos.x < 0 || pos.x > f.size.x || pos.y < 0 || pos.y > f.size.y)
		return ;
	dst = f.addr;
	dst += (int)pos.y * f.line_length;
	dst += (int)pos.x * (f.bits_per_pixel / 8);
	bg_color = hex_to_color(*(uint32_t *)dst);
	*(uint32_t *)dst = color_to_hex(color_blend(bg_color, c));
}
