/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 17:10:13 by llepesqu          #+#    #+#             */
/*   Updated: 2026/11/25 16:01:30 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

#include "libft.h"
#include "get_next_line_bonus.h"

typedef struct s_params t_params;

int check_extension(char *file);
int	open_file(char *file, t_params *params);
int parse_identifier(char *line, t_params *params);
// void parsing_wrapper(int nb, char *file);

// int	load_game_params(t_params *params, char *file_path);
// int	free_game_params(t_params *params);

// int	wrong_arg_count(void);

// int	load_params_failed(char *game_file);

#endif