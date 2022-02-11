/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:13:55 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/23 15:56:59 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*ptr;

	ptr = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (*(str + i))
	{
		*(ptr + i) = *(str + i);
		i++;
	}
	*(ptr + i) = 0;
	return (ptr);
}
