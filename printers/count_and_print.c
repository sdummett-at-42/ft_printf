/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:26:22 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/09 14:40:35 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
 *	count_and_print() skips all the flags and specifier character, adds
 *	the len that will be printed for the return of ft_printf and then
 *	print the string.
*/

void	count_and_print(char **format, char *str, char c, int *ptf_ret)
{
	int	len;

	if (c == 'd')
	{
		while (**format != c && **format != 'i')
			(*format)++;
	}
	else
	{
		while (**format != c)
			(*format)++;
	}
	(*format)++;
	len = ft_strlen(str);
	*ptf_ret = *ptf_ret + len;
	write(1, str, len);
}
