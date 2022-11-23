/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:24:27 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 21:31:41 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_render(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == 'P')
	{
		if (game->direction == 'r')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
					game->images.soldier_right, x * PIXEL, y * PIXEL);
		else if (game->direction == 'l')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
					game->images.soldier_left, x * PIXEL, y * PIXEL);
	}
	if (game->map.map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
					game->images.bombsite, x * PIXEL, y * PIXEL);
	if (game->map.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
					game->images.wall, x * PIXEL, y * PIXEL);
	if (game->map.map[y][x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
					game->images.floor, x * PIXEL, y * PIXEL);
	if (game->map.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
					game->images.c4, x * PIXEL, y * PIXEL);
}

int	render_game(t_game *game)
{
	int		x;
	int		y;
	char	*message;

	message = ft_itoa(game->moves);
	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			map_render(game, x, y);
			x++;
		}
		y++;
	}
	mlx_set_font(game->mlx_ptr, game->win_ptr, \
	"-Misc-Fixed-Medium-R-Normal-ja-18-120-100-100-C-180-ISO10646-1");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 1, 20, 0xFFFFFF, message);
	free(message);
	return (0);
}
