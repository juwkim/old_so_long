/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:52:26 by juwkim            #+#    #+#             */
/*   Updated: 2022/08/29 04:52:27 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	const size_t	s = ft_strlen(src);

	if (size)
	{
		while (*src && --size)
			*dest++ = *src++;
		*dest = '\0';
	}
	return (s);
}
