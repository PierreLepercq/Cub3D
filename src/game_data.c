/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:26:15 by plepercq          #+#    #+#             */
/*   Updated: 2026/10/15 15:47:41 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	game_init(t_game *g)
{
	g->map = NULL;
	g->textures = NULL;
	g->wall_n = NULL;
	g->wall_s = NULL;
	g->wall_w = NULL;
	g->wall_e = NULL;
	g->floor = NULL;
	g->ceiling = NULL;
}
