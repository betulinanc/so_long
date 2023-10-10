/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binanc <binanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:36:55 by binanc            #+#    #+#             */
/*   Updated: 2023/07/15 20:08:52 by binanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write (1, "(null)", 6));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int number)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa(number);
	len += ft_putstr(str);
	free(str);
	return (len);
}

int	ft_unintlen(unsigned int number)
{
	int	i;

	i = 0;
	if (number == 0)
		return (1);
	while (number)
	{
		number /= 10;
		i++;
	}
	return (i);
}

int	ft_putunint(unsigned int number)
{
	int	i;

	i = ft_unintlen(number);
	if (number > 9)
	{
		ft_putunint(number / 10);
		ft_putunint(number % 10);
	}
	else
		ft_putchar(number + '0');
	return (i);
}
