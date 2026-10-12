/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord2D.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 19:53:03 by plepercq          #+#    #+#             */
/*   Updated: 2026/10/12 19:55:45 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORD2D_H
# define COORD2D_H

typedef struct s_coord2d
{
	float	x;
	float	y;
}				t_coord2d;

t_coord2d	coord2d(float x, float y);

#endif