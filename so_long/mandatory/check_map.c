/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:58:25 by youbella          #+#    #+#             */
/*   Updated: 2025/03/27 05:23:48 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**check_map_elements(char **map)
{
	int	i;
	int	j;
	int	count_p_e;
	int	count_c;

	i = 0;
	count_p_e = 0;
	count_c = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != '0' && \
				map[i][j] != '1' && map[i][j] != 'C')
				return (ft_putstr_fd("ERROR\n", 2), NULL);
			else if (map[i][j] == 'P' || map[i][j] == 'E')
				count_p_e++;
			else if (map[i][j] == 'C')
				count_c++;
			j++;
		}
		i++;
	}
	if (count_p_e != 2 || count_c < 1)
		return (ft_putstr_fd("ERROR: Map must contain \
		1(P) 1(E) >1(C)\n", 1), NULL);
	return (map);
}

static char	**check_map_border(char **map)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	height = 0;
	width = ft_strlen(map[0]);
	while (map[height] != NULL)
		height++;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (ft_putstr_fd("ERROR: Border is not closed!\n", 2), NULL);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (ft_putstr_fd("ERROR: Border is not closed!\n", 2), NULL);
		i++;
	}
	return (map);
}

static char	**check_map_struct(char **map)
{
	int	i;
	int	width;
	int	len;

	i = 0;
	width = ft_strlen(map[0]);
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len != width)
			return (ft_putstr_fd("Unbalanced structure.\n", 2), NULL);
		i++;
	}
	return (map);
}

int	count_c(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void free_map(char **map)
{
	int i;

	if (!map)
	    return; 
	i = 0;
	while (map[i])
	{
	    free(map[i]);
	    i++;
	}
	free(map);
}

char	**check_map(char *path_map)
{
	int		fd;
	char	*line_map;
	char	*line;
	char	**map;
	char	*temp;

	fd = open(path_map, O_RDONLY, 0777);
	if (fd < 0)
		return (ft_putstr_fd("INVALID MAP\n", 2), NULL);
	line_map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "\n", 1) == 0)
			return (close(fd), free(line), free(line_map), ft_putstr_fd("Error: Empty line!\n", 2), NULL);
		temp = ft_strjoin(line_map, line);
		free(line);
		free(line_map);
		line_map = temp;
		line = get_next_line(fd);
	}
	map = ft_split(line_map, '\n');
	free(line_map);
	if (!map)
		return (ft_putstr_fd("ERROR\n", 2), NULL);
	if (!check_map_border(map) || !check_map_elements(map) \
		|| !check_map_struct(map))
		return (free_map(map), NULL);
	return (map);
}
