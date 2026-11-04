/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 01:39:01 by pierre_lepe       #+#    #+#             */
/*   Updated: 2026/11/04 16:03:55 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

//	Digital Differential Analyzer
void	draw_line(t_frame f, t_vec2 pos1, t_vec2 pos2, t_color c)
{
	t_vec2	delta;
	t_vec2	inc;
	int		i;
	int		step;

	delta = vec2_sub(pos2, pos1);
	if (fabsf(delta.x) > fabsf(delta.y))
		step = fabsf(delta.x);
	else
		step = fabsf(delta.y);
	inc = vec2(delta.x / step, delta.y / step);
	i = 0;
	while (i < step)
	{
		delta = vec2(pos1.x + (i * inc.x), pos1.y + (i * inc.y));
		draw_pixel(f, delta, c);
		i++;
	}
	delta = vec2(pos1.x + (i * inc.x), pos1.y + (i * inc.y));
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
