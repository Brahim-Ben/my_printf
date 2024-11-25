/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 07:50:21 by bbenaali          #+#    #+#             */
/*   Updated: 2024/11/21 14:44:29 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_num_u(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		counter++;
		n = -n;
	}
	else if (n > 0)
	{
		while (n)
		{
			n = n / 10;
			counter++;
		}
	}
	return (counter);
}

int	ft_unsigned(unsigned int n)
{
	int	counter;

	counter = 0;
	counter = ft_count_num_u(n);
	if (n >= 10)
	{
		ft_unsigned (n / 10);
		ft_unsigned (n % 10);
	}
	else
		ft_putchar (n + '0');
	return (counter);
}
