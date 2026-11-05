/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 17:10:13 by llepesqu          #+#    #+#             */
/*   Updated: 2026/11/05 17:14:48 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

int	load_game_params(t_params *params, char *file_path);
int	free_game_params(t_params *params);

int	wrong_arg_count(void);

int	load_params_failed(char *game_file);

#endif