/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/12/16 18:37:32 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	allowed_char(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (
				!(so_long->map[i][j] == '1' || so_long->map[i][j] == '0'
				|| so_long->map[i][j] == 'C' || so_long->map[i][j] == 'M'
				|| so_long->map[i][j] == 'P' || so_long->map[i][j] == 'E'
				|| so_long->map[i][j] == '*'
				|| (j == so_long->game_width - 1 && so_long->map[i][j] == '\n'))
			)
				return (0);
			if (j == so_long->game_width -1 && so_long->map[i][j] != '\n' )
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	required_char(t_so_long *so_long)
{
	int		i;
	int		j;
	int		elements[3];

	i = 0;
	ft_memset(elements, 0, sizeof(elements));
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'C')
				elements[0]++;
			else if (so_long->map[i][j] == 'P')
				elements[1]++;
			else if (so_long->map[i][j] == 'E')
				elements[2]++;
			j++;
		}
		i++;
	}
	if (elements[0] < 1 || elements[1] < 1 || elements[2] < 1)
		return (0);
	so_long->collectable_count = elements[0];
	return (1);
}

int	sides_is_wall(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j] && i < so_long->game_height &&
		j < so_long->game_width - 1)
		{
			if (i == 0 || i + 1 == so_long->game_height)
				if (so_long->map[i][j] != '1')
					return (0);
			if (j == 0 || j + 2 == so_long->game_width)
				if (so_long->map[i][j] != '1')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}
