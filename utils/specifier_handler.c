/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 23:10:31 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/30 04:10:29 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	call_handler(int handler_choice, char **format, va_list var)
{
	if (handler_choice == 1)
	{
		char_handler(format, var);
/*		ft_putchar(va_arg(var, int));
*/
	}
	else if (handler_choice == 2)
	{
		str_handler(format, var);
/*		ft_putstr(va_arg(var, char *));
*/		
	}
	else if (handler_choice == 3)
	{
		pointer_handler(format, var);
/*		ft_putaddr(va_arg(var, void *));
*/	
	}	
	else if (handler_choice == 4)
		ft_putnbr(va_arg(var, int));
	else if (handler_choice == 5)
		ft_putnbr(va_arg(var, unsigned int));
	else if (handler_choice == 6)
		ft_puthex_low(va_arg(var, int)); // UP ???
	else if (handler_choice == 7)
		ft_putpercent();
}

/*
 *	1 : %c
 *	2 : %s
 *	3 : %p
 *	4 : %d - %i
 *	5 : %u
 *	6 : %x - %X
 *	7 : %%
*/

int	search_specifier(char **format)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while ((*format)[i] != '\0')
	{
		if ((*format)[i] == 'c')
			ret = 1;
		else if ((*format)[i] == 's')
			ret = 2;
		else if ((*format)[i] == 'p')
			ret = 3;
		else if ((*format)[i] == 'd' || (*format)[i] == 'i')
			ret = 4;
		else if ((*format)[i] == 'u')
			ret = 5;
		else if ((*format)[i] == 'x' || (*format)[i] == 'X')
			ret = 6;
		else if ((*format)[i] == '%')
			ret = 7;
		else
			i++;
		if (ret != 0)
			break ;
	}
	return (ret);
}

/*
 *	Main test for this function (search_specifier)
 *	OK !
*/

/*
int main()
{
	int i;
	char *format = "%vfc    %vvs %    p % f f  d %    i % u %nnx %       l  X %l%";

	i = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			printf("specifier = %d\n", search_specifier(&format));
		}
		else
			format++;
	}
	return (0);
}
*/
