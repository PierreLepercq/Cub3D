/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:36:04 by llepesqu          #+#    #+#             */
/*   Updated: 2026/11/05 17:03:59 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// ◦ The map must be composed of only 6 possible characters: 0 for an empty space,
// 1 for a wall, and N,S,E or W for the player’s start position and spawning
// orientation.
// This is a simple valid map:
// 111111
// 100101
// 101001
// 1100N1
// 111111
// ◦ The map must be closed/surrounded by walls, if not the program must return
// an error.
// ◦ Except for the map content, each type of element can be separated by one or
// more empty lines.
// ◦ Except for the map content which always has to be the last, each type of
// element can be set in any order in the file.
// ◦ Except for the map, each type of information from an element can be separated
// by one or more spaces.
// ◦ The map must be parsed as it looks in the file. Spaces are a valid part of the
// map and are up to you to handle. You must be able to parse any kind of map,
// as long as it respects the rules of the map.


void	check_walls(t_game *game, int line)
{
	int	col;

	if (line == 0 || line == game->height - 1)
	{
		col = 0;
		while (col < game->width)
		{
			ft_puterror_game(game->map[line][col] != '1',
				"Map must be enclosed by walls (top/bottom)", game);
			col++;
		}
	}
	else
	{
		ft_puterror_game(game->map[line][0] != '1',
			"Map must be enclosed by walls (left)", game);
		ft_puterror_game(game->map[line][game->width - 1] != '1',
			"Map must be enclosed by walls (right)", game);
	}
}

void	check_char(t_game *game, int line, int col)
{
	ft_puterror_game(!ft_strchr(CHARS, game->map[line][col]),
		"Only \"01PEC\" accepted", game);
}

void	set_count(t_game *game, int line, int *nb_start, int *nb_exit)
{
	int	col;

	col = 0;
	while (col < game->width)
	{
		check_char(game, line, col);
		if (game->map[line][col] == 'P')
		{
			*nb_start += 1;
			game->player_x = line;
			game->player_y = col;
			ft_puterror_game(*nb_start > 1, "Too many starting positions",
				game);
		}
		if (game->map[line][col] == 'E')
		{
			*nb_exit += 1;
			game->exit_x = line;
			game->exit_y = col;
			ft_puterror_game(*nb_exit > 1, "Too many exits", game);
		}
		if (game->map[line][col] == 'C')
			game->collectibles++;
		col++;
	}
}

void	map_check(t_game *game)
{
	int	i;
	int	nb_exit;
	int	nb_start;

	i = 0;
	nb_exit = 0;
	nb_start = 0;
	while (i < game->height)
	{
		check_rectangular(game, i);
		check_walls(game, i);
		set_count(game, i, &nb_start, &nb_exit);
		i++;
	}
	ft_puterror_game(nb_start != 1,
		"Map must contain exactly 1 starting position", game);
	ft_puterror_game(nb_exit != 1, "Map must contain exactly 1 exit", game);
	ft_puterror_game(game->collectibles < 1,
		"Map must have at least 1 collectible", game);
	check_solvable(game);
}
