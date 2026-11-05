/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:36:02 by llepesqu          #+#    #+#             */
/*   Updated: 2026/11/05 16:52:43 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// depuis la position du joueur
// → si la case est un mur ou déjà visitée, on stop
// → sinon on marque la case comme visitée
// → on appelle récursivement dans les 4 directions (haut, bas, gauche, droite)
// → à la fin on vérifie que toutes les cases accessibles ont été visitées

char	**copy_map(t_game *game)
{
	char	**cpy;
	int		i;

	i = 0;
	cpy = malloc(sizeof(char *) * (game->height + 1));
	if (!cpy)
		return (NULL);
	while (i < game->height)
	{
		cpy[i] = ft_strdup(game->map[i]);
		if (!cpy[i])
		{
			while (i > 0)
				free(cpy[--i]);
			free(cpy);
			return (NULL);
		}
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

void	flood_fill(char **map, t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->height || y >= game->width)
		return ;
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	flood_fill(map, game, x + 1, y);
	flood_fill(map, game, x, y + 1);
	flood_fill(map, game, x - 1, y);
	flood_fill(map, game, x, y - 1);
}

int	check_fill(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], 'E') || ft_strchr(map[i], 'C'))
			return (1);
		i++;
	}
	return (0);
}

void	check_solvable(t_game *game)
{
	char	**map_copy;
	int		unsolvable;

	map_copy = copy_map(game);
	ft_puterror_game(!map_copy, "Malloc failed", game);
	flood_fill(map_copy, game, game->player_x, game->player_y);
	unsolvable = check_fill(map_copy);
	ft_free_map(map_copy);
	ft_puterror_game(unsolvable, "Map unsolvable", game);
}
