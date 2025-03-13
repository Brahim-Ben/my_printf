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

static int	ft_hexodecimal_lower(unsigned long n)
{
	int	counter;
	char	s[16] = "0123456789abcdef";

	counter = 0;
	if (n < 16)
		counter += ft_putstr(s[n]);
	else if (n >= 16)
	{
		counter += ft_hexodecimal_lower(n / 16);
		counter += ft_hexodecimal_lower(n % 16);
	}
	return (counter);
}

static int	ft_hexodecimal_upper(unsigned long n)
{
	int	counter;
	char	s[16] = "0123456789ABCDEF";

	counter = 0;
	if (n < 16)
		counter += ft_putstr(s[n]);
	else if (n >= 16)
	{
		counter += ft_hexodecimal_upper(n / 16);
		counter += ft_hexodecimal_upper(n % 16);
	}
	return (counter);
}

int	ft_hexodecimal(unsigned long n, char c)
{
	int	counter;

	counter = 0;
	if (c == 'X')
		counter += ft_hexodecimal_upper(n);
	else if (c == 'x')
		counter += ft_hexodecimal_lower(n);
	return (counter);
}
