/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:21:45 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/21 20:24:38 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int	ft_printf(int nb_arg, const char *format, ...)
{
	va_list list;
	va_start(list, format);
	
	//int k = va_arg(list, int);
	//printf(" %d\n", k);
	//printf("%d\n", va_arg(list, int));
	//printf("%d\n", va_arg(list, int));
	while (nb_arg != 0)
	{
		printf("%d\n", va_arg(list, int));
		nb_arg--;
	}
	//printf("%d\n", 22);
	va_end(list);	
	return 0;
}

int main()
{

	//ft_printf(42, "", 42, 41,40,39,38);
	printf(">> %%0100d     : ||%0100d||\n", 42);
	printf(">> %%0*d       : ||%0*d||\n", 100, 42);
	printf(">> %%100d      : ||%100d||\n", 42);
	printf(">> %%*d        : ||%*d||\n", 100, 42);
	printf(">> %%-100d     : ||%-100d||\n", 42);
	printf(">> %%-*d       : ||%-*d||\n", 100, 42);
	printf(">> %%.100d     : ||%100.d||\n", 42);
	printf(">> %%x         : ||%x||\n", 16);
	
	return (0);
}
