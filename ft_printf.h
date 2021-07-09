/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:21:59 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/09 23:22:26 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

/*
 *	Structure for the result of the format parsing on a specifier. 
*/

typedef struct s_attribs
{
	int	precision;
	int	prec_is_zero;
	int	width;
	int	padding;
	int	prefix;
	int	plus_prefix;
	int	blank;
	int	negative;
}		t_attribs;

/*
 *	Ft_printf prototype.
*/

int			ft_printf(const char *fmt, ...)
			__attribute__((format (printf, 1, 2)));

/*
 *	Functions that will parse *fmt in order to find flags (0, -, field
 *	width, *, ., #, +, ' ').
 *	Note: field width => a number, can be replace by a '*' and instead given
 *	as an argument of type int.
*/

t_attribs	*fmt_parser(char **fmt, va_list var);
t_attribs	*struct_init(void);
void		sharp_parsing(t_attribs *flag, char **fmt, int *i);
void		zero_parsing(t_attribs *flag, char **fmt, va_list var, int *i);
void		dot_parsing(t_attribs *flag, char **fmt, va_list var, int *i);
void		blank_parsing(t_attribs *flag, char **fmt, int *i);
void		plus_parsing(t_attribs *flag, char **fmt, int *i);
int			check_specifier(char **fmt, va_list var);
int			search_specifier(char **fmt);
void		call_printer(int handler_choice, char **fmt, va_list var, \
		int *ptf_ret);

/*
 *	Functions that will transform a string.
*/

char		*precision_conversion(char *str, int precision);
char		*width_conversion(char *str, int width);
char		*padding_conversion(char *str, int padding, int precision, int dot);
char		*x_prefix_conversion(char *str, char spec);
char		*x_prefix_padding(char *str, int padding, int len);
char		*check_if_eq_zero(char *str, int dot);

/*
 *	Functions that will print each type of conversion (c, s, p, d, i, u,
 *	x, X, %).
*/

void		c_printer(char **fmt, va_list var, int *ptf_ret);
void		s_printer(char **fmt, va_list var, int *ptf_ret);
void		p_printer(char **fmt, va_list var, int *ptf_ret);
void		d_i_printer(char **fmt, va_list var, int *ptf_ret);
void		u_printer(char **fmt, va_list var, int *ptf_ret);
void		lower_x_printer(char **fmt, va_list var, int *ptf_ret);
void		upper_x_printer(char **fmt, va_list var, int *ptf_ret);
void		percent_printer(char **fmt, va_list var, int *ptf_ret);
void		count_and_print(char **fmt, char *str, char c, int *ptf_ret);

/*
 *	Some other useful functions.
*/

char		*uitoa(unsigned int n);
char		*uitohex_low(unsigned long nb);
char		*uitohex_up(unsigned long nb);

#endif
