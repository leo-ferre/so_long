/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:32:04 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 19:24:20 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	count_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	walls_check(char **map)
{
	int	i;
	int	j;
	int	lst_x;
	int	lst_y;

	lst_x = count_lines(map) - 1;
	lst_y = ft_strlen(map[0]) - 1;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[0][j] != '1' || map[i][0] != '1'
				|| map[i][lst_y] != '1' || map[lst_x][j] != '1')
			{
				warning_printer(WRONG_WALLS);
				map_free(map);
				exit(0);
			}
		}
	}
}
