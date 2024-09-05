/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:29:25 by jormoral          #+#    #+#             */
/*   Updated: 2024/06/25 16:30:39 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_counts_digits(long int n)
{
	int	digits;

	digits = 0;
	if (n < 0)
	{
		digits++;
		n = n * -1;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

int	ft_putnbr(int n)
{
	char		*result;
	int			digits;
	long int	nbr;

	nbr = n;
	digits = ft_counts_digits(n);
	result = (char *)malloc(digits + 1);
	if (!result)
		return (0);
	result[digits] = '\0';
	if (nbr < 0)
		nbr = nbr * -1;
	while (digits--)
	{
		result[digits] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (n < 0)
		result[0] = '-';
	n = ft_putstr(result);
	free(result);
	return (n);
}
