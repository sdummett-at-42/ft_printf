/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:50:39 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/07 14:57:02 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static void	prec_parsing(t_attribs *flag, char **fmt, va_list var, int *i)
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

static void	width_parsing(t_attribs *flag, char **fmt, va_list var, int *i)
{
	int	j;

	j = *i;
	if ((*fmt)[j] == '-')
	{
		flag->negative = -1;
		j++;
	}
	while ((*fmt)[j] == '0')
		j++;
	while ((*fmt)[j] == '-')
		j++;
	if ((*fmt)[j] == '*')
	{
		flag->width = va_arg(var, int);
		if (flag->negative == -1 && flag->width > 0)
			flag->width = flag->width * -1;
		j++;
	}
	else
		flag->width = ft_atoi(&(*fmt)[j]) * flag->negative;
	while (((*fmt)[j] >= '0' && (*fmt)[j] <= '9') || \
			(*fmt)[j] == '-')
		j++;
	*i = j;
}

static void	padding_parsing(t_attribs *flag, char **fmt, va_list var, int *i)
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

t_attribs	*fmt_parser(char **fmt, va_list var)
{
	int			i;
	t_attribs	*flag;

	flag = struct_init();
	i = 0;
	flag->negative = 1;
	if ((*fmt)[i] == ' ')
	{
		flag->blank = 1;
		while ((*fmt)[i] == ' ')
			i++;
	}
	if ((*fmt)[i] == '+')
	{
		flag->pos_prefix = 1;
		flag->blank = 0;
		while ((*fmt)[i] == '+' || (*fmt)[i] == ' ') // <=== modif blank flag
			i++;
	}
	if ((*fmt)[i] == '#')
	{
		flag->prefix = 1;
		while ((*fmt)[i] == '#')
			i++;
	}
	if ((*fmt)[i] == '0')
		padding_parsing(flag, fmt, var, &i);
	if (((*fmt)[i] >= '1' && (*fmt)[i] <= '9') || \
			(*fmt)[i] == '-' || (*fmt)[i] == '*')
		width_parsing(flag, fmt, var, &i);
	if ((*fmt)[i] == '.')
		prec_parsing(flag, fmt, var, &i);
	return (flag);
}
