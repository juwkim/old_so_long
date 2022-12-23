/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:07:47 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 14:59:28 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_strin(char c, const char *str)
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
