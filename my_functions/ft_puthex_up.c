/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 05:05:58 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/26 05:09:40 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_str(long int nb)
{
	int	len;

	len = 0;
	while (nb)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

static long int conv_nb(long int nb)
{
	long int ref;

	ref = 4294967295;
	nb = (nb * -1) - 1;
	ref = ref - nb;
	return (ref);
}

void	ft_puthex_up(long int nb)
{
	char	*str;
	char	*hexbase;
	int		len;

	hexbase = "0123456789ABCDEF";
	if (nb < 0)
		nb = conv_nb(nb);
	len = len_str(nb);
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len] = 0;
	while (nb)
	{
		str[len - 1] = *(hexbase + nb % 16);
		nb = nb / 16;
		len--;
	}
	ft_putstr(str);
	free(str);
}
