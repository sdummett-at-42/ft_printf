/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:27:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/07 14:55:46 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_attribs	*struct_init(void)
{
	t_attribs	*new;

	new = (t_attribs *)malloc(sizeof(t_attribs) * 1);
	new->precision = 0;
	new->prec_is_dot = 0;
	new->width = 0;
	new->padding = 0;
	new->prefix = 0;
	new->pos_prefix = 0;
	new->blank = 0;
	new->negative = 1;
	return (new);
}
