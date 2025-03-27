/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:33:45 by youbella          #+#    #+#             */
/*   Updated: 2025/03/25 00:07:28 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_image(t_data *data)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	data->wall = mlx_xpm_file_to_image(data->mlx, \
	"img/wall.xpm", &width, &height);
	data->steve_up = mlx_xpm_file_to_image(data->mlx, \
	"img/steve_up.xpm", &width, &height);
	data->steve_down = mlx_xpm_file_to_image(data->mlx, \
	"img/steve_down.xpm", &width, &height);
	data->steve_left = mlx_xpm_file_to_image(data->mlx, \
	"img/steve_left.xpm", &width, &height);
	data->steve_right = mlx_xpm_file_to_image(data->mlx, \
	"img/steve_right.xpm", &width, &height);
	data->xp = mlx_xpm_file_to_image(data->mlx, \
	"img/xp.xpm", &width, &height);
	data->door = mlx_xpm_file_to_image(data->mlx, \
	"img/door.xpm", &width, &height);
	data->open_door = mlx_xpm_file_to_image(data->mlx, \
	"img/open_door.xpm", &width, &height);
	data->background = mlx_xpm_file_to_image(data->mlx, \
	"img/background.xpm", &width, &height);
	if (!data->wall || !data->steve_up || !data->steve_down || \
		!data->steve_left || !data->steve_right || !data->xp || \
		!data->door || !data->open_door || !data->background)
		return (0);
	return (1);
}

void	put_image(void	*img, t_data *data, int width, int height)
{
	mlx_put_image_to_window(data->mlx, data->win, img, width * 64, height * 64);
}

void	put_image_to_map(t_data *data, int width, int height)
{
	if (data->map[height][width] == 'P')
	{
		if (data->move_x == -1 && data->move_y == -1)
		{
			data->move_x = width * 64;
			data->move_y = height * 64;
		}
		put_image(data->background, data, width, height);
	}
	else if (data->map[height][width] == '0')
		put_image(data->background, data, width, height);
	else if (data->map[height][width] == '1')
		put_image(data->wall, data, width, height);
	else if (data->map[height][width] == 'C')
		put_image(data->xp, data, width, height);
	else if (data->map[height][width] == 'E')
		put_image(data->door, data, width, height);
}
