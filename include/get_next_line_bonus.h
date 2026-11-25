/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 10:38:49 by llepesqu          #+#    #+#             */
/*   Updated: 2026/11/25 16:05:46 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

char	*get_next_line(int fd);
// size_t	ft_strlen(const char *str);
// char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strndup(char *src, unsigned int n);
int		ft_index_of_char(char *base, char c);
void	update_stash(char **stash, char *buf, int size);

#endif
