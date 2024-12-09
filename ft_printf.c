/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:46:50 by rothiery          #+#    #+#             */
/*   Updated: 2024/12/09 15:52:58 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	cmd(const char *str, va_list args, t_buffer *buffer)
{
	if (str[1] == 'c')
		return (ft_putchr(va_arg(args, unsigned int), buffer));
	else if (str[1] == 's')
		return (ft_putstr(va_arg(args, unsigned char *), buffer));
	else if (str[1] == 'p')
		return (ft_putptr(va_arg(args, size_t *), buffer));
	else if (str[1] == 'd' || str[1] == 'i')
		return (ft_putnbr(va_arg(args, int), buffer));
	else if (str[1] == 'u')
		return (ft_putuni(va_arg(args, unsigned int), buffer));
	else if (str[1] == 'x')
		return (ft_puthex(va_arg(args, unsigned int), buffer));
	else if (str[1] == 'X')
		return (ft_puthexmaj(va_arg(args, unsigned int), buffer));
	else if (str[1] == 'l' && str[2] && str[2] == 'd')
		return (ft_putlong(va_arg(args, long), buffer));
	else if (str[1] == 'l' && str[2] && str[2] == 'u')
		return (ft_putunl(va_arg(args, unsigned long), buffer));
	else if (str[1] == '%')
		return (ft_putchr('%', buffer));
	return (0);
}

// int	ft_printf(const char *str, ...)
// {
// 	va_list			args;
// 	unsigned int	i;
// 	unsigned int	l;
// 	unsigned char	buffer[BUFFER_SIZE];

// 	i = 0;
// 	l = 0;
// 	va_start(args, str);
// 	while (str[i])
// 	{
// 		if (str[i] == '%')
// 		{
// 			l += cmd(str + i, args);
// 			if (str[i + 1])
// 				i++;
// 			if (str[i + 1] && ((str[i] == 'l' && str[i + 1] == 'u')
// 				|| (str[i == 'l'] && str[i + 1] == 'd')))
// 				i++;
// 		}
// 		else
// 			l += ft_putchr(str[i]);
// 		i++;
// 	}
// 	va_end(args);
// 	return (l);
// }

unsigned int	skip(const char *str)
{
	unsigned int	i;

	i = 0;
	if (str[i + 1])
		i++;
	if (str[i + 1] && ((str[i] == 'l' && str[i + 1] == 'u')
			|| (str[i == 'l'] && str[i + 1] == 'd')))
		i++;
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	t_buffer		buffer;
	unsigned int	ret;
	unsigned int	i;

	i = 0;
	buffer.index = 0;
	ret = 0;
	va_start(args, str);
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret += cmd(str + i, args, &buffer);
			i += skip(str + i);
		}
		else
			ret += ft_putchr(str[i], &buffer);
		i++;
	}
	write(1, buffer.save, buffer.index);
	return (ret);
}

// int	main(void)
// {
// 	long	n = 9223372036854775808;
// 	// char	*ptr;
// 	// char	**test;

// 	//int i = 10;
// 	//int *ptr = &i;
// 	//str = malloc(1);
// 	// printf("%%%v");
// 	ft_printf("%lu", n);
// 	//printf("%p", "test");
// 	//free(str);
// 	return (0);
// }
