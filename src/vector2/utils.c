/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre_lepercq <pierre_lepercq@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 11:49:17 by pierre_lepe       #+#    #+#             */
/*   Updated: 2026/10/24 11:52:15 by pierre_lepe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_vec2	min_pos(t_vec2 pos1, t_vec2 pos2)
{
	t_vec2	min;

	min = vec2(pos2.x, pos2.y);
	if (pos1.x < pos2.x)
		min.x = pos1.x;
	if (pos1.y < pos2.y)
		min.y = pos1.y;
	return(min);
}

t_vec2	max_pos(t_vec2 pos1, t_vec2 pos2)
{
	t_vec2	max;

	max = vec2(pos2.x, pos2.y);
	if (pos1.x > pos2.x)
		max.x = pos1.x;
	if (pos1.y > pos2.y)
		max.y = pos1.y;
	return(max);
}
