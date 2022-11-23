/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:11:35 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 19:28:06 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!(game->mlx_ptr))
	{
		warning_printer(WRONG_GRAPHIC);
		map_free(game->map.map);
		exit(0);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.width * PIXEL, \
			game->map.height * PIXEL, "so_long");
	game->moves = 0;
	game->direction = 'r';
}

void	load_props(t_game *game)
{
	int	pixel;

	pixel = PIXEL;
	game->images.floor = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./images/floor.xpm", &pixel, &pixel);
	game->images.wall = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./images/wall.xpm", &pixel, &pixel);
	game->images.soldier_right = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./images/soldier_right.xpm", &pixel, &pixel);
	game->images.bombsite = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./images/bombsite.xpm", &pixel, &pixel);
	game->images.c4 = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./images/c4.xpm", &pixel, &pixel);
}

void	game_free(t_game *game)
{
	if (game->direction == 'r')
		mlx_destroy_image(game->mlx_ptr, game->images.soldier_right);
	else if (game->direction == 'l')
		mlx_destroy_image(game->mlx_ptr, game->images.soldier_left);
	mlx_destroy_image(game->mlx_ptr, game->images.floor);
	mlx_destroy_image(game->mlx_ptr, game->images.wall);
	mlx_destroy_image(game->mlx_ptr, game->images.bombsite);
	mlx_destroy_image(game->mlx_ptr, game->images.c4);
	map_free(game->map.map);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
}

void	so_long(t_game *game)
{
	game_init(game);
	load_props(game);
	mlx_expose_hook(game->win_ptr, &render_game, game);
	mlx_key_hook(game->win_ptr, &keys_game, game);
	mlx_hook(game->win_ptr, 17, 0, &x_game, game);
	mlx_loop(game->mlx_ptr);
}
