/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:19:23 by jormoral          #+#    #+#             */
/*   Updated: 2024/05/14 18:38:17 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	size_t			i;

	ch = c;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	if (ch == 0)
	{
		return (&((char *)s)[i]);
	}
	while (i > 0)
	{
		i--;
		if (s[i] == ch)
		{
			return (&((char *)s)[i]);
		}
	}
	return (NULL);
}
