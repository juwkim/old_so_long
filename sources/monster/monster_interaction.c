/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_interaction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/12/16 17:42:19 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	monster_player_action(t_monster *m, t_so_long *so_long)
{
	if (so_long->player.a[0] > m->a[0])
		so_long->player.direction = 0;
	else
		so_long->player.direction = 1;
	so_long->player.tick_life = 50;
	m->td = 15;
	m->alive = 0;
}

static void	monster_action(t_monster *m, t_so_long *so_long)
{
	m->move = 0;
	so_long->player.tick_life--;
	if (m->ta > 0)
		m->ta--;
	if (m->td > 0)
		m->td--;
	if (so_long->player.life_number < 1)
	{
		mlx_destroy_window(so_long->mlx, so_long->window);
		ft_printf("You loose the game !\n");
		exit(EXIT_SUCCESS);
	}
	if (so_long->player.tick_life < 1)
	{
		ft_printf("You loose 1 life !\n");
		so_long->player.tick_life = 50;
		so_long->player.life_number--;
		m->ta = 20;
	}
	else if (so_long->player.action_code[2] == 5)
		monster_player_action(m, so_long);
}

void	monster_interaction(t_so_long *so_long)
{
	t_list		*lst;
	t_monster	*m;
	t_player	*p;

	lst = so_long->monsters;
	while (lst)
	{
		m = ((t_monster *)lst->content);
		p = &so_long->player;
		if ((((p->a[0] > m->a[0] && p->a[0] < m->c[0]) || \
			(p->c[0] > m->a[0] && p->c[0] < m->c[0])) && \
			p->a[1] < m->b[1] && p->b[1] > m->a[1]) && \
			(m->alive == 1 || m->td > 0))
		{
			if (m->a[0] > p->a[0])
				m->direction = 0;
			else
				m->direction = 1;
			monster_action(m, so_long);
		}
		else
			m->move = 1;
		lst = lst->next;
	}
}
