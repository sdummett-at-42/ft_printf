/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:41:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/07 00:21:43 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*neg_wid_handler(char *str, int width, int len)
{
	int		i;
	char	*new;

	if (width <= len)
		return (str);
	new = malloc(sizeof(char) * width + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	while (i != width)
	{
		new[i] = ' ';
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

static char	*pos_wid_handler(char *str, int width, int len)
{
	int		i;
	char	*new;

	if (width <= len)
		return (str);
	new = malloc(sizeof(char) * width + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < (width - len))
	{
		new[i] = ' ';
		i++;
	}
	len = 0;
	while (str[len] != '\0')
	{
		new[i] = str[len];
		i++;
		len++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

char	*width_handler(char *str, int width)
{
	int	len;

	len = ft_strlen(str);
	if (width < 0)
		return (neg_wid_handler(str, width * -1, len));
	return (pos_wid_handler(str, width, len));
}
