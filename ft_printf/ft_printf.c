/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:16:27 by jormoral          #+#    #+#             */
/*   Updated: 2024/06/25 16:45:35 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checkletter(char c, va_list args)
{
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == '%')
		return (ft_putchar('%'));
	if ((c == 'i') || (c == 'd'))
		return (ft_putnbr(va_arg(args, int)));
	if ((c == 'x') || (c == 'X'))
		return (ft_printhex(va_arg(args, unsigned int), c));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	if (c == 'p')
		return (ft_putvoid(va_arg(args, unsigned long long)));
	return (0);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;
	int		x;

	x = 0;
	i = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			x = x + checkletter(s[i], args);
			i++;
		}
		else if (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
			x++;
		}
	}
	va_end (args);
	return (x);
}
