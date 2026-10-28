/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre_lepercq <pierre_lepercq@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 00:10:45 by pierre_lepe       #+#    #+#             */
/*   Updated: 2026/10/24 00:14:54 by pierre_lepe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

# include <math.h>

typedef struct s_vec2
{
	int	x;
	int	y;
}	t_vec2;

t_vec2	vec2(int x, int y);
float	vec2_len(t_vec2 v);
t_vec2	vec2_add(t_vec2 v1, t_vec2 v2);
t_vec2	vec2_sub(t_vec2 v1, t_vec2 v2);
void	print_vec2(t_vec2 v);

#endif