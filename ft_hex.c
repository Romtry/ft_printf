/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:44:31 by rothiery          #+#    #+#             */
/*   Updated: 2024/05/16 11:15:13 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexmaj(size_t i)
{
	char	*base;
	size_t	cnt;

	cnt = 0;
	base = "0123456789ABCDEF";
	if (i >= 16)
		cnt += ft_puthexmaj(i / 16);
	write(1, &base[i % 16], 1);
	cnt++;
	return (cnt);
}

int	ft_puthex(size_t i)
{
	char	*base;
	size_t	cnt;

	cnt = 0;
	base = "0123456789abcdef";
	if (i >= 16)
		cnt += ft_puthex(i / 16);
	write(1, &base[i % 16], 1);
	cnt++;
	return (cnt);
}

/*#include <stdio.h>

int	main(void)
{
	printf("\nreturn : %d\n", ft_puthex(3735929054));
}*/
