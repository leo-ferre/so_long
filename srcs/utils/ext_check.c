/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:31:40 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 20:24:07 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ext_check(char *argv)
{
	if (ft_strncmp(argv + ft_strlen(argv) - 4, ".ber", 5) != 0)
	{
		warning_printer(WRONG_EXT);
		ft_printf("For Example: ./maps/map.ber\n\n");
		exit(0);
	}
}
