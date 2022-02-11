/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 22:18:37 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/25 13:14:15 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	while (*str)
	{
		if (*str == (unsigned char)ch)
			return ((char *)str);
		str++;
	}
	if (*str == (unsigned char)ch)
		return ((char *)str);
	return (0);
}
