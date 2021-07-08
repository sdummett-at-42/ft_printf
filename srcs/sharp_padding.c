/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharp_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:49:25 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/08 17:51:12 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	copy_str(char *new, char *str, int i, int j)
{
	while (str[j] != '\0')
	{
		new[i] = str[j];
		i++;
		j++;
	}
	new[i] = '\0';
}

static int	sharp_insert_zero(char *new, int padding)
{
	int	i;

	i = 2;
	while (padding != 0)
	{
		new[i] = '0';
		i++;
		padding--;
	}
	return (i);
}

char	*sharp_hexa_pad(char *str, int padding, int len)
{
	int		i;
	char	*new;

	if (padding <= len)
		return (str);
	new = malloc(sizeof(char) * padding + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < 2)
	{
		new[i] = str[i];
		i++;
	}
	padding = padding - len;
	i = sharp_insert_zero(new, padding);
	copy_str(new, str, i, 2);
	free(str);
	return (new);
}
