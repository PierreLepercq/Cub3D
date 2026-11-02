/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre_lepercq <pierre_lepercq@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 00:44:33 by pierre_lepe       #+#    #+#             */
/*   Updated: 2026/11/02 03:08:56 by pierre_lepe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <math.h>
# include <stdlib.h>

# include "vector2.h"
# include "color.h"

typedef struct s_frame
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_vec2	size;
}			t_frame;

void	draw_pixel(t_frame f, t_vec2 pos, t_color c);

void    draw_line(t_frame f, t_vec2 pos1, t_vec2 pos2, t_color c);
//void    draw_line_aa(t_frame f, t_vec2 pos1, t_vec2 pos2, t_color c);

void	draw_rect(t_frame f, t_vec2 pos, t_vec2 size, t_color c);
void	draw_fillrect(t_frame f, t_vec2 pos, t_vec2 size, t_color c);

void	draw_circle(t_frame f, t_vec2 pos, int r, t_color c);
void	draw_fillcircle(t_frame f, t_vec2 pos, int r, t_color c);

void	draw_circle_aa(t_frame f, t_vec2 pos, int r, int thickness, t_color c);
void	draw_fillcircle_aa(t_frame f, t_vec2 pos, int r, t_color c);

#endif