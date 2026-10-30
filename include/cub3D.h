/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:25:23 by plepercq          #+#    #+#             */
/*   Updated: 2026/10/29 18:36:00 by plepercq         ###   ########.fr       */
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

# include <limits.h>
# include <math.h>

# include <mlx.h>

# include "color.h"
# include "vector2.h"
# include "draw.h"

# define SUCCESS			1
# define FAILURE			0

# define BASE_HEX			"0123456789ABCDEF"

# define KEY_LEFT			65361
# define KEY_UP				65362
# define KEY_RIGHT			65363
# define KEY_DOWN			65364
# define K_ESC				65307

# define WIN_HEIGHT			600
# define WIN_WIDTH			800
# define WIN_TITLE			"Cub3D"

# define VELOCITY			2.0

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

typedef struct s_vec2f
{
	float	x;
	float	y;
}	t_vec2f;

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
}				t_player;

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
}	t_game;

//	UTILS
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(int fd, const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
int		ft_error(char *str);

//	PARAMS PARSER
int	load_game_params(t_params *params, char *file_path);
int	free_game_params(t_params *params);

#endif