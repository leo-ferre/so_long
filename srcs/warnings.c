/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warnings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:23:08 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/27 18:43:48 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	warning_printer(int status)
{
	char	*message;

	if (status == WRONG_NBR_CHARS)
		message = "Error\nThe number of map chars is invalid.\n\n";
	if (status == WRONG_CHARS)
		message = "Error\nInvalid map chars.\n\n";
	if (status == WRONG_EXT)
		message = "Error\nWrong map extension. Must be .ber.\n\n";
	if (status == WRONG_PATH)
		message = "Error\nInvalid path.\n\n";
	if (status == WRONG_SHAPE)
		message = "Error\nThe map should be rectangular.\n\n";
	if (status == WRONG_WALLS)
		message = "Error\nThe map should be surrounded with walls.\n\n";
	if (status == WRONG_ARGS)
		message = "Error\nInvalid number of arguments.\n\n";
	if (status == WRONG_MAP)
		message = "Error\nThe map is empty.\n\n";
	if (status == WRONG_FILE)
		message = "Error\nThe map file is invalid or dont exist.\n\n";
	if (status == WRONG_GRAPHIC)
		message = "Error\nMissing graphical interface.\n\n";
	ft_printf("%s", message);
	return (status);
}
