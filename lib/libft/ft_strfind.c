/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:45:56 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 13:52:39 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strfind(char c, const char *str)
{
	int			idx;
	const int	end = ft_strlen(str);

	idx = 0;
	while (idx < end)
	{
		if (str[idx] == c)
			return (idx);
		++idx;
	}
	return (-1);
}
