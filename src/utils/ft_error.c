/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 20:33:50 by llepesqu          #+#    #+#             */
/*   Updated: 2026/11/05 20:28:59 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_error(char *str)
{
	ft_putstr_fd(STDERR_FILENO,"Error\n");
	ft_putstr_fd(STDERR_FILENO,str);
	return (FAILURE);
}

void	ft_puterror(int condition, char *msg)
{
	if (condition)
	{
		ft_putstr_fd(STDERR_FILENO, "Error\n");
		ft_putstr_fd(STDERR_FILENO, msg);
		ft_putstr_fd(STDERR_FILENO, "\n");
		exit(1);
	}
}