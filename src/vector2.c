/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre_lepercq <pierre_lepercq@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 00:09:36 by pierre_lepe       #+#    #+#             */
/*   Updated: 2026/10/24 00:17:26 by pierre_lepe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.h"
#include "stdio.h"

t_vec2	vec2(int x, int y)
{
	t_vec2	vec2;

	vec2.x = x;
	vec2.y = y;
	return (vec2);
}

float	vec2_len(t_vec2 v)
{
	return(sqrtf(pow(v.x, 2) + pow(v.y, 2)));
}

t_vec2	vec2_add(t_vec2 v1, t_vec2 v2)
{
	return(vec2(v1.x + v2.x, v1.y + v2.y));
}

t_vec2	vec2_sub(t_vec2 v1, t_vec2 v2)
{
	return(vec2(v1.x - v2.x, v1.y - v2.y));
}

void	print_vec2(t_vec2 v)
{
	printf("vec2(%i, %i)\n", v.x, v.y);
}
