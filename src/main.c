/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:16:00 by plepercq          #+#    #+#             */
/*   Updated: 2026/10/15 15:50:16 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	wrong_arg_count(int argc)
{
	ft_putstr_fd("Incorrect number of arguments (expected 2)\n", 2);
	ft_putstr_fd("Usage : ./cub3D scene_description_file\n", 2);
	return (1);
}

int	load_params_failed(char *game_file)
{
	ft_putstr_fd("Failed to load game parameters from file : ", 2);
	ft_putstr_fd(game_file, 2);
	ft_putstr_fd("\n", 2);
	return (2);
}

int	main(int argc, char **argv)
{
	t_params	params;
	int			rcode;

	if (argc != 2)
		return (wrong_arg_count(argc));
	if (!load_game_params(params, argv[1]))
		return (load_params_failed(argv[1]));
	rcode = cub3d(params);
	free_game_params(params);
	return (rcode);
}
