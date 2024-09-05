/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:59:15 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/30 15:35:36 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(char ***matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix && matrix[i])
	{
		j = 0;
		while (matrix[i] && matrix[i][j])
			free(matrix[i][j++]);
		free(matrix[i++]);
	}
	free(matrix);
}

void	free_data(t_map *fdf)
{
	int	i;

	i = fdf->max_x;
	while (i--)
		free(fdf->map_data[i]);
	free(fdf->map_data);
}
