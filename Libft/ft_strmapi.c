/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:55:52 by jormoral          #+#    #+#             */
/*   Updated: 2024/05/14 18:34:02 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*temp;
	unsigned int	i;
	char			c;

	i = 0;
	temp = malloc(ft_strlen(s) + 1);
	if (!temp)
		return (NULL);
	while (s[i] != '\0')
	{
		c = f(i, s[i]);
		temp[i] = c;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
