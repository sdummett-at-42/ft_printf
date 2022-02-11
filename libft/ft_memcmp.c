/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:00:24 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/24 11:17:59 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	if (len)
	{
		while (--len)
		{
			if (*(unsigned char *)b1 != *(unsigned char *)b2)
				return (*(unsigned char *)b1 - *(unsigned char *)b2);
			b1++;
			b2++;
		}
		return (*(unsigned char *)b1 - *(unsigned char *)b2);
	}
	else
		return (0);
}
