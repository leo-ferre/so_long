/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:31:57 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 19:25:59 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	sub_pos(t_path *valid_path, t_game *game, int y, int x)
{
	if (valid_path->aux[y][x] == '1')
		return ;
	else
	{
		if (valid_path->aux[y][x] == 'C')
			valid_path->collectible++;
		if (valid_path->aux[y][x] == 'E')
		{
			valid_path->exit_map++;
			if (valid_path->collectible != game->map.collectible)
				return ;
		}
		valid_path->aux[y][x] = '1';
		sub_pos(valid_path, game, y + 1, x);
		sub_pos(valid_path, game, y - 1, x);
		sub_pos(valid_path, game, y, x + 1);
		sub_pos(valid_path, game, y, x - 1);
		return ;
	}
}

void	path_check(char *argv, t_game *game)
{
	t_path	valid_path;
	char	*str_aux;

	valid_path.collectible = 0;
	valid_path.exit_map = 0;
	str_aux = map_read(argv);
	valid_path.aux = ft_split(str_aux, '\n');
	free(str_aux);
	sub_pos(&valid_path, game, game->player.p_y, game->player.p_x);
	map_free(valid_path.aux);
	if (valid_path.collectible != game->map.collectible
		|| valid_path.exit_map != 1)
	{
		map_free(game->map.map);
		warning_printer(WRONG_PATH);
		exit(0);
	}
}
