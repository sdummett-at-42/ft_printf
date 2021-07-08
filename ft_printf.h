/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:21:59 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/08 18:32:27 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

/*
 * -> Checker les printfs (grep) et return (-1) en cas de malloc failed.
*/

typedef struct s_attribs
{
	int	precision;
	int	prec_is_dot;
	int	width;
	int	padding;
	int	prefix;
	int	pos_prefix;
	int	blank;
	int	negative;
}		t_attribs;

int			ft_printf(const char *fmt, ...)
			__attribute__((format (printf, 1, 2)));
int			check_specifier(char **fmt, va_list var);
int			search_specifier(char **fmt);

void		call_handler(int handler_choice, char **fmt, va_list var, \
		int *ptf_ret);

void		percent_printer(char **fmt, va_list var, int *ptf_ret);
void		c_printer(char **fmt, va_list var, int *ptf_ret);
void		s_printer(char **fmt, va_list var, int *ptf_ret);
void		p_printer(char **fmt, va_list var, int *ptf_ret);
void		d_i_printer(char **fmt, va_list var, int *ptf_ret);
void		u_printer(char **fmt, va_list var, int *ptf_ret);
void		lower_x_printer(char **fmt, va_list var, int *ptf_ret);
void		upper_x_printer(char **fmt, va_list var, int *ptf_ret);

char		*ft_uitoa(unsigned int n);
void		count_and_display(char **fmt, char *str, char c, int *ptf_ret);
char		*uitohex_low(unsigned long nb);
char		*uitohex_up(unsigned long nb);
char		*check_if_eq_zero(char *str, int dot);
char		*precision_handler(char *str, int precision);
char		*width_handler(char *str, int width);
char		*padding_handler(char *str, int padding, int precision, int dot);
void		integer_handler(char **fmt, va_list var, int *ptf_ret);
t_attribs	*struct_init(void);
t_attribs	*fmt_parser(char **fmt, va_list var);
char		*prefix_handler(char *str, char spec);
char		*sharp_hexa_pad(char *str, int padding, int len);
void		prec_parsing(t_attribs *flag, char **fmt, va_list var, int *i);
void		padding_parsing(t_attribs *flag, char **fmt, va_list var, int *i);
void		pos_prefix_parsing(t_attribs *flag, char **fmt, int *i);
void		prefix_parsing(t_attribs *flag, char **fmt, int *i);
void		blank_parsing(t_attribs *flag, char **fmt, int *i);

#endif
