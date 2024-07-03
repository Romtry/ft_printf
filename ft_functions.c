/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:42:37 by rothiery          #+#    #+#             */
/*   Updated: 2024/05/16 12:19:06 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>

int	ft_putchr(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *c)
{
	int	i;

	i = 0;
	if (!c)
		c = "(null)";
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	return (i);
}

int	ft_putptr(size_t *c)
{
	if (!c)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
		write(1, "0x", 2);
	return (ft_puthex((size_t)c) + 2);
}

int	ft_putnbr(int n)
{
	int	l;

	l = 0;
	if (n == 1 << 31)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		n = n * -1;
		ft_putchr('-');
		l++;
	}
	if (n >= 10)
	{
		l += ft_putnbr(n / 10);
		ft_putchr('0' + n % 10);
	}
	else
		ft_putchr(n + '0');
	return (l + 1);
}

int	ft_putuni(unsigned int i)
{
	int	cnt;

	cnt = 0;
	if (i >= 10)
		cnt += ft_putuni(i / 10);
	ft_putchr('0' + i % 10);
	return (cnt + 1);
}
