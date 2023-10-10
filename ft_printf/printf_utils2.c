/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binanc <binanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:36:55 by binanc            #+#    #+#             */
/*   Updated: 2023/07/15 20:09:05 by binanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *ptr)
{
	unsigned long	ret;
	int				len;

	ret = (unsigned long)ptr;
	len = 0;
	if (ret > 15)
		len += ft_putpointer((void *)(ret / 16));
	len += ft_putchar("0123456789abcdef"[ret % 16]);
	return (len);
}

int	hex_len(unsigned int number)
{
	int	i;

	i = 0;
	if (number == 0)
		return (1);
	while (number)
	{
		number /= 16;
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned int number, const char format)
{
	int	len;

	len = hex_len(number);
	if (number >= 16)
	{
		ft_puthex(number / 16, format);
		ft_puthex(number % 16, format);
	}
	else
	{
		if (format == 'x')
			ft_putchar("0123456789abcdef"[number % 16]);
		else if (format == 'X')
			ft_putchar("0123456789ABCDEF"[number % 16]);
	}
	return (len);
}
