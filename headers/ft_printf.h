/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binanc <binanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:36:55 by binanc            #+#    #+#             */
/*   Updated: 2023/07/15 20:10:21 by binanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putpointer(void *ptr);
int		ft_putnbr(int number);
int		ft_putunint(unsigned int number);
int		ft_puthex(unsigned int number, const char format);
char	*ft_itoa(int number);

#endif
