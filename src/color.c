/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre_lepercq <pierre_lepercq@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 16:10:57 by plepercq          #+#    #+#             */
/*   Updated: 2026/10/24 12:37:01 by pierre_lepe      ###   ########.fr       */
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

t_color	color_blend(t_color bg, t_color fg)
{
	t_color	mix;

	mix.a = 255;
	mix.r = (fg.r * (255 - fg.a) + bg.r * fg.a) / 255;
    mix.g = (fg.g * (255 - fg.a) + bg.g * fg.a) / 255;
    mix.b = (fg.b * (255 - fg.a) + bg.b * fg.a) / 255;
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
