/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:42:37 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 02:58:42 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monster/monster_image.h"

int	get_monster_image_idx(t_monster *monster)
{
	int	idx;

	if (monster->move_horizontal == MOVE_RIGHT)
	{
		if (monster->image_idx > 10)
			idx = 0;
		else
			idx = (monster->image_idx + 1) % 11;
	}
	else
	{
		if (monster->image_idx <= 10)
			idx = 11;
		else
		{
			idx = monster->image_idx + 1;
			if (idx == 22)
				idx = 11;
		}
	}
	return (idx);
}

int	*get_monster_image(t_game *game, t_monster *monster)
{
	monster->image_update = (monster->image_update + 1) % UPDATE_CYCLE;
	if (monster->image_update == 0)
		monster->image_idx = get_monster_image_idx(monster);
	return (game->image[MONSTER][monster->image_idx]);
}
