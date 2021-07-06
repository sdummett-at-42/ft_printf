/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:21:59 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/06 19:35:20 by sdummett         ###   ########.fr       */
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
// PROTEGER LES MALLOCS !
/////////// MYF FUNC ///////

typedef struct s_flag_attribs
{
	int precision;
	int prec_is_dot;
	int width;
	int padding;
	int negative;
}		t_flag_attribs;

int        ft_printf(const char *format, ...)
        __attribute__((format (printf, 1, 2)));
void	ft_putchar(char c);
void	ft_putaddr(void *addr);
void	ft_putstr(char *str);
void	ft_putnbr(long long int nb);
void	ft_puthex_low(long int nb);
void	ft_puthex_up(long int nb);
int		check_specifier(char **format, va_list var);
int		search_specifier(char **format);
void	call_handler(int handler_choice, char **format, va_list var, int *ptf_ret);
void	percent_handler(char **format, va_list var, int *ptf_ret);
void	char_handler(char **format, va_list var, int *ptf_ret);
void	str_handler(char **format, va_list var, int *ptf_ret);
void	pointer_handler(char **format, va_list var, int *ptf_ret);
void	integer_handler(char ** format, va_list var, int *ptf_ret);
void	u_integer_handler(char **format, va_list var, int *ptf_ret);
void	hexalow_handler(char **format, va_list var, int *ptf_ret);
void	hexaup_handler(char **format, va_list var, int *ptf_ret);
char	*ft_uitoa(unsigned int n);
void count_and_display(char **format, char *str, char c, int *ptf_ret);
char	*uitohex_low(unsigned long nb);
char	*uitohex_up(unsigned long nb);
char	*check_if_eq_zero(char *str, int dot);
char	*precision_handler(char *str, int precision);
char	*width_handler(char *str, int width);
char	*padding_handler(char *str, int padding, int precision, int dot);
void	integer_handler(char **format, va_list var, int *ptf_ret);
t_flag_attribs	*struct_init(void);
t_flag_attribs	*format_parser(char **format, va_list);

//////////////////////////// 


#include "libft/libft.h"
#include <stdarg.h>

#endif
