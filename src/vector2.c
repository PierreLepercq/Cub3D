/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 00:09:36 by pierre_lepe       #+#    #+#             */
/*   Updated: 2026/11/23 18:14:44 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.h"
#include "stdio.h"

t_vec2	vec2(float x, float y)
{
	t_vec2	vec2;

	vec2.x = x;
	vec2.y = y;
	return (vec2);
}

float	vec2_norm(t_vec2 v)
{
	return (sqrtf(pow(v.x, 2) + pow(v.y, 2)));
}

t_vec2	vec2_add(t_vec2 v1, t_vec2 v2)
{
	return (vec2(v1.x + v2.x, v1.y + v2.y));
}

t_vec2	vec2_sub(t_vec2 v1, t_vec2 v2)
{
	return (vec2(v1.x - v2.x, v1.y - v2.y));
}

t_vec2	vec2_mult(t_vec2 v, float m)
{
	return (vec2(v.x * m, v.y * m));
}

t_vec2	vec2_unit(t_vec2 v)
{
	float	norm;

	norm = vec2_norm(v);
	return (vec2(v.x / norm, v.y / norm));
}

t_vec2	vec2_rotate(t_vec2 v, float rad)
{
	t_vec2	vr;

	vr.x = v.x * cos(rad) - v.y * sin(rad);
	vr.y = v.x * sin(rad) + v.y * cos(rad);
	return (vr);
}

t_vec2	vec2_perpendicular(t_vec2 v)
{
	return (vec2(v.y, -v.x));
}

void	pvec2(t_vec2 v)
{
	printf("vec2(%f, %f)\n", v.x, v.y);
}
