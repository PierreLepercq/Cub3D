/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:46:58 by llepesqu          #+#    #+#             */
/*   Updated: 2026/11/25 16:31:39 by llepesqu         ###   ########.fr       */
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

int parse_identifier(char *line, t_params *params)
{
	static const char *id[ID_COUNT] = {"NO ", "SO ", "WE ", "EA "};
	char *ptr;
	int j;

	ptr = ft_skip_spaces(line);
	j = 0;
	while (j < ID_COUNT)
	{	
		if (!ft_strncmp(ptr, id[j], 3))
		{
			ptr = ft_skip_spaces(ptr + 3); // skip "NO "
			if (!params->walls[j].path)
			{
				params->walls[j].path = ft_strdup(ptr);
				return (1);
			}
			else
			{
				ft_error((char *)id[j]);
				ft_putendl_fd("has already been assigned.", STDERR_FILENO);
				return (FAILURE);
			}
		}
		j++;
	}
	return (0);
}

// char **open_file(char *file, t_params *params)
// {
// 	char *line;
// 	int fd;
// 	int j;
	
// 	ft_bzero(params, sizeof(params));
// 	fd = open(file, O_RDONLY);
// 	ft_puterror(fd < 0, strerror(errno));
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break;
// 		free(line);
// 		//ft_puterror(true, "Wrong identifier parameters");
// 	}
// 	close(fd);
// }

// void parsing_wrapper(int nb, char *file)
// {
// 	int fd;
	
// 	fd = 0;
// 	ft_puterror(nb != 2, "Incorrect number of arguments (expected 2)\nUsage : ./cub3D scene_description_file.cub");
// 	ft_puterror(!check_extension(file), "Incorrect file\nUsage : ./cub3D scene_description_file.cub");
// 	fd = open_file(file);
// 	get_next_line(fd);	
// }

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