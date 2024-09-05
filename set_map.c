/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:49:07 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/30 17:37:19 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_setting_maps(t_map *fdf)
{
	int	i;
	int	j;

	fdf->x_range[0] = fdf->map_data[0][fdf->max_y - 1].x;
	fdf->x_range[1] = fdf->map_data[fdf->max_x - 1][0].x;
	i = fdf->max_x;
	while (i--)
	{
		j = fdf->max_y;
		while (j--)
		{
			if (fdf->map_data[i][j].y < fdf->y_range[0])
				fdf->y_range[0] = fdf->map_data[i][j].y;
			if (fdf->map_data[i][j].y > fdf->y_range[1])
				fdf->y_range[1] = fdf->map_data[i][j].y;
		}
	}
	ft_set_scale(fdf);
}

int	loading_map(t_map *fdf)
{
	char	***tmp_map;
	int		j;
	int		i;

	tmp_map = read_fdf(fdf);
	fdf->map_data = ft_calloc(sizeof(t_point *), fdf->max_x);
	if (!tmp_map || !fdf->map_data)
		return (free_matrix(tmp_map), free_data(fdf), free(fdf), -1);
	i = fdf->max_x;
	while (i--)
	{
		fdf->map_data[i] = ft_calloc(sizeof(t_point), fdf->max_y);
		if (!fdf->map_data[i])
			return (free_data(fdf), free_matrix(tmp_map), -1);
		j = fdf->max_y;
		while (j--)
		{
			fdf->map_data[i][j].x = (i - j) * 87;
			fdf->map_data[i][j].y = (i + j) * 50 - 100 * ft_atoi(tmp_map[j][i]);
			fdf->map_data[i][j].c = load_color(tmp_map[j][i]);
		}
	}
	ft_setting_maps(fdf);
	free_matrix(tmp_map);
	return (0);
}

float	ft_set_scale(t_map *fdf)
{
	int	dif_x;
	int	dif_y;

	dif_y = fdf->y_range[1] - fdf->y_range[0];
	dif_x = fdf->x_range[1] - fdf->x_range[0];
	fdf->scale = (fdf->img_width * 0.9) / dif_x;
	if (((fdf->img_height - 10.0) / dif_y)
		< fdf->scale)
		fdf->scale = (fdf->img_height * 0.9) / dif_y;
	fdf->o_xy[0] = fdf->img_width / 2.0 - (fdf->x_range[1] + fdf->x_range[0])
		* fdf->scale / 2.0;
	fdf->o_xy[1] = fdf->img_height / 2.0 - (fdf->y_range[1] + fdf->y_range[0])
		* fdf->scale / 2.0 - fdf->img_height * 0.025;
	return (fdf->scale);
}
