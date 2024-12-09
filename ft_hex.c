/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:44:31 by rothiery          #+#    #+#             */
/*   Updated: 2024/12/09 15:37:21 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_puthexmaj(size_t i, t_buffer *buffer)
{
	unsigned char	*base;
	size_t			cnt;

	cnt = 0;
	base = (unsigned char *)"0123456789ABCDEF";
	if (i >= 16)
		cnt += ft_puthexmaj(i / 16, buffer);
	buffer_hit(buffer);
	buffer->save[buffer->index] = base[i % 16];
	buffer->index++;
	cnt++;
	return (cnt);
}

unsigned int	ft_puthex(size_t i, t_buffer *buffer)
{
	unsigned char	*base;
	size_t			cnt;

	cnt = 0;
	base = (unsigned char *)"0123456789abcdef";
	if (i >= 16)
		cnt += ft_puthex(i / 16, buffer);
	buffer_hit(buffer);
	buffer->save[buffer->index] = base[i % 16];
	buffer->index++;
	cnt++;
	return (cnt);
}

/*#include <stdio.h>

int	main(void)
{
	printf("\nreturn : %d\n", ft_puthex(3735929054));
}*/
