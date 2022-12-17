/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:50:12 by juwkim            #+#    #+#             */
/*   Updated: 2022/08/29 04:50:32 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*buf;
	const size_t	len = ft_strlen(s);

	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	ft_strlcpy(buf, s, len + 1);
	return (buf);
}
