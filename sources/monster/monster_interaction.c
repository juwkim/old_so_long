/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_interaction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:42:05 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 13:42:09 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	monster_player_action(t_monster *m, t_game *game)
{
	if (game->player.a[0] > m->a[0])
		game->player.direction = 0;
	else
		game->player.direction = 1;
	game->player.tick_life = 50;
	m->td = 15;
	m->alive = 0;
}

static void	monster_action(t_monster *m, t_game *game)
{
	m->move = 0;
	game->player.tick_life--;
	if (m->ta > 0)
		m->ta--;
	if (m->td > 0)
		m->td--;
	if (game->player.life_number < 1)
	{
		mlx_destroy_window(game->mlx, game->window);
		ft_printf("You loose the game !\n");
		exit(EXIT_SUCCESS);
	}
	if (game->player.tick_life < 1)
	{
		ft_printf("You loose 1 life !\n");
		game->player.tick_life = 50;
		game->player.life_number--;
		m->ta = 20;
	}
	else if (game->player.action_code[2] == 5)
		monster_player_action(m, game);
}

void	monster_interaction(t_game *game)
{
	t_list		*lst;
	t_monster	*m;
	t_player	*p;

	lst = game->monsters;
	while (lst)
	{
		m = ((t_monster *)lst->content);
		p = &game->player;
		if ((((p->a[0] > m->a[0] && p->a[0] < m->c[0]) || \
			(p->c[0] > m->a[0] && p->c[0] < m->c[0])) && \
			p->a[1] < m->b[1] && p->b[1] > m->a[1]) && \
			(m->alive == 1 || m->td > 0))
		{
			if (m->a[0] > p->a[0])
				m->direction = 0;
			else
				m->direction = 1;
			monster_action(m, game);
		}
		else
			m->move = 1;
		lst = lst->next;
	}
}
