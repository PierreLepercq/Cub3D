/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 10:39:09 by llepesqu          #+#    #+#             */
/*   Updated: 2026/11/25 16:07:33 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// il manquait bonus ici

// unsigned int	ft_strlcpy(char *dest, char const *src, unsigned int size)
// {
// 	unsigned int	l;
// 	unsigned int	i;

// 	i = 0;
// 	l = 0;
// 	while (src[l])
// 		l++;
// 	if (!size)
// 		return (l);
// 	while (*src && i < size - 1)
// 		dest[i++] = *src++;
// 	dest[i] = '\0';
// 	return (l);
// }

// unsigned int	ft_strlcat(char *dest, char const *src, unsigned int size)
// {
// 	unsigned int	i;
// 	unsigned int	min;
// 	unsigned int	src_l;
// 	unsigned int	dest_l;

// 	src_l = ft_strlen(src);
// 	if (!size)
// 		return (src_l);
// 	dest_l = ft_strlen(dest);
// 	i = dest_l;
// 	while (*src && i < size - 1)
// 		dest[i++] = *src++;
// 	dest[i] = '\0';
// 	if (size < dest_l)
// 		min = size;
// 	else
// 		min = dest_l;
// 	return (src_l + min);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	s1len;
// 	size_t	s2len;
// 	char	*str;

// 	s1len = ft_strlen(s1);
// 	s2len = ft_strlen(s2);
// 	str = malloc(s1len + s2len + 1);
// 	if (!str)
// 		return (NULL);
// 	ft_strlcpy(str, s1, s1len + 1);
// 	ft_strlcat(str, s2, s1len + s2len + 1);
// 	return (str);
// }

char	*ft_strndup(char *src, unsigned int n)
{
	int				size;
	char			*dest;
	unsigned int	i;

	if (!src || n == 0)
		return (NULL);
	if (ft_strlen(src) < n)
		size = ft_strlen(src);
	else
		size = n;
	dest = malloc(size + 1 * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_index_of_char(char *base, char c)
{
	int	i;

	i = 0;
	if (!base)
		return (-1);
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
