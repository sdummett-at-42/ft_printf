/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:50:39 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/09 14:55:39 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
 *	dot_parsing() stock the value of the precision in flag->precision.
*/

void	dot_parsing(t_attribs *flag, char **fmt, va_list var, int *i)
{
	int	j;

	j = *i;
	j++;
	if ((*fmt)[j] == '*')
		flag->precision = va_arg(var, int);
	else if ((*fmt)[j] >= '0' && (*fmt)[j] <= '9')
		flag->precision = ft_atoi(&(*fmt)[j]);
	if (flag->precision == 0)
		flag->prec_is_zero = 1;
	while ((*fmt)[j] >= '0' && (*fmt)[j] <= '9')
		j++;
	*i = j;
}

/*
 *	zero_parsing() stock the value of the padding in flag->padding.
*/

void	zero_parsing(t_attribs *flag, char **fmt, va_list var, int *i)
{
	int	j;

	j = *i;
	j++;
	if ((*fmt)[j] == '-')
		flag->padding = 0;
	else if ((*fmt)[j] == '*')
		flag->padding = va_arg(var, int);
	else
		flag->padding = ft_atoi(&(*fmt)[j]);
	while (((*fmt)[j] >= '0' && (*fmt)[j] <= '9') || \
			(*fmt)[j] == '*')
		j++;
	*i = j;
}

/*
 *	plus_parsing() set the value for the '+' flag at 1 in flag->plus_prefix.
*/

void	plus_parsing(t_attribs *flag, char **fmt, int *i)
{
	int	j;

	j = *i;
	flag->plus_prefix = 1;
	flag->blank = 0;
	while ((*fmt)[j] == '+' || (*fmt)[j] == ' ')
		j++;
	*i = j;
}

/*
 *	sharp_parsing() set the value for the '#' flag at 1 in flag->prefix.
*/

void	sharp_parsing(t_attribs *flag, char **fmt, int *i)
{
	int	j;

	j = *i;
	flag->prefix = 1;
	while ((*fmt)[j] == '#')
		j++;
	*i = j;
}

/*
 *	blank_parsing() set the value for the ' ' flag at 1 in flag->blank.
*/

void	blank_parsing(t_attribs *flag, char **fmt, int *i)
{
	int	j;

	j = *i;
	flag->blank = 1;
	while ((*fmt)[j] == ' ')
		j++;
	*i = j;
}
