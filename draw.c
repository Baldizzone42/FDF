/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:20:12 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/30 17:37:07 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static uint32_t	grad_color(uint32_t start, uint32_t end, float step)
{
	t_color		cl;
	uint32_t	color;

	cl.r_start = (start >> 24) & 0xFF;
	cl.g_start = (start >> 16) & 0xFF;
	cl.b_start = (start >> 8) & 0xFF;
	cl.a_start = start & 0xFF;
	cl.r_end = (end >> 24) & 0xFF;
	cl.g_end = (end >> 16) & 0xFF;
	cl.b_end = (end >> 8) & 0xFF;
	cl.a_end = end & 0xFF;
	cl.r = cl.r_start + (cl.r_end - cl.r_start) * step;
	cl.g = cl.g_start + (cl.g_end - cl.g_start) * step;
	cl.b = cl.b_start + (cl.b_end - cl.b_start) * step;
	cl.a = cl.a_start + (cl.a_end - cl.a_start) * step;
	color = (cl.r << 24) | (cl.g << 16) | (cl.b << 8) | cl.a;
	return (color);
}

static void	swap_points(t_point *start, t_point *end)
{
	t_point	swap;

	swap = *start;
	*start = *end;
	*end = swap;
}

static void	plot_line(t_point start, t_point end, mlx_image_t *img, t_map *fdf)
{
	float	m;
	int		b;
	int		i;

	m = (float)(end.y - start.y) / (float)(end.x - start.x);
	if ((m <= 1.0 && m >= -1.0 && start.x > end.x)
		|| ((m > 1.0 || m < -1.0) && start.y > end.y))
		swap_points(&start, &end);
	b = (start.y - m * start.x) * fdf->scale;
	if (m <= 1.0 && m >= -1.0)
	{
		i = start.x * fdf->scale;
		while (i++ < end.x * fdf->scale)
			mlx_put_pixel(img, i + fdf->o_xy[0], i * m + fdf->o_xy[1] + b,
				grad_color(start.c, end.c, (i - start.x * fdf->scale)
					/ ((end.x - start.x) * fdf->scale)));
		return ;
	}
	i = start.y * fdf->scale;
	while (i++ < end.y * fdf->scale)
		mlx_put_pixel(img, fdf->o_xy[0] + (i - b) / m, i + fdf->o_xy[1],
			grad_color(start.c, end.c, (i - start.y * fdf->scale)
				/ ((end.y - start.y) * fdf->scale)));
}

void	plot_map(t_map *fdf, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->max_x)
	{
		j = 0;
		while (j < fdf->max_y)
		{
			if (i < fdf->max_x - 1)
				plot_line(fdf->map_data[i][j], fdf->map_data[i + 1][j],
					img, fdf);
			if (j < fdf->max_y - 1)
				plot_line(fdf->map_data[i][j], fdf->map_data[i][j + 1],
					img, fdf);
			j++;
		}
		i++;
	}
}
