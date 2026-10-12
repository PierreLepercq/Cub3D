/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:25:23 by plepercq          #+#    #+#             */
/*   Updated: 2026/10/12 19:50:59 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// Standard C Libraries
# include <unistd.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

// mlx cloned by Makefile from official 42 repo: https://github.com/42Paris/minilibx-linux
# include <mlx.h>

# include <limits.h>

# define WRONG_ARG_COUNT	"Incorrect number of arguments\n\
Usage : ./cub3D scene_description_file\n"

typedef struct s_game
{
	void	*mlx;
	void	*win;

	char	**map;
	char	last_tile;

	int		width;
	int		height;

	int		moves;
	int		collectibles;

	int		player_x;
	int		player_y;

	int		exit_x;
	int		exit_y;

	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;

}			t_game;

typedef struct s_params
{
	char	*map;
	char	*floor;
	char	*ceiling;
	char	*wall_n;
	char	*wall_s;
	char	*wall_w;
	char	*wall_e;

}	t_params;

typedef struct s_texture
{
	char	*file;
}	t_texture;

typedef struct s_game
{
	char	*map;
	char	*floor;
	char	*ceiling;
	char	*wall_n;
	char	*wall_s;
	char	*wall_w;
	char	*wall_e;
	char	**textures;
}	t_game;

#endif