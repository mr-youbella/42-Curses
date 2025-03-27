/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:24:10 by youbella          #+#    #+#             */
/*   Updated: 2025/03/25 00:10:52 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <libc.h>
# include "utils/libft_bonus.h"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_RL 123
# define KEY_RR 124	
# define KEY_RU 126
# define KEY_RD 125

typedef struct data
{
	void	*mlx;
	void	*win;
	void	*background;
	void	*wall;
	void	*steve_up;
	void	*steve_down;
	void	*steve_left;
	void	*steve_right;
	void	*zombie;
	void	*zombie2;
	void	*xp;
	void	*door;
	void	*open_door;
	int		move_x;
	int		move_y;
	int		width;
	int		height;
	char	**map;
	int		xp_count;
	int		move_count;
	int		xp_total;
	char	pos;
	int		anim_frame;
	int		anim_speed;
}	t_data;

char	**check_map(char *map);
int		count_c(char **map);
void	put_image(void	*img, t_data *data, int width, int height);
void	put_image_to_map(t_data *data, int width, int height);
int		file_image(t_data *data);
void	draw_map(t_data *data);

#endif
