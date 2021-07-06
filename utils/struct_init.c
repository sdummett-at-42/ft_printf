/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:27:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/06 18:17:12 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flag_attribs	*struct_init(void)
{
	t_flag_attribs	*new;

	new = (t_flag_attribs *)malloc(sizeof(t_flag_attribs) * 1);
	new->precision = 0;
	new->prec_is_dot = 0;
	new->width = 0;
	new->padding = 0;
	new->negative = 1;
	return (new);
}
