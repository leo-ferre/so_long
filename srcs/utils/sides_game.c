/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sides_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:50:27 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 19:23:31 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	sides_game(t_game *game, char direction)
{
	int	pixel;

	pixel = PIXEL;
	if (direction == 'l' && game->direction != 'l')
	{
		game->direction = 'l';
		mlx_destroy_image(game->mlx_ptr, game->images.soldier_right);
		game->images.soldier_left = mlx_xpm_file_to_image(game->mlx_ptr, \
				"./images/soldier_left.xpm", &pixel, &pixel);
	}
	else if (direction == 'r' && game->direction != 'r')
	{
		game->direction = 'r';
		mlx_destroy_image(game->mlx_ptr, game->images.soldier_left);
		game->images.soldier_right = mlx_xpm_file_to_image(game->mlx_ptr, \
				"./images/soldier_right.xpm", &pixel, &pixel);
	}
}
