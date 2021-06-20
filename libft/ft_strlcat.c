/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:07:57 by sdummett          #+#    #+#             */
/*   Updated: 2021/05/21 19:55:29 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (dest[i] != 0)
		i++;
	while (*src != 0 && i < size - 1)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = 0;
	if (ft_strlen(dest) > size)
		return (ft_strlen(src) + size);
	return (ft_strlen(dest) + ft_strlen(src));
}
