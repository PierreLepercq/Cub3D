/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:40:53 by plepercq          #+#    #+#             */
/*   Updated: 2026/10/15 15:16:23 by plepercq         ###   ########.fr       */
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

