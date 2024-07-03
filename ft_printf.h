/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:42:26 by rothiery          #+#    #+#             */
/*   Updated: 2024/05/16 12:31:00 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putchr(int c);
int		ft_putstr(char *c);
int		ft_putptr(size_t *c);
int		ft_putnbr(int n);
int		ft_putuni(unsigned int i);
int		ft_puthex(size_t i);
int		ft_puthexmaj(size_t i);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

#endif
