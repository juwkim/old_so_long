/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:41:23 by juwkim            #+#    #+#             */
/*   Updated: 2022/08/29 04:42:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*add;

	if (!n || dest == src)
		return (dest);
	add = dest;
	while (n--)
		*(unsigned char *)add++ = *(unsigned char *)src++;
	return (dest);
}
