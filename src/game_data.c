/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre_lepercq <pierre_lepercq@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:26:15 by plepercq          #+#    #+#             */
/*   Updated: 2026/10/19 00:40:52 by pierre_lepe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	game_data_init(t_game *g)
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

void	game_data_free(t_game *g)
{
	return ;
}
