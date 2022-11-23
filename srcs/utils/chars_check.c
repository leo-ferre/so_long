/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:31:50 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 19:25:13 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_chars(t_map *mp)
{
	mp->player = 0;
	mp->collectible = 0;
	mp->exit_map = 0;
}

void	chars_counter(char c, t_game *game, int x, int y)
{
	if (c == 'P')
	{
		game->player.p_x = x;
		game->player.p_y = y;
		game->map.player++;
	}
	if (c == 'C')
		game->map.collectible++;
	if (c == 'E')
		game->map.exit_map++;
}

void	test_values(t_map *mp)
{
	if (mp->player != 1 || mp->exit_map != 1 || mp->collectible < 1)
	{
		warning_printer(WRONG_NBR_CHARS);
		map_free(mp->map);
		exit(0);
	}
}

void	chars_check(char **map, t_game *game)
{
	int	x;
	int	y;

	init_chars(&game->map);
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] != '1' && map[y][x] != '0'
				&& map[y][x] != 'P' && map[y][x] != 'C' && map[y][x] != 'E')
			{
				warning_printer(WRONG_CHARS);
				map_free(map);
				exit(0);
			}
			chars_counter(map[y][x], game, x, y);
		}
	}
	test_values(&game->map);
	game->map.height = y;
	game->map.width = ft_strlen(map[0]);
}
