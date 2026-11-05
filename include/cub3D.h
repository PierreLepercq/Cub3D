/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:25:23 by plepercq          #+#    #+#             */
/*   Updated: 2026/11/05 20:34:26 by llepesqu         ###   ########.fr       */
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
# include <fcntl.h>
# include <string.h>
# include <errno.h>

# include <limits.h>
# include <math.h>

# include <mlx.h>

# include "utils.h"
# include "color.h"
# include "vector2.h"
# include "draw.h"
# include "time_utils.h"
# include "parsing.h"

# define SUCCESS			1
# define FAILURE			0

# define BASE_HEX			"0123456789ABCDEF"

# define KEY_LEFT			65361f, 
# define KEY_UP				65362
# define KEY_RIGHT			65363
# define KEY_DOWN			65364
# define K_ESC				65307

# define WIN_HEIGHT			800
# define WIN_WIDTH			1000
# define WIN_TITLE			"Cub3D"

# define VELOCITY			2.0
f, 
# define ON_KEYDOWN			2
# define ON_KEYUP			3

# define FILENAME_EXTENSION ".cub"
# define CHARS				"01NSWE"
# define MAP				"1111111111\n\
							 1000000001\n\
							 1000000001\n\
							 1000000001\n\
							 1000000001\n\
							 1000000001\n\
							 1111111111"

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
	char		*path;
	void		*img;
	int			height;
	int			width;
}				t_texture;

typedef struct s_player
{
	t_vec2	pos;
	int		angle;
}				t_player;

typedef struct s_inputs
{
	bool		left;
	bool		right;
	bool		forward;
	bool		backward;
	bool		action;
}				t_inputs;


typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	int			win;
	char		**map;
	char		*floor;
	char		*ceiling;
	char		*wall_n;
	char		*wall_s;
	char		*wall_w;
	char		*wall_e;
	char		**textures;
	t_player	player;
	t_frame		frame;
	t_inputs	inputs;
}	t_game;



#endif