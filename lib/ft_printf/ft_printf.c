/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 05:17:58 by juwkim            #+#    #+#             */
/*   Updated: 2022/10/12 19:02:10 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_args(char c, va_list args, t_opt *opt)
{
	int	printed;

	printed = 0;
	if (c == '%')
		printed += ft_print_c('%', opt);
	else if (c == 'c')
		printed += ft_print_c(va_arg(args, int), opt);
	else if (c == 's')
		printed += ft_print_string(va_arg(args, char *), opt);
	else if (c == 'p')
		printed += ft_print_address(va_arg(args, unsigned long), opt);
	else if (c == 'x')
		printed += ft_print_unsigned(va_arg(args, unsigned), opt, 16, 32);
	else if (c == 'X')
		printed += ft_print_unsigned(va_arg(args, unsigned), opt, 16, 0);
	else if (c == 'u')
		printed += ft_print_unsigned(va_arg(args, unsigned), opt, 10, 0);
	else if (c == 'd' || c == 'i')
		printed += ft_print_signed(va_arg(args, int), opt);
	return (printed);
}

int	ft_vprintf(const char *fmt, va_list args)
{
	t_opt	opt;
	int		printed;
	int		len;

	printed = 0;
	len = 0;
	while (*fmt)
	{
		if (*fmt != '%')
		{
			len++;
			fmt++;
			continue ;
		}
		printed += write(1, fmt - len, len);
		len = 0;
		ft_init_opt(&fmt, &opt);
		printed += ft_print_args(*fmt, args, &opt);
		fmt++;
	}
	printed += write(1, fmt - len, len);
	return (printed);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		printed;

	if (fmt == NULL)
		return (-1);
	va_start(args, fmt);
	printed = ft_vprintf(fmt, args);
	va_end(args);
	return (printed);
}
