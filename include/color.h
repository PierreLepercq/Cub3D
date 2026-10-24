/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre_lepercq <pierre_lepercq@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 22:29:32 by pierre_lepe       #+#    #+#             */
/*   Updated: 2026/10/24 12:13:43 by pierre_lepe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>

typedef struct s_color
{
	uint8_t	a;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_color;

t_color	    argb(uint8_t a, uint8_t r, uint8_t g, uint8_t b);
t_color		color_blend(t_color c1, t_color c2);
t_color    	hex_to_color(uint32_t hex);
uint32_t    color_to_hex(t_color color);

#endif