/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 19:52:20 by llepesqu          #+#    #+#             */
/*   Updated: 2026/10/12 19:52:53 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	ft_puterror(!game, "Memory allocation failed : game");
	ft_bzero(game, sizeof(t_game));
	game->last_tile = '0';
	return (game);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	ft_puterror_game(!game->mlx, "X server connection failed", game);
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height
			* TILE_SIZE, "so_long");
	ft_puterror_game(!game->win, "Failed opening window", game);
}