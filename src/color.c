/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 16:10:57 by plepercq          #+#    #+#             */
/*   Updated: 2026/10/23 18:18:48 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_color	argb(char a, char r, char g, char b)
{
	t_color	color;

	color.a = a;
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

char	*color_hex(t_color color)
{
	__uint32_t	hex;

	hex = color.a << 24;
	hex = color.r << 16;
	hex = color.g << 8;
	hex = color.b;
	return (hex);
}
