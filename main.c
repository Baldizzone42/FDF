/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:28:25 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/30 15:00:20 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_esc(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window((mlx_t *)param);
	}
}

static void	fdf_check_empty(char *str)
{
	int		fd;
	int		count;
	char	*rd;

	rd = NULL;
	fd = open(str, O_RDONLY);
	count = read(fd, rd, 1024);
	if (count == '\0')
	{
		write(STDERR_FILENO, "Map empty\n", 10);
		exit(1);
	}
	close(fd);
}

int	main(int argc, char *argv[])
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*fdf;

	if (argc != 2 || !ft_strnstr(argv[1], "fdf\0", ft_strlen(argv[1]) + 1))
		return (1);
	fdf_check_empty(argv[1]);
	if (ft_init_fdf(&fdf, argv[1]) == -1 || loading_map(fdf) == -1)
		return (write(2, "Wrong Map\n", 10), 1);
	mlx = mlx_init(1800, 1800, "FDF", 1);
	if (!mlx)
		return (perror("mlx"), 1);
	img = mlx_new_image(mlx, fdf->img_width, fdf->img_height);
	if (!img)
		return (perror("mlx"), 1);
	plot_map(fdf, img);
	mlx_resize_image(img, mlx->width, mlx->height);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_key_hook(mlx, &key_esc, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	free_data(fdf);
	free(fdf);
	return (0);
}
