/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 00:10:45 by pierre_lepe       #+#    #+#             */
/*   Updated: 2026/11/23 18:24:15 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

# include <math.h>

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

t_vec2	vec2(float x, float y);
float	vec2_norm(t_vec2 v);
t_vec2	vec2_add(t_vec2 v1, t_vec2 v2);
t_vec2	vec2_sub(t_vec2 v1, t_vec2 v2);
t_vec2	vec2_mult(t_vec2 v, float m);
t_vec2	vec2_unit(t_vec2 v);
t_vec2	vec2_rotate(t_vec2 v, float rad);
t_vec2	vec2_perpendicular(t_vec2 v);
void	pvec2(t_vec2 v);

#endif