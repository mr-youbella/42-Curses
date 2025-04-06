/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:48:20 by youbella          #+#    #+#             */
/*   Updated: 2025/04/05 22:18:22 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	animation_loop(t_data *data)
{
	data->anim_frame++;
	mlx_clear_window(data->mlx, data->win);
	draw_map(data, 0, 0);
	return (0);
}

void	print_moves_score(t_data *data)
{
	char	*move_score;

	move_score = ft_itoa(data->move_count);
	mlx_string_put(data->mlx, data->win, 25, 15, 0xFFFFFF, \
					move_score);
	free(move_score);
	move_score = ft_itoa(data->xp_count);
	mlx_string_put(data->mlx, data->win, ft_strlen(data->map[0]) * 64 - 50, 15, \
					0x00ff00, move_score);
	free(move_score);
}

static char	**ft_read_map(char *path_file, char	*line, char	*join_line)
{
	char	**map;
	int		fd;

	fd = open(path_file, O_RDONLY, 0777);
	if (fd == -1)
		ft_putstr_fd("Error: file not open!\n", 2);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "\n", 1) == 0)
		{
			close(fd);
			ft_putstr_fd("Error: Empty line!\n", 2);
		}
		join_line = ft_strjoin(join_line, line);
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(join_line, '\n');
	if (!map)
	{
		close(fd);
		ft_putstr_fd("Map no found\n", 2);
	}
	return (free(join_line), close(fd), map);
}

void	f(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	char	**map;

	atexit(f);
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4))
		{
			map = ft_read_map(argv[1], NULL, NULL);
			check_map(map);
		}
		else
			ft_putstr_fd("Problem name!\n", 2);
	}
	else
		ft_putstr_fd("arg != 2\n", 2);
}
