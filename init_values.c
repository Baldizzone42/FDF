/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:51:40 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/30 14:44:26 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init_fdf(t_map **fdf, char *file)
{
	*fdf = ft_calloc(sizeof(t_map), 1);
	if (!(*fdf))
		return (-1);
	(*fdf)->file = file;
	(*fdf)->max_x = 0;
	(*fdf)->max_x = 0;
	(*fdf)->x_range[0] = 0;
	(*fdf)->x_range[1] = 0;
	(*fdf)->y_range[0] = 0;
	(*fdf)->y_range[1] = 0;
	(*fdf)->img_width = 1500;
	(*fdf)->img_height = 1500;
	(*fdf)->scale = 1.5;
	(*fdf)->o_xy[0] = 0;
	(*fdf)->o_xy[1] = 0;
	(*fdf)->map_data = NULL;
	return (0);
}
