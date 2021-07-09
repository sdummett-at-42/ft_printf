/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_eq_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:27:13 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/09 14:27:32 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
 *	check_if_eq_zero() checks if the string is "0" and returns an empty
 *	string if the precision is 0 too.
*/

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
