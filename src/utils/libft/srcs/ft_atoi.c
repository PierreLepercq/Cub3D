/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:13:40 by llepesqu          #+#    #+#             */
/*   Updated: 2025/12/03 16:06:28 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_char_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	n;
	int	i;
	int	num;

	i = 0;
	num = 0;
	n = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			n = n * (-1);
		i++;
	}
	while (ft_char_is_numeric(nptr[i]))
	{
		num = (num * 10) + (nptr[i] - 48);
		i++;
	}
	return (num * n);
}

// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>

// int	main(int argc, char **argv)
// {
// 	printf("%i\n", ft_atoi(argv[1]));
// 	printf("%i\n", atoi(argv[1]));
// }