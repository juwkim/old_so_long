/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 05:18:12 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 13:51:07 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "common/libft.h"

typedef struct s_opt
{
	int		width;
	int		prec;
	char	zeropad_char;
	char	sign_char;
	char	zeropad	: 1;
	char	plus	: 1;
	char	space	: 1;
	char	left	: 1;
	char	special	: 1;
	char	dot		: 1;
}	t_opt;

int		ft_skip_atoi(const char **s);
int		_ft_itoa(char *buf, unsigned long num, int base, int lower);
void	reverse(char *buf, char *end);
int		max(int a, int b);

void	ft_set_flags(const char **fmt, t_opt *opt);
int		ft_get_width(const char **fmt);
void	ft_set_prec(const char **fmt, t_opt *opt);
void	ft_init_opt(const char **fmt, t_opt *opt);
void	ft_set_sign(long *num, t_opt *opt);

int		ft_print_c(char c, t_opt *opt);
int		ft_print_string(const char *s, t_opt *opt);
int		ft_print_address(unsigned long num, t_opt *opt);
int		ft_print_unsigned(unsigned long num, t_opt *opt, int base, int lower);
int		ft_print_signed(long num, t_opt *opt);

int		ft_print_args(char c, va_list args, t_opt *opt);
int		ft_vprintf(const char *fmt, va_list args);
int		ft_printf(const char *format, ...);
#endif