/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:59:32 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/23 16:17:35 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		while (len)
		{
			*((unsigned char *)dst + len - 1) = *((unsigned char *)src
					+ len - 1);
			len--;
		}
	}
	else
	{
		while (len)
		{
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
			len--;
			i++;
		}
	}
	return (dst);
}
