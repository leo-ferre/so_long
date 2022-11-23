/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:12:06 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 19:21:34 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_read(char *str_map)
{
	if (!str_map)
	{
		warning_printer(WRONG_MAP);
		exit(0);
	}
}

void	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

char	*map_read(char *argv)
{
	char	*str_map;
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		warning_printer(WRONG_FILE);
		exit (0);
	}
	str_map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		str_map = ft_strjoin_gnl(str_map, line);
		free(line);
	}
	check_read(str_map);
	return (str_map);
}

void	map_check(char *argv, t_game *game)
{
	char	*str_map;

	ext_check(argv);
	str_map = map_read(argv);
	game->map.map = ft_split(str_map, '\n');
	free(str_map);
	shape_check(game->map.map);
	walls_check(game->map.map);
	chars_check(game->map.map, game);
	path_check(argv, game);
}
