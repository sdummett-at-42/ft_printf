/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:21:45 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/20 18:02:27 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list list;
	va_start(list, format);
	
	//int k = va_arg(list, int);
	//printf(" %d\n", k);
	//printf("%d\n", va_arg(list, int));
	//printf("%d\n", va_arg(list, int));
	printf("%d\n", 22);
	va_end(list);	
	return 0;
}

int main()
{

	ft_printf("", 55);
	return (0);
}
