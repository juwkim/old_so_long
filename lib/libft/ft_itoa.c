/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:27:03 by juwkim            #+#    #+#             */
/*   Updated: 2022/08/29 04:27:05 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = 1 + (~n);
	}
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*buf;
	long long	num;
	int			len;
	int			end;

	num = (long long)n;
	len = ft_intlen(num);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	buf[len] = '\0';
	end = 0;
	if (num < 0)
	{
		end = 1;
		buf[0] = '-';
		num *= -1;
	}
	while (--len >= end)
	{
		buf[len] = num % 10 + '0';
		num /= 10;
	}
	return (buf);
}
