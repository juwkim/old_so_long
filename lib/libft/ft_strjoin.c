/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:50:56 by juwkim            #+#    #+#             */
/*   Updated: 2022/08/29 04:50:58 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	s1_size;
	size_t	s2_size;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	buf = (char *)malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (!buf)
		return (NULL);
	ft_strlcpy(buf, s1, s1_size + 1);
	ft_strlcpy(buf + s1_size, s2, s2_size + 1);
	return (buf);
}
