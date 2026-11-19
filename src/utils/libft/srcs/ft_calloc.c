/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:28:28 by llepesqu          #+#    #+#             */
/*   Updated: 2025/12/04 16:00:38 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*ptr;

	total = nmemb * size;
	if (size != 0 && total / size != nmemb)
		return (NULL);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total);
	return (ptr);
}

char	*ft_strdup(char *src)
{
	size_t	size;
	char	*dest;
	int		i;

	size = ft_strlen(src);
	dest = malloc(size * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		len = 0;
	else if (len > slen - start)
		len = slen - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	if (len > 0)
		ft_memcpy(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
}

// #include <stdio.h>

// int	main(int argc, char const *argv[])
// {
// 	(void)argc;
// 	printf("Substring : %s\n", ft_substr(argv[1], atoi(argv[2]),
// 			atoi(argv[3])));
// 	return (0);
// }