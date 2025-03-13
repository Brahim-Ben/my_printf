/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:40:18 by bbenaali          #+#    #+#             */
/*   Updated: 2024/11/23 13:06:25 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_s(char c, va_list list)
{
	int	counter;

	counter = 0;
	if (c == 'd' || c == 'i')
		counter += ft_putnbr(va_arg(list, int));
	else if (c == 's')
		counter += ft_putstr(va_arg(list, char *));
	else if (c == 'c')
		counter += ft_putchar(va_arg(list, int));
	else if (c == 'x' || c == 'X')
		counter += ft_hexodecimal(va_arg(list, unsigned int), c);
	else if (c == 'u')
		counter += ft_unsigned(va_arg(list, unsigned int));
	else if (c == 'p')
	{
		counter += ft_putstr("0x");
		counter += ft_hexodecimal(va_arg(list, unsigned long), 'x');
	}
	else
		counter += write (1, &c, 1);
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		counter;

	if (write (1, 0, 0) == -1)
		return (-1);
	i = 0;
	counter = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			counter += ft_s(format[i], list);
		}
		else if (format[i] != '%')
		{
			counter += write (1, &format[i], 1);
		}
		i++;
	}
	va_end (list);
	return (counter);
}
