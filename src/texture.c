/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:40:53 by plepercq          #+#    #+#             */
/*   Updated: 2026/11/19 18:14:25 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Texture related functions

#include "cub3D.h"

void	tx_init(t_texture *tx)
{
	tx->path = NULL;
	tx->img = NULL;
	tx->height = 0;
	tx->width = 0;
}

void	tx_load(void *mlx, t_texture *tx, char *tx_path)
{
	(void)mlx;
	(void)tx;
	(void)tx_path;
}
