/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:21:05 by jormoral          #+#    #+#             */
/*   Updated: 2024/06/25 16:21:59 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printvoid(unsigned long int n)
{
	unsigned long int	count;

	count = 0;
	if (n >= 16)
		count = count + ft_printvoid(n / 16);
	ft_putchar("0123456789abcdef"[n % 16]);
	count++;
	return (count);
}

int	ft_putvoid(unsigned long long n)
{
	unsigned long long	v;

	v = 0;
	if (n == 0)
		return (ft_putstr("(nil)"));
	v = ft_putstr("0x");
	v = v + ft_printvoid(n);
	return (v);
}
