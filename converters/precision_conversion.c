/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:42:57 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/09 15:23:27 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
 *	precision_conversion() will add '0' if precision is greater than
 *	the actual length of the string.
*/

static char	*positive_precision(char *str, int precision, int len)
{
	int		i;
	char	*new;

	if (precision <= len)
		return (str);
	new = (char *)malloc(sizeof(char) * precision + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	precision = precision - len;
	while (i < precision)
	{
		new[i] = '0';
		i++;
	}
	len = 0;
	while (str[len] != 0)
	{
		new[i] = str[len];
		i++;
		len++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

static char	*negative_precision(char *str, int precision, int len)
{
	int		i;
	char	*new;

	if (!(precision + 1 >= len))
		return (str);
	new = (char *)malloc(sizeof(char) * precision + 2);
	new[0] = '-';
	precision = precision - (len - 1);
	i = 1;
	while (precision != 0)
	{
		new[i] = '0';
		i++;
		precision--;
	}
	precision = 1;
	while (str[precision] != '\0')
	{
		new[i] = str[precision];
		i++;
		precision++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

char	*precision_conversion(char *str, int precision)
{
	int	len;

	len = ft_strlen(str);
	if (str[0] == '-')
		return (negative_precision(str, precision, len));
	else
		return (positive_precision(str, precision, len));
}
