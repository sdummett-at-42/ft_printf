/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_call_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 23:10:31 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/08 18:39:36 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
 *	1 : %c
 *	2 : %s
 *	3 : %p
 *	4 : %d - %i
 *	5 : %u
 *	6 : %x
 *	7 : %X
 *	8 : %%
 */

void	call_handler(int handler_choice, char **fmt, va_list var, int *len)
{
	if (handler_choice == 1)
		c_printer(fmt, var, len);
	else if (handler_choice == 2)
		s_printer(fmt, var, len);
	else if (handler_choice == 3)
		p_printer(fmt, var, len);
	else if (handler_choice == 4)
		d_i_printer(fmt, var, len);
	else if (handler_choice == 5)
		u_printer(fmt, var, len);
	else if (handler_choice == 6)
		lower_x_printer(fmt, var, len);
	else if (handler_choice == 7)
		upper_x_printer(fmt, var, len);
	else if (handler_choice == 8)
		percent_printer(fmt, var, len);
}

static void	search_specifier_bis(char **fmt, int *ret, int *i)
{
	if ((*fmt)[*i] == 'c')
		*ret = 1;
	else if ((*fmt)[*i] == 's')
		*ret = 2;
	else if ((*fmt)[*i] == 'p')
		*ret = 3;
	else if ((*fmt)[*i] == 'd' || (*fmt)[*i] == 'i')
		*ret = 4;
	else if ((*fmt)[*i] == 'u')
		*ret = 5;
	else if ((*fmt)[*i] == 'x')
		*ret = 6;
	else if ((*fmt)[*i] == 'X')
		*ret = 7;
	else if ((*fmt)[*i] == '%')
		*ret = 8;
}

int	search_specifier(char **fmt)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while ((*fmt)[i] != '\0')
	{
		search_specifier_bis(fmt, &ret, &i);
		i++;
		if (ret != 0)
			break ;
	}
	return (ret);
}
