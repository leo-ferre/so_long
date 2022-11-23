/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:34:05 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 19:23:16 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	keys_game(int key, t_game *game)
{
	if (key == KEY_ESCAPE)
		game_free(game);
	else
		move_game(key, game);
	return (0);
}
