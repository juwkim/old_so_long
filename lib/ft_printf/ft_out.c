/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 06:31:19 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/16 19:58:08 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(char c, t_opt *opt)
{
	int	printed;

	printed = 0;
	if (!opt->left)
		while (opt->width-- > 1)
			printed += write(1, " ", 1);
	printed += write(1, &c, 1);
	while (opt->width-- > 1)
		printed += write(1, " ", 1);
	return (printed);
}

int	ft_print_string(const char *s, t_opt *opt)
{
	int	len;
	int	printed;

	printed = 0;
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (opt->dot && len > opt->prec)
		len = opt->prec;
	if (!opt->left)
		while (len < opt->width--)
			printed += write(1, " ", 1);
	printed += write(1, s, len);
	while (len < opt->width--)
		printed += write(1, " ", 1);
	return (printed);
}

int	ft_print_address(unsigned long num, t_opt *opt)
{
	int			printed;
	char		buf[16];
	const int	len = _ft_itoa(buf, num, 16, 32);

	printed = 0;
	opt->width -= 2 + len;
	if (!opt->left)
		while (opt->width-- > 0)
			printed += write(1, " ", 1);
	printed += write(1, "0x", 2) + write(1, buf, len);
	while (opt->width-- > 0)
		printed += write(1, " ", 1);
	return (printed);
}

int	ft_print_unsigned(unsigned long num, t_opt *opt, int base, int lower)
{
	int			i;
	int			printed;
	char		buf[32];
	const int	len = _ft_itoa(buf, num, base, lower);

	printed = 0;
	opt->width -= (num && opt->special) << 1;
	opt->width -= max(len, opt->prec) * (num || !opt->dot || opt->prec);
	if (!opt->left && (opt->dot || !opt->zeropad))
		while (opt->width-- > 0)
			printed += write(1, " ", 1);
	i = 'X' | lower;
	if (num && opt->special)
		printed += write(1, "0", 1) + write(1, &i, 1);
	if (!opt->left)
		while (opt->width-- > 0)
			printed += write(1, &opt->zeropad_char, 1);
	i = max(len, opt->prec);
	while (len < i--)
		printed += write(1, "0", 1);
	if (num || !opt->dot || opt->prec)
		printed += write(1, buf, len);
	while (opt->width-- > 0)
		printed += write(1, " ", 1);
	return (printed);
}

int	ft_print_signed(long num, t_opt *opt)
{
	int		i;
	int		len;
	int		printed;
	char	buf[32];

	printed = 0;
	ft_set_sign(&num, opt);
	len = _ft_itoa(buf, num, 10, 0);
	opt->width -= max(len, opt->prec) * (num || !opt->dot || opt->prec);
	if (!opt->left && (opt->dot || !opt->zeropad))
		while (opt->width-- > 0)
			printed += write(1, " ", 1);
	if (opt->sign_char)
		printed += write(1, &opt->sign_char, 1);
	if (!opt->left)
		while (opt->width-- > 0)
			printed += write(1, &opt->zeropad_char, 1);
	i = max(len, opt->prec);
	while (len < i--)
		printed += write(1, "0", 1);
	if (num || !opt->dot || opt->prec)
		printed += write(1, buf, len);
	while (opt->width-- > 0)
		printed += write(1, " ", 1);
	return (printed);
}
