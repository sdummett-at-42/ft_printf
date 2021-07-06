/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_eq_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:27:13 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/06 14:33:21 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*check_if_eq_zero(char *str, int dot)
{
	int	len;

	len = ft_strlen(str);
	if (len == 1 && str[0] == '0' && dot == 1)
	{
		free(str);
		return (ft_strdup(""));
	}
	return (str);
}
