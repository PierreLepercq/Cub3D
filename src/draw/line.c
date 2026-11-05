/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 01:39:01 by pierre_lepe       #+#    #+#             */
/*   Updated: 2026/11/05 16:46:12 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

//	Digital Differential Analyzer
void	draw_line(t_frame f, t_vec2 px1, t_vec2 px2, t_color c)
{
	t_vec2	delta;
	t_vec2	inc;
	float	len_max;
	float	step;
	float	i;

	delta = vec2_sub(px2, px1);
	len_max = fabsf(delta.x);
	step = delta.x / len_max;
	if (fabsf(delta.y) > len_max)
	{
		len_max = fabsf(delta.y);
		step = delta.y / len_max;
	}
	inc = vec2(delta.x / len_max, delta.y / len_max);
	i = 0;
	while (i < len_max)
	{
		delta = vec2_add(px1, vec2_mult(inc, i));
		draw_pixel(f, delta, c);
		i += step;
	}
	delta = vec2_add(px1, vec2_mult(inc, i));
	draw_pixel(f, delta, c);
}

//void	draw_line_aa(t_frame f, t_vec2 pos1, t_vec2 pos2, t_color c)
//{
//	t_vec2	delta;
//	int		i;
//	int		step;
//	float	inc_x;
//	float	inc_y;
//
//	delta = vec2(pos2.x - pos1.x, pos2.y - pos1.y);
//	if (abs(delta.x) > abs(delta.y))
//		step = abs(delta.x);
//	else
//		step = abs(delta.y);
//	inc_x = (float)delta.x / step;
//	inc_y = (float)delta.y / step;
//	i = 0;
//	while (i < step)
//	{
//		delta = vec2(pos1.x + (i * inc_x), pos1.y + (i * inc_y));
//		draw_pixel(f, delta, c);
//		i++;
//	}
//	delta = vec2(pos1.x + (i * inc_x), pos1.y + (i * inc_y));
//	draw_pixel(f, delta, c);
//}
