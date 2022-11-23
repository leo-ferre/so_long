/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:32:00 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 19:24:03 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	shape_check(char **map)
{
	size_t	len_line_one;
	int		i;

	len_line_one = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (len_line_one != ft_strlen(map[i]))
		{
			warning_printer(WRONG_SHAPE);
			map_free(map);
			exit(0);
		}
		i++;
	}
}
