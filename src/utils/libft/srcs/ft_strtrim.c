/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:37:06 by llepesqu          #+#    #+#             */
/*   Updated: 2025/12/03 13:32:14 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static size_t	ft_find_start(char const *s1, char const *set)
{
	size_t	start;
	size_t	flag;
	size_t	j;

	start = 0;
	while (s1[start])
	{
		flag = 0;
		j = 0;
		while (set[j])
		{
			if (set[j] == s1[start])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (!flag)
			break ;
		start++;
	}
	return (start);
}

static size_t	ft_find_end(char const *s1, char const *set, const size_t start)
{
	size_t	end;
	size_t	flag;
	size_t	j;

	end = ft_strlen(s1) - 1;
	while (end > start)
	{
		flag = 0;
		j = 0;
		while (set[j])
		{
			if (set[j] == s1[end])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (!flag)
			break ;
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !*s1)
		return (ft_substr(s1, 0, 0));
	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set, start);
	if (start > end)
		return (ft_substr(s1, 0, 0));
	return (ft_substr(s1, start, end - start + 1));
}

// #include <stdio.h>

// int	main(int argc, char const *argv[])
// {
// 	(void)argc;
// 	printf("%s\n", ft_strtrim(argv[1], argv[2]));
// 	return (0);
// }
