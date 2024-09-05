/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:51:33 by jormoral          #+#    #+#             */
/*   Updated: 2024/05/14 18:42:10 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*sub;
	size_t		i;
	size_t		f;

	f = ft_strlen(s1);
	i = 0;
	while (ft_strchr(set, s1[i]) != NULL && i < f)
	{
		i++;
	}
	while (ft_strchr (set, s1[f]) != NULL && i < f)
	{
		f--;
	}
	sub = ft_substr(s1, i, f - i + 1);
	if (!sub)
		return (0);
	return (sub);
}
