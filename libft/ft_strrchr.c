/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 22:33:37 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/25 13:16:09 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	const char	*ptr;

	ptr = 0;
	while (*str)
	{
		if (*str == (unsigned char)ch)
			ptr = str;
		str++;
	}
	if (*str == (unsigned char)ch)
		return ((char *)str);
	return ((char *)ptr);
}
