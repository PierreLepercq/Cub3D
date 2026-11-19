/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:25:20 by llepesqu          #+#    #+#             */
/*   Updated: 2026/11/19 19:02:52 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] != c && !flag)
		{
			flag = 1;
			count += 1;
		}
		else if (str[i] == c && flag)
			flag = 0;
		i++;
	}
	return (count);
}

static char	*ft_strndup(char const *src, unsigned int n)
{
	size_t	size;
	char	*dest;
	int		i;

	if (ft_strlen(src) < n)
		size = ft_strlen(src);
	else
		size = n;
	dest = malloc((size + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] && i < (int)n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**ft_freearray(char **array, int len)
{
	while (len > 0)
		free(array[--len]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	char	**array;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = ft_count_words(str, c);
	array = malloc((k + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (j < k)
	{
		i = 0;
		while (*str == c)
			str++;
		while (str[i] != c && str[i])
			i++;
		array[j++] = ft_strndup(str, i);
		if (array[j - 1] == NULL)
			return (ft_freearray(array, j));
		str = str + i;
	}
	array[k] = NULL;
	return (array);
}

// static int	ft_char_in_charset(char c, char *charset)
// {
// 	int	i;

// 	i = 0;
// 	while (charset[i])
// 	{
// 		if (charset[i] == c)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// static int	ft_count_words(char const *str, char *charset)
// {
// 	int	i;
// 	int	count;
// 	int	flag;

// 	i = 0;
// 	count = 0;
// 	flag = 0;
// 	while (str[i])
// 	{
// 		if (!ft_char_in_charset(str[i], charset) && !flag)
// 		{
// 			flag = 1;
// 			count += 1;
// 		}
// 		else if (ft_char_in_charset(str[i], charset) && flag)
// 			flag = 0;
// 		i++;
// 	}
// 	return (count);
// }

// static char	*ft_strndup(char const *src, unsigned int n)
// {
// 	size_t	size;
// 	char	*dest;
// 	int		i;

// 	if (ft_strlen(src) < n)
// 		size = ft_strlen(src);
// 	else
// 		size = n;
// 	dest = malloc((size + 1) * sizeof(char));
// 	if (dest == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (src[i] && i < (int)n)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

// char	**ft_split(char const *str, char *charset)
// {
// 	int		i;
// 	char	**array;
// 	int		j;
// 	int		k;

// 	(1 && (i = 0), (j = 0), (k = ft_count_words(str, charset)));
// 	array = malloc((k + 1) * sizeof(char *));
// 	if (array == NULL)
// 		return (NULL);
// 	array[0] = ft_strndup(str, ft_strlen(str));
// 	array[k] = NULL;
// 	if (charset == NULL || !ft_strlen(charset))
// 		return (array);
// 	while (j < k)
// 	{
// 		i = 0;
// 		while (ft_char_in_charset(*str, charset))
// 			str++;
// 		while (!ft_char_in_charset(str[i], charset))
// 			i++;
// 		array[j++] = ft_strndup(str, i);
// 		str = str + i;
// 	}
// 	return (array);
// }

// #include <stdio.h>

// int	main(int ac, char **av)
// {
// 	int i;
// 	char **array;

// 	(void)ac;
// 	array = ft_split(av[1], av[2][0]);
// 	i = 0;
// 	while (array[i])
// 	{
// 		printf("%s\n", array[i]);
// 		free(array[i]);
// 		i++;
// 	}
// 	free(array);
// }