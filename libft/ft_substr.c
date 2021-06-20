/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:45:28 by sdummett          #+#    #+#             */
/*   Updated: 2021/05/21 19:14:53 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (0);
	if (!(start > ft_strlen(s)))
	{
		if (ft_strlen(s) - start < len)
			len = ft_strlen(s) - start;
		ptr = malloc(sizeof(char) * len + 1);
		if (!ptr)
			return (0);
		*(ptr + len) = 0;
		while (len)
		{
			*(ptr + len - 1) = *(s + start + len - 1);
			len--;
		}
		return (ptr);
	}
	else
		return (ft_calloc(1, sizeof(char)));
}
