/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:42:37 by rothiery          #+#    #+#             */
/*   Updated: 2024/12/09 15:28:33 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putlong(long n, t_buffer *buffer)
{
	int		i;
	long	l;

	i = 0;
	l = 1;
	if (n < 0)
	{
		n = n * -1;
		ft_putchr('-', buffer);
		i++;
	}
	if (n >= 10)
	{
		i += ft_putlong(n / 10, buffer);
		ft_putchr('0' + n % 10, buffer);
	}
	else
		ft_putchr(n + '0', buffer);
	return (l + 1);
}

unsigned int	ft_putptr(size_t *c, t_buffer *buffer)
{
	unsigned int	i;
	char			*nil;

	i = 0;
	nil = "(nil)";
	if (!c)
	{
		while (nil[i])
		{
			buffer_hit(buffer);
			buffer->save[buffer->index] = nil[i];
			buffer->index++;
			i++;
		}
		return (5);
	}
	else
	{
		buffer_hit(buffer);
		buffer->save[buffer->index] = '0';
		buffer_hit(buffer);
		buffer->save[++buffer->index] = 'x';
		buffer->index++;
	}
	return (ft_puthex((size_t)c, buffer) + 2);
}

unsigned int	ft_putnbr(int n, t_buffer *buffer)
{
	unsigned int	l;

	l = 0;
	if (n == 1 << 31)
	{
		ft_putstr((unsigned char *)"-2147483648", buffer);
		return (11);
	}
	if (n < 0)
	{
		n = n * -1;
		ft_putchr('-', buffer);
		l++;
	}
	if (n >= 10)
	{
		l += ft_putnbr(n / 10, buffer);
		ft_putchr('0' + n % 10, buffer);
	}
	else
		ft_putchr(n + '0', buffer);
	return (l + 1);
}

unsigned int	ft_putunl(unsigned long n, t_buffer *buffer)
{
	unsigned long	cnt;

	cnt = 0;
	if (n >= 10)
		cnt += ft_putunl(n / 10, buffer);
	ft_putchr('0' + n % 10, buffer);
	return (cnt + 1);
}

unsigned int	ft_putuni(unsigned int i, t_buffer *buffer)
{
	unsigned int	cnt;

	cnt = 0;
	if (i >= 10)
		cnt += ft_putuni(i / 10, buffer);
	ft_putchr('0' + i % 10, buffer);
	return (cnt + 1);
}
