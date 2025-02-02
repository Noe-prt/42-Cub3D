/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:09:45 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/02 16:08:05 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_rgb(char *line)
{
	char	**line_splitted;
	int		i;
	int		j;
	char	c;
	int		tab_size;

	line_splitted = ft_split(line, ',');
	tab_size = 0;
	while (line_splitted[tab_size])
		tab_size++;
	if (tab_size != 3)
		return (ft_free_array(line_splitted), 0);
	i = -1;
	j = -1;
	while (line_splitted[++i])
	{
		j = -1;
		while (line_splitted[i][++j])
		{
			c = line_splitted[i][j];
			if (!ft_isdigit(c))
				return (ft_free_array(line_splitted), 0);
		}
	}
	return (ft_free_array(line_splitted), 1);
}

int	check_lines(char *line)
{
	if (line[0] == 'C' || line[0] == 'F')
	{
		if (line[1] != ' ')
			return (0);
		if (!is_rgb(line + 2))
			return (0);
		return (1);
	}
	return (0);
}

int	read_lines(int fd, int *count, char *line, char *cleaned)
{
	while (line)
	{
		cleaned = remove_spaces(line);
		free(line);
		line = cleaned;
		if (!line)
			return (free(line), 1);
		if (line[0] == '\0')
			line = remove_spaces(get_next_line(fd));
		if (line[0] == 'O' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E'
			|| line[0] == 'N')
		{
			(*count)++;
			if (!check_cardinal_points(line))
				return (free(line), 1);
		}
		else if (line[0] == 'C' || line[0] == 'F')
		{
			if (!check_lines(line))
				return (free(line), 1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

char	**check_map(char *map_path)
{
	int		fd;
	int		count;
	char	*line;
	char	*cleaned;
	char	**map;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (close(fd), NULL);
	line = get_next_line(fd);
	cleaned = NULL;
	if (line == NULL)
		return (close(fd), NULL);
	count = 0;
	if (read_lines(fd, &count, line, cleaned) != 0)
		return (close(fd), gnl_cleanup(fd), NULL);
	map = parse_map(map_path);
	if (map == NULL)
		return (close(fd), gnl_cleanup(fd), NULL);
	if (check_map_content(map) != 0)
		return (close(fd), gnl_cleanup(fd), ft_free_array(map), NULL);
	gnl_cleanup(fd);
	close(fd);
	return (map);
}
