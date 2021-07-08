/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:50:39 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/08 18:02:38 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	prec_parsing(t_attribs *flag, char **fmt, va_list var, int *i)
{
	int	j;

	j = *i;
	j++;
	if ((*fmt)[j] == '*')
	{	
		flag->precision = va_arg(var, int);
	}
	else if ((*fmt)[j] >= '0' && (*fmt)[j] <= '9')
		flag->precision = ft_atoi(&(*fmt)[j]);
	if (flag->precision == 0)
		flag->prec_is_dot = 1;
	while ((*fmt)[j] >= '0' && (*fmt)[j] <= '9')
		j++;
	*i = j;
}

void	padding_parsing(t_attribs *flag, char **fmt, va_list var, int *i)
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

void	pos_prefix_parsing(t_attribs *flag, char **fmt, int *i)
{
	int	j;

	j = *i;
	flag->pos_prefix = 1;
	flag->blank = 0;
	while ((*fmt)[j] == '+' || (*fmt)[j] == ' ')
		j++;
	*i = j;
}

void	prefix_parsing(t_attribs *flag, char **fmt, int *i)
{
	int	j;

	j = *i;
	flag->prefix = 1;
	while ((*fmt)[j] == '#')
		j++;
	*i = j;
}

void	blank_parsing(t_attribs *flag, char **fmt, int *i)
{
	int	j;

	j = *i;
	flag->blank = 1;
	while ((*fmt)[j] == ' ')
		j++;
	*i = j;
}
