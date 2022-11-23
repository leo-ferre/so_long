/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:05:44 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 19:17:30 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
	{
		return (warning_printer(WRONG_ARGS));
		ft_printf("You should choose one map.\n");
		ft_printf("For Example: ./so_long ./maps/map.ber\n\n");
	}
	else
	{
		map_check(argv[1], &game);
		so_long(&game);
	}
	return (0);
}
