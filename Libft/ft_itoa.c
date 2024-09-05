/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:30:12 by jormoral          #+#    #+#             */
/*   Updated: 2024/05/14 17:41:14 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	digits(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10 != '\0')
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		d;
	long int	nbr;

	nbr = n;
	d = digits(n);
	str = malloc((d + 1) * sizeof (char));
	if (!str)
		return (NULL);
	str[d] = '\0';
	if (nbr < 0)
		nbr *= -1;
	while (d > 0)
	{
		d--;
		str[d] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
