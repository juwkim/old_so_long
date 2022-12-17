/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 02:03:51 by juwkim            #+#    #+#             */
/*   Updated: 2022/08/29 02:04:16 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buf;

	buf = (void *)malloc(nmemb * size);
	if (buf == NULL)
		return (NULL);
	ft_bzero(buf, nmemb * size);
	return (buf);
}
