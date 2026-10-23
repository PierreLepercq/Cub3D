/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:15:31 by plepercq          #+#    #+#             */
/*   Updated: 2026/10/23 15:32:34 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_hitting_wall(t_game *g, t_vec2f hit)
{
	int		map_x;
	int		map_y;

	map_x = (int)fabsf(hit.x);
	map_y = (int)fabsf(hit.y);
	if (g->map[map_y][map_x] == 1)
		return (true);
	return (false);
}

t_vec2f	get_next_hit_dx(t_vec2f pos, t_vec2f ray_dir)
{
	float	sign;
	float	delta;
	t_vec2f	hit;

	sign = ray_dir.x / fabsf(ray_dir.x);
	delta = sign - (pos.x - (int)pos.x);
	printf("SIGN : %f\n", sign);
	printf("DELTA : %f\n", delta);
	
	hit.x = 0.;
	hit.y = 0.;
	return (hit);
}




t_vec2f	DDA(t_game *g, t_vec2f pos, t_vec2f ray_dir)
{
	t_vec2f	hit;
	float	slope;
	t_vec2f	next_hit_dx;
	t_vec2f	next_hit_dy;

	hit = pos;
	slope = ray_dir.y / ray_dir.x;
	while (!is_hitting_wall(g, hit))
	
	hit.x = pos.x

	return (hit);
}

t_vec2f	raycast(t_vec2f pos, t_vec2f ray_dir)
{
	t_vec2f	ray;
	

	dda()
	

	return (hit);
}

