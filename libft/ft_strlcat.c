/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:55:40 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 19:04:56 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	size_t			destsize;
	size_t			srcsize;

	srcsize = ft_strlen(src);
	destsize = 0;
	while (dest[destsize] != '\0' && destsize < size)
		destsize++;
	i = 0;
	if (destsize < size)
	{
		while (src[i] != '\0' && destsize + i < size - 1)
		{
			dest[destsize + i] = src[i];
			i++;
		}
		dest[destsize + i] = '\0';
	}
	return (destsize + srcsize);
}
