/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:16:00 by plepercq          #+#    #+#             */
/*   Updated: 2026/10/12 19:23:59 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
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
*/

int	main(int argc, char **argv)
{
	(void)argv;

	if (argc != 2)
	{
		ft_putstr_fd(WRONG_ARG_COUNT, 2);
		return (1);
	}
	return (0);
}
