/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:16:00 by plepercq          #+#    #+#             */
/*   Updated: 2026/10/08 18:13:29 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"



void	params_init(t_params *params)
{
	params->map = NULL;
	params->floor = NULL;
	params->ceiling = NULL;
	params->wall_n = NULL;
	params->wall_s = NULL;
	params->wall_w = NULL;
	params->wall_e = NULL;
}

void	params_get(t_params *params, char *file)
{
	map_set(file, params);
	walls_set(file, params);
}

int	main(int argc, char **argv)
{
	t_params	params;

	if (argc != 2)
		return (ft_putstr_fd(WRONG_ARG_COUNT, 2), 0);
	if (!is_file_correct(argv[1]))
		return (0);
	params_init(&params);
	cub3d(params);
}
