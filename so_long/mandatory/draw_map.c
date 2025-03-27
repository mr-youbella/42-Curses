/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:36:08 by youbella          #+#    #+#             */
/*   Updated: 2025/03/24 20:59:53 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_data *data)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	while (data->map[height] != NULL)
	{
		width = 0;
		while (data->map[height][width] != '\0')
		{
			put_image_to_map(data, width, height);
			width++;
		}
		height++;
	}
	if (data->pos == 'l')
		mlx_put_image_to_window(data->mlx, data->win, \
								data->steve_left, data->move_x, data->move_y);
	else if (data->pos == 'r')
		mlx_put_image_to_window(data->mlx, data->win, \
								data->steve_right, data->move_x, data->move_y);
	else if (data->pos == 'u')
		mlx_put_image_to_window(data->mlx, data->win, \
								data->steve_up, data->move_x, data->move_y);
	else if (data->pos == 'd')
		mlx_put_image_to_window(data->mlx, data->win, \
								data->steve_down, data->move_x, data->move_y);
}
