/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:29:13 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/23 16:18:54 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	while (len)
	{
		if (*(unsigned char *)src == (unsigned char)c)
		{
			*(unsigned char *)dst = (unsigned char)c;
			return (dst + 1);
		}
		*(unsigned char *)dst = *(unsigned char *)src;
		dst++;
		src++;
		len--;
	}
	return (0);
}
