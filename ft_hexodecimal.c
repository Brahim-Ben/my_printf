/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexodecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:08:25 by bbenaali          #+#    #+#             */
/*   Updated: 2024/11/23 13:06:16 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexodecimal_lower(unsigned long n, int count)
{
	int	counter;

	counter = 0;
	counter = count;
	if (n == 10)
		counter += ft_putchar('a');
	else if (n == 11)
		counter += ft_putchar('b');
	else if (n == 12)
		counter += ft_putchar('c');
	else if (n == 13)
		counter += ft_putchar('d');
	else if (n == 14)
		counter += ft_putchar('e');
	else if (n == 15)
		counter += ft_putchar('f');
	else if (n >= 16)
	{
		counter = ft_hexodecimal_lower(n / 16, counter);
		counter = ft_hexodecimal_lower(n % 16, counter);
	}
	else
		counter += ft_putnbr(n);
	return (counter);
}

static int	ft_hexodecimal_upper(unsigned long n, int count)
{
	int	counter;

	counter = 0;
	counter = count;
	if (n == 10)
		counter += ft_putchar('A');
	else if (n == 11)
		counter += ft_putchar('B');
	else if (n == 12)
		counter += ft_putchar('C');
	else if (n == 13)
		counter += ft_putchar('D');
	else if (n == 14)
		counter += ft_putchar('E');
	else if (n == 15)
		counter += ft_putchar('F');
	else if (n >= 16)
	{
		counter = ft_hexodecimal_upper(n / 16, counter);
		counter = ft_hexodecimal_upper(n % 16, counter);
	}
	else
		counter += ft_putnbr(n);
	return (counter);
}

int	ft_hexodecimal(unsigned long n, char c)
{
	int	counter;

	counter = 0;
	if (c == 'X')
		counter += ft_hexodecimal_upper(n, 0);
	else if (c == 'x')
		counter += ft_hexodecimal_lower(n, 0);
	return (counter);
}
