/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:42:14 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 13:42:20 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	monster_move_dir(t_monster *m, t_game *game)
{
	int			dist;

	if (m->mi > 4)
	{
		m->mi = 0;
		if (m->direction == 1)
		{
			dist = get_mrwc(m, game);
			m->pp[0] = m->pp[0] + dist;
			if (m->pp[0] > m->init_p[0] + (BPX * 2) || dist == 0)
				m->direction = 0;
		}
		else
		{
			dist = get_mlwc(m, game);
			m->pp[0] = m->pp[0] - dist;
			if (m->pp[0] < m->init_p[0] - (BPX * 2) || dist == 0)
				m->direction = 1;
		}
	}
	m->mi++;
}

void	monster_move(t_game *game)
{
	t_list		*lst;
	t_monster	*m;

	lst = game->monsters;
	while (lst)
	{
		m = ((t_monster *)lst->content);
		monster_position(m);
		if (m->move == 1)
			monster_move_dir(m, game);
		lst = lst->next;
	}
}
