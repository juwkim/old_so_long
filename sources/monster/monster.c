/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:42:52 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 17:09:10 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monster/monster.h"

// Analyzes the map and creates as many monsters as there are 'M' in the map
void	set_monster(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == '0')
			{
				count++;
				if (count == MOSTER_FREQUENCY)
				{
					new_monster(game, i, j);
					count = 0;
				}
			}
			j++;
		}
		i++;
	}
}

void	new_monster(t_game *game, int i, int j)
{
	t_monster *const	m = ft_calloc(sizeof(t_monster), 1);

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
	if (game->monsters == NULL)
		game->monsters = ft_lstnew(m);
	else
		ft_lstadd_front(&game->monsters, ft_lstnew(m));
}

// Displays a monster block
void	draw_monster(t_game *game)
{
	t_list		*lst;
	t_monster	*m;

	lst = game->monsters;
	while (lst)
	{
		m = (t_monster *)lst->content;
		if (m->alive == 1 || m->td > 0)
			draw_block(m->pp[0] + game->offset_window.first,
				m->pp[1] + game->offset_window.second,
				get_monster_sprite(m, game), game);
		lst = lst->next;
	}
}

// Meta function for monster
void	monster(t_game *game)
{
	monster_move(game);
	monster_interaction(game);
	draw_monster(game);
}
