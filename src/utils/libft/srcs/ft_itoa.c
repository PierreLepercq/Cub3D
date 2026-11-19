/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:47:46 by llepesqu          #+#    #+#             */
/*   Updated: 2025/12/03 16:32:26 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static long	ft_abs(int n)
{
	if (n < 0)
		return (-(long)n);
	return ((long)n);
}

static size_t	ft_numlen(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_createstr(size_t len)
{
	char	*str;

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	len;
	char	*str;

	nb = ft_abs(n);
	len = ft_numlen(n);
	str = ft_createstr(len);
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (nb)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

// char	*ft_itoa(int n)
// {
//     long nb;
//     size_t len;
//     char *str;
//     char *buffer;
//     int i;
//     int j;

//     len = 1;
//     i = 0;
//     j = 0;
//     if (n < 0)
//     {
//         nb = -n;
//         len++;
//     }
//     else
//         nb = n;
//     while (nb >= 10)
//     {
//         nb /= 10;
//         len++;
//     }
//     str = malloc(len + 1);
//     if (str == NULL)
//         return (NULL);
//     buffer = malloc(len + 1);
//     if (buffer == NULL)
//         return (NULL);
//     nb = n;
//     if (n < 0)
//     {
//         str[j++] = '-';
//         nb = -n;
//     }
//     while (nb >= 10)
//     {
//         buffer[i++] = (nb % 10) + 48;
//         nb /= 10;
//     }
//     buffer[i] = nb + 48;
//     while (i >= 0)
//         str[j++] = buffer [i--];
//     str[j] = '\0';
//     free(buffer);
//     return (str);
// }

// #include <stdio.h>

// int	main(int argc, char const *argv[])
// {
// 	int	i;

// 	i = 1;
// 	while (i < argc)
// 		printf("%s\n", ft_itoa(atoi(argv[i++])));
// 	return (0);
// }
