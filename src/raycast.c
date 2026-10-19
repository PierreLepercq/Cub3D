/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:15:31 by plepercq          #+#    #+#             */
/*   Updated: 2026/10/19 19:13:50 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_hitting_wall(t_game *g, t_vec2 hit)
{
	int		map_x;
	int		map_y;

	map_x = (int)fabsf(hit.x);
	map_y = (int)fabsf(hit.y);
	if (g->map[map_y][map_x] == 1)
		return (true);
	return (false);
}

t_vec2	get_next_hit()
{
	t_vec2	hit;

	

	return (hit);
}

t_vec2	DDA(t_game *g, t_vec2 pos, t_vec2 ray_dir)
{
	t_vec2	hit;
	float	slope;

	slope = ray_dir.y / ray_dir.x;
	while (!is_hitting_wall(g, pos))
	
	hit.x = pos.x

	return (hit);
}

t_vec2	raycast(t_vec2 pos, t_vec2 ray_dir)
{
	t_vec2	ray;
	

	dda()
	

	return (hit);
}

