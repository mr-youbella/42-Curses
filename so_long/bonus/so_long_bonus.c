/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:20:13 by youbella          #+#    #+#             */
/*   Updated: 2025/03/25 22:06:45 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	check_collision(t_data *data, int new_x, int new_y)
{
	int	grid_y;
	int	grid_x;

	grid_y = new_y / 64;
	grid_x = new_x / 64;
	if (data->xp_count == data->xp_total)
		data->door = data->open_door;
	if (data->map[grid_y][grid_x] == '1')
		return (0);
	else if (data->map[grid_y][grid_x] == 'C')
	{
		data->map[grid_y][grid_x] = '0';
		data->xp_count++;
	}
	else if (data->map[grid_y][grid_x] == 'E')
	{
		if (data->xp_count == data->xp_total)
		{
			ft_putstr_fd("You WIN!\n", 1);
			exit(0);
		}
		return (0);
	}
	else if (data->map[grid_y][grid_x] == 'Z')
	{
		ft_putstr_fd("You Lose!\n", 1);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (1);
}

int	move_steve(t_data *data, char move, int sign, char pos)
{
	int	move_possible;

	data->pos = pos;
	if (move == 'x')
		move_possible = check_collision(data, \
		data->move_x + sign, data->move_y);
	else
		move_possible = check_collision(data, \
		data->move_x, data->move_y + sign);
	if (move_possible)
	{
		data->move_count++;
		ft_putnbr_fd(data->move_count, 1);
		ft_putchar_fd('\n', 1);
		return (64);
	}
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_win(data);
	else if (keycode == KEY_A || keycode == KEY_RL)
		data->move_x -= move_steve(data, 'x', -64, 'l');
	else if (keycode == KEY_D || keycode == KEY_RR)
		data->move_x += move_steve(data, 'x', 64, 'r');
	else if (keycode == KEY_W || keycode == KEY_RU)
		data->move_y -= move_steve(data, 'y', -64, 'u');
	else if (keycode == KEY_S || keycode == KEY_RD)
		data->move_y += move_steve(data, 'y', 64, 'd');
	check_collision(data, data->move_x, data->move_y);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	return (1);
}

int	animation_loop(t_data *data)
{
	data->anim_frame++;
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	return (0);
}

void	data_init(t_data *data)
{
	data->mlx = mlx_init();
	data->xp_count = 0;
	data->move_count = 0;
	data->move_x = -1;
	data->move_y = -1;
	data->pos = 'd';
	data->anim_frame = 0;
	data->anim_speed = 20;
}

void f()
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		height;

	atexit(f);
	data_init(&data);
	height = 0;
	data.map = check_map(argv[1]);
	if (!data.map || argc != 2 || \
		ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4))
		return (1);
	if (!file_image(&data))
		return (ft_putstr_fd("INVALID IMAGE!\n", 2), 1);
	while (data.map[height] != NULL)
		height++;
	data.win = mlx_new_window(data.mlx, ft_strlen(data.map[0]) * 64, \
								height * 64, "minecraft 2d (bonus)");
	data.xp_total = count_c(data.map);
	draw_map(&data);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 17, 0, close_win, &data);
	mlx_loop_hook(data.mlx, animation_loop, &data);
	mlx_loop(data.mlx);
}
