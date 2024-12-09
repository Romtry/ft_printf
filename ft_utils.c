/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:06:35 by rothiery          #+#    #+#             */
/*   Updated: 2024/12/09 15:25:21 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putstr(unsigned char *c, t_buffer *buffer)
{
	unsigned int	i;

	i = 0;
	if (!c)
		c = (unsigned char *)"(null)";
	while (c[i])
	{
		buffer_hit(buffer);
		buffer->save[buffer->index] = c[i];
		i++;
		buffer->index++;
	}
	return (i);
}

unsigned int	ft_putchr(unsigned int c, t_buffer *buffer)
{
	buffer_hit(buffer);
	buffer->save[buffer->index] = c;
	buffer->index++;
	return (1);
}

size_t	ft_strlen(const unsigned char *s)
{
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	buffer_hit(t_buffer *buffer)
{
	if (buffer->index == BUFFER_SIZE)
	{
		write(1, &buffer->save, BUFFER_SIZE);
		buffer->index = 0;
	}
}
