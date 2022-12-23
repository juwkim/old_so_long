/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:42:52 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 16:48:12 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monster/monster.h"

// Analyzes the map and creates as many monsters as there are 'M' in the map
void	analyse_monster(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->game_height)
	{
		j = 0;
		while (j < so_long->game_width)
		{
			if (so_long->map[i][j] == 'M')
				create_monster(i, j, so_long);
			j++;
		}
		i++;
	}
}

// Create monsters in a linked list
void	create_monster(int i, int j, t_so_long *so_long)
{
	t_monster	*m;

	m = ft_calloc(sizeof(t_monster), 1);
	if (m == NULL)
		exit(EXIT_FAILURE);
	m->pp[0] = j * BPX;
	m->pp[1] = i * BPX;
	m->init_p[0] = m->pp[0];
	m->init_p[1] = m->pp[1];
	m->alive = 1;
	m->direction = 1;
	m->move = 1;
	m->ai = 0;
	m->td = 0;
	if (so_long->monsters == NULL)
		so_long->monsters = ft_lstnew(m);
	else
		ft_lstadd_front(&so_long->monsters, ft_lstnew(m));
}

// Displays a monster block
void	draw_monster(t_so_long *so_long)
{
	t_list		*lst;
	t_monster	*m;

	lst = so_long->monsters;
	while (lst)
	{
		m = (t_monster *)lst->content;
		if (m->alive == 1 || m->td > 0)
			draw_block(m->pp[0] + so_long->window_offset.first,
				m->pp[1] + so_long->window_offset.second,
				get_monster_sprite(m, so_long), so_long);
		lst = lst->next;
	}
}

// Meta function for monster
void	monster(t_so_long *so_long)
{
	monster_move(so_long);
	monster_interaction(so_long);
	draw_monster(so_long);
}
