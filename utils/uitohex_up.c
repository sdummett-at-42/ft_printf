/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitohex_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:19:42 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/09 15:21:04 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
 *	uitohexup() : Just unsigned int to hexadecimal upper case conversion.
*/

static int	len_str(unsigned long nb)
{
	int	len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

char	*uitohex_up(unsigned long nb)
{
	char	*str;
	char	*hexbase_up;
	int		len;

	hexbase_up = "0123456789ABCDEF";
	len = len_str(nb);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	str[len] = 0;
	while (nb)
	{
		str[len - 1] = *(hexbase_up + nb % 16);
		nb = nb / 16;
		len--;
	}
	return (str);
}
