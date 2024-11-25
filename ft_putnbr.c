/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:40:04 by bbenaali          #+#    #+#             */
/*   Updated: 2024/11/22 09:25:05 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_num_i(int n)
{
	int	countr;

	countr = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		countr++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		countr++;
	}
	return (countr);
}

int	ft_putnbr(int n)
{
	int	counter;

	counter = 0;
	if (n != -2147483648)
		counter = ft_count_num_i(n);
	if (n == -2147483648)
	{
		counter += ft_putstr("-2147483648");
	}
	else if (n < 0)
	{
		ft_putchar ('-');
		n = -n;
		ft_putnbr (n);
	}
	else if (n >= 10)
	{
		ft_putnbr (n / 10);
		ft_putnbr (n % 10);
	}
	else
		ft_putchar (n + '0');
	return (counter);
}
