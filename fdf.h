/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:16:28 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/30 17:41:20 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "MLX42/include/MLX42/MLX42.h"
# include "Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
	uint8_t	r_start;
	uint8_t	g_start;
	uint8_t	b_start;
	uint8_t	a_start;
	uint8_t	r_end;
	uint8_t	g_end;
	uint8_t	b_end;
	uint8_t	a_end;
}	t_color;

typedef struct s_point
{
	int			x;
	int			y;
	uint32_t	c;
}	t_point;

typedef struct s_map
{
	char		*file;
	int			max_x;
	int			max_y;
	int			x_range[2];
	int			y_range[2];
	uint32_t	img_width;
	uint32_t	img_height;
	float		scale;
	int			o_xy[2];
	t_point		**map_data;
}	t_map;

int			ft_init_fdf(t_map **fdf, char *file);
int			loading_map(t_map *fdf);
void		free_matrix(char ***matrix);
void		plot_map(t_map *fdf, mlx_image_t *img);
void		free_matrix(char ***matrix);
void		free_data(t_map *fdf);
uint32_t	load_color(char *str);
uint32_t	atoi_hexa(char *str);
float		ft_set_scale(t_map *fdf);
int			check_map(t_map *fdf, char ***tmp_map);
char		***read_fdf(t_map *fdf);

#endif