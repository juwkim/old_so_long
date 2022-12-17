/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:53:25 by juwkim            #+#    #+#             */
/*   Updated: 2022/08/29 04:53:26 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	const size_t	find_len = ft_strlen(to_find);

	if (!find_len)
		return ((char *)str);
	while (*str && n-- >= find_len)
	{
		if (*str == *to_find && !ft_memcmp(str, to_find, find_len))
			return ((char *)str);
		str++;
	}
	return (NULL);
}
