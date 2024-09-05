/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:30:36 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/30 15:31:27 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_map(t_map *fdf, char ***tmp_map)
{
	int	i;

	i = fdf->max_y;
	while (tmp_map[0] && tmp_map[0][fdf->max_x])
		fdf->max_x++;
	while (i--)
	{
		if (!tmp_map[i] || !tmp_map[i][fdf->max_x - 1]
			|| tmp_map[i][fdf->max_x])
			return (-1);
	}
	return (0);
}

char	***read_fdf(t_map *fdf)
{
	int		fd;
	char	*tmp_line;
	char	***tmp_map;

	tmp_map = (char ***)calloc(1024, sizeof(char **));
	fd = open(fdf->file, O_RDONLY);
	if (!tmp_map || fd == -1)
		return (free(tmp_map), NULL);
	tmp_line = get_next_line(fd);
	while (tmp_line)
	{
		tmp_map[fdf->max_y] = ft_split(tmp_line, ' ');
		free(tmp_line);
		if (!tmp_map[fdf->max_y++])
			return (free_matrix(tmp_map), NULL);
		tmp_line = get_next_line(fd);
	}
	close(fd);
	if (check_map(fdf, tmp_map) == -1)
		return (free_matrix(tmp_map), NULL);
	return (tmp_map);
}
