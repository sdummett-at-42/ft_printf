/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:21:59 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/02 01:11:57 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

/////////// TEMP /////////// 

#include <stdio.h>

//////////////////////////// 

/*
 * CHEECKER LES PRINTFS AVANT LE PUSH FINAL !
*/

/////////// MYF FUNC ///////

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
void	ft_putaddr(void *addr);
void	ft_putstr(char *str);
void	ft_putnbr(long long int nb);
void	ft_puthex_low(long int nb);
void	ft_puthex_up(long int nb);
void	ft_putpercent(void);
int		check_specifier(char **format, va_list var);
int		search_specifier(char **format);
void	call_handler(int handler_choice, char **format, va_list var);
void	char_handler(char **format, va_list var);
void	str_handler(char **format, va_list var);
void	pointer_handler(char **format, va_list var);
void	integer_handler(char ** format, va_list var);
void	u_integer_handler(char **format, va_list var);
char	*ft_uitoa(unsigned int n);

//////////////////////////// 

typedef struct s_flag_attribs
{
	int precision;
	int width;
	int zero;
}		t_flag_attribs;

#include "libft/libft.h"
#include <stdarg.h>

#endif
