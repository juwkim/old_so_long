/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 06:31:59 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 03:58:09 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monster/monster_action.h"

void	monster_move(t_monster *monster, char *map[])
{
	const int	right_dist = get_right_dist(&monster->position, map);
	const int	left_dist = get_left_dist(&monster->position, map);

	monster->move = (monster->move + 1) % MONSTER_MOVE_COUNT;
	if (monster->move_horizontal == MOVE_RIGHT)
		monster->position.first += right_dist / 2;
	else if (monster->move_horizontal == MOVE_LEFT)
		monster->position.first -= left_dist / 2;
	if (monster->move == 0 || (monster->move > MONSTER_MOVE_COUNT * 9 / 10 \
		&& (right_dist == 0 || left_dist == 0)))
	{
		monster->move = MONSTER_MOVE_COUNT;
		monster->move_horizontal ^= 1;
	}
	monster->position.second += get_down_dist(&monster->position, map);
}

void	monster_collision(t_game *game, t_monster *monster)
{
	const int		p_y = game->player.position.first + BLOCK_SIZE / 2;
	const int		p_x = game->player.position.second + BLOCK_SIZE / 2;
	const int		m_y = monster->position.first + BLOCK_SIZE / 2;
	const int		m_x = monster->position.second + BLOCK_SIZE / 2;

	monster->hited = ft_max(monster->hited - 1, 0);
	if (monster->hited == 0 && \
	ft_abs(p_x - m_x) < COLLISION_HIT && \
	ft_abs(p_y - m_y) < COLLISION_HIT)
	{
		--game->player.life_number;
		monster->hited = NO_HIT_COUNT;
	}
}
