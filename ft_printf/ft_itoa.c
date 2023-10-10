/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binanc   <binanc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:36:55 by binanc            #+#    #+#             */
/*   Updated: 2022/11/29 20:58:39 by binanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	intlen(int c)
{
	int	i;

	i = 0;
	if (c <= 0)
		i = 1;
	while (c)
	{
		i++;
		c = c / 10;
	}
	return (i);
}

char	*numbermaker(int n, int strlen, int x, char *str)
{
	while (strlen >= 0)
	{
		x = n % 10;
		str[strlen--] = x + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		strlen;
	char	*str;
	int		x;
	int		sign;

	strlen = intlen(n);
	x = 0;
	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * strlen + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	str[strlen--] = '\0';
	numbermaker(n, strlen, x, str);
	if (sign == -1 && str[0] == '0')
		str[0] = '-';
	return (str);
}
