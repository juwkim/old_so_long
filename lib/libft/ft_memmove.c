/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:42:26 by juwkim            #+#    #+#             */
/*   Updated: 2022/08/29 04:45:29 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*s = src;
	unsigned char		*d;

	d = dst;
	if (d < s)
		while (len--)
			*d++ = *s++;
	else if (d > s)
		while (len--)
			d[len] = s[len];
	return (dst);
}
