/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre_lepercq <pierre_lepercq@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 16:10:57 by plepercq          #+#    #+#             */
/*   Updated: 2026/10/23 23:52:12 by pierre_lepe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	argb(uint8_t a, uint8_t r, uint8_t g, uint8_t b)
{
	t_color	color;

	color.a = a;
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color	mix_color(t_color c1, t_color c2)
{
	t_color	mix;

	mix.a = c2.a + c1.a * (1 - c2.a);
	mix.r = (c2.r * c2.a) + (c1.r * c1.a) * (1 - c2.a);
	mix.g = (c2.g * c2.a) + (c1.g * c1.a) * (1 - c2.a);
	mix.b = (c2.b * c2.a) + (c1.b * c1.a) * (1 - c2.a);
	return (mix);
}

t_color	hex_to_color(uint32_t hex)
{
	t_color	color;
	
	color.a = hex >> 24;
	color.r = hex >> 16;
	color.g = hex >> 8;
	color.b = hex;
	return (color);
}

uint32_t	color_to_hex(t_color color)
{
	uint32_t	hex;

	hex = color.a << 24;
	hex |= color.r << 16;
	hex |= color.g << 8;
	hex |= color.b;
	return (hex);
}
