/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:46:58 by llepesqu          #+#    #+#             */
/*   Updated: 2026/11/05 20:37:10 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_extension(char *file)
{
	size_t len;
	size_t extension_len;

	extension_len = ft_strlen(FILENAME_EXTENSION);
	len = ft_strlen(file);
	if (len <= extension_len || 
		ft_strncmp(file + (len - extension_len), FILENAME_EXTENSION, extension_len))
		return (FAILURE);
	return (SUCCESS);
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	ft_puterror(fd < 0, strerror(errno));
	return (fd);
}

// ------------------------------------

// int	load_params_failed(char *game_file)
// {
// 	ft_error("Failed to load game parameters from file : ");
// 	ft_putstr_fd(2, game_file);
// 	ft_putstr_fd(2, "\n");
// 	return (2);
// }

// int	load_map(char *line)
// {
// 	(void)line;
// 	return (SUCCESS);
// }

// int	load_color(char *line)
// {
// 	(void)line;
// 	return (SUCCESS);
// }

// int	load_texture(char *line)
// {
// 	(void)line;
// 	return (SUCCESS);
// }


// void	count_lines(int fd, t_game *game)
// {
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		i++;
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	game->height = i;
// }

// void	read_map(int fd, t_game *game)
// {
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		game->map[i] = ft_strtrim(line, "\n");
// 		ft_puterror(!game->map[i], "Memory allocation failed");
// 		free(line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	game->map[i] = NULL;
// 	game->width = ft_strlen(game->map[0]);
// }

// ------------------------------------

void parsing_wrapper(int nb, char *file)
{
	int fd;
	
	ft_puterror(nb != 2, "Incorrect number of arguments (expected 2)\nUsage : ./cub3D scene_description_file.cub");
	ft_puterror(!check_extension(file), "Incorrect file\nUsage : ./cub3D scene_description_file.cub");
	fd = open_file(file); // ft_puterror dans open_file
	
}