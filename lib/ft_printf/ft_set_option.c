/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 06:12:51 by juwkim            #+#    #+#             */
/*   Updated: 2022/10/12 18:39:06 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_flags(const char **fmt, t_opt *opt)
{
	while (1)
	{
		(*fmt)++;
		if (**fmt == '-')
			opt->left = 1;
		else if (**fmt == '+')
			opt->plus = 1;
		else if (**fmt == ' ')
			opt->space = 1;
		else if (**fmt == '#')
			opt->special = 1;
		else if (**fmt == '0')
		{
			opt->zeropad = 1;
			opt->zeropad_char = '0';
		}
		else
			return ;
	}
}

int	ft_get_width(const char **fmt)
{
	int	width;

	width = 0;
	if ('0' <= **fmt && **fmt <= '9')
		width = ft_skip_atoi(fmt);
	return (width);
}

void	ft_set_prec(const char **fmt, t_opt *opt)
{
	opt->prec = 0;
	opt->dot = 0;
	if (**fmt == '.')
	{
		(*fmt)++;
		opt->dot = 1;
		if ('0' <= **fmt && **fmt <= '9')
			opt->prec = ft_skip_atoi(fmt);
	}
}

void	ft_init_opt(const char **fmt, t_opt *opt)
{
	opt->zeropad = 0;
	opt->zeropad_char = ' ';
	opt->plus = 0;
	opt->space = 0;
	opt->left = 0;
	opt->special = 0;
	ft_set_flags(fmt, opt);
	opt->width = ft_get_width(fmt);
	ft_set_prec(fmt, opt);
}

void	ft_set_sign(long *num, t_opt *opt)
{
	opt->sign_char = 0;
	if (*num < 0)
	{
		opt->sign_char = '-';
		*num *= -1;
		opt->width--;
	}
	else if (opt->plus)
	{
		opt->sign_char = '+';
		opt->width--;
	}
	else if (opt->space)
	{
		opt->sign_char = ' ';
		opt->width--;
	}
}
