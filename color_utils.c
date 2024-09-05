/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:35:04 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/30 15:39:22 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t	atoi_hexa(char *str)
{
	uint32_t	acc;
	int			i;

	i = 0;
	acc = 0;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f'))
	{
		if (str[i] < 'a')
			acc = acc * 16 + str[i] - '0';
		else
			acc = acc * 16 + str[i] - 'a' + 10;
		i++;
	}
	return (acc);
}

uint32_t	load_color(char *str)
{
	char		**tmp_color;
	uint32_t	color;
	int			i;

	color = 0x66ffffff;
	if (ft_strchr(str, 'x'))
	{
		tmp_color = ft_split(str, 'x');
		if (!tmp_color || !tmp_color[1])
			perror("Color not valid");
		else
			color = atoi_hexa(tmp_color[1]) * 256 + 0xff;
		i = 0;
		while (tmp_color && tmp_color[i])
			free(tmp_color[i++]);
		free(tmp_color);
	}
	return (color);
}
