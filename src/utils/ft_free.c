/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 18:13:31 by llepesqu          #+#    #+#             */
/*   Updated: 2026/11/26 20:22:19 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ft_free_texture(void *mlx, t_texture *texture)
{
    free(texture->path);
    if (texture->img)
        mlx_destroy_image(mlx, texture->img);
}

void ft_free_param(void *mlx, t_params *param)
{
    int i;

    ft_free_tab(param->map);
    i = 0;
    while (i < ID_COUNT)
        ft_free_texture(mlx, &param->walls[i++]);
}

void ft_free_game(t_game *game)
{
    ft_free_param(game->mlx, &game->params);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}