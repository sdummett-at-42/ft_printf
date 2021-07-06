/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:44:37 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/06 21:48:29 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*pos_pad_handler(char *str, int padding, int len)
{
	int		i;
	char	*new;

	if (padding <= len)
		return (str);
	new = malloc(sizeof(char) * padding + 1);
	if (new == NULL)
		return (NULL);
	padding = padding - len;
	i = 0;
	while (padding != 0)
	{
		new[i] = '0';
		i++;
		padding--;
	}
	len = 0;
	while (str[len] != '\0')
	{
		new[i] = str[len];
		len++;
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

static char	*neg_pad_handler(char *str, int padding, int len)
{
	int		i;
	char	*new;

	if (padding <= len)
		return (str);
	new = malloc(sizeof(char) * padding + 1);
	if (new == NULL)
		return (NULL);
	new[0] = '-';
	padding = padding - len;
	i = 1;
	while (padding != 0)
	{
		new[i] = '0';
		i++;
		padding--;
	}
	len = 1;
	while (str[len] != '\0')
	{
		new[i] = str[len];
		len++;
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

char	*padding_handler(char *str, int padding, int precision, int dot)
{
	int	len;

	len = ft_strlen(str);
	 if (precision > 0 || dot == 1)
		return (width_handler(str, padding));
	else if (str[0] == '-')
		return (neg_pad_handler(str, padding, len));
	else
		return (pos_pad_handler(str, padding, len));
}
