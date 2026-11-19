/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:47:16 by llepesqu          #+#    #+#             */
/*   Updated: 2025/12/03 16:41:14 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

// On parcoure la str jusqu'a la fin avec un indice,
// on retourne cet indice.
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// On recupere la taille de src, si taille nulle retourne taille src.
// on copie les char de src dans dest, on ajoute le null byte
// on retourne la taille

// /**
//  * test
//  *
//  * @param dst test
//  */
size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	l;
	size_t	i;

	i = 0;
	l = 0;
	while (src[l])
		l++;
	if (!siz)
		return (l);
	while (*src && i < siz - 1)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (l);
}

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	min;
	size_t	src_l;
	size_t	dest_l;

	src_l = ft_strlen(src);
	if (!siz)
		return (src_l);
	dest_l = ft_strlen(dst);
	i = dest_l;
	while (*src && i < siz - 1)
		dst[i++] = *src++;
	dst[i] = '\0';
	if (siz < dest_l)
		min = siz;
	else
		min = dest_l;
	return (src_l + min);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0 && str[i] != (char)c)
	{
		i--;
	}
	if (i < 0)
		return (NULL);
	return ((char *)&s[i]);
}
