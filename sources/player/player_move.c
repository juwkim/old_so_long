/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:45:01 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 04:34:31 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player/player_move.h"

// Player move in horizontal axis
void	player_move_horizontal(t_player p, char *map[])
{
	t_player	*p;

	p = &game->player;
	if (p->action_code[0] == 2)
		p->position.first += get_prwc(game);
	else if (p->action_code[0] == 1)
		p->position.first -= get_plwc(game);
}

// Player move in vertical axis
void	player_move_vertical(t_player p, char *map[])
{
	t_player	*p;

	p = &game->player;
	if (p->action_code[0] == 3)
		p->position.second -= get_pjwc(game);
	else if (p->action_code[0] == 4)
		p->position.second += get_pdwc(game);
}

// Player move in diagonal
void	player_move_diagonal(t_player p, char *map[])
{
	t_player *const	p = &game->player;

	if ((((p->action_code[0] == 10 && p->action_code[1] == 1) || \
		(p->action_code[0] == 1 && p->action_code[1] == 10)) || \
		((p->action_code[0] == 10 && p->action_code[1] == 2) || \
		(p->action_code[0] == 2 && p->action_code[1] == 10))
		) && get_pgwc(game) == 0)
	{
		p->jump = 10;
		if (p->action_code[1] == 1)
			p->di = 1;
		else if (p->action_code[1] == 2)
			p->di = 2;
	}
	if (p->jump > 0 && p->di > 0)
	{
		p->position.first -= get_pjwc(game);
		if (p->di == 2)
			p->position.first += get_prwc(game) / 2;
		else if (p->di == 1)
			p->position.first -= get_plwc(game) / 2;
		p->jump--;
		if (p->jump == 0)
			p->di = 0;
	}
}

void	player_jump(t_player p, char *map[])
{
	const t_player	*p = &game->player;

	if ((p->action_code[0] == 10 \
		|| p->action_code[1] == 10) && p->jump == 0 && \
		get_pgwc(game) == 0)
		p->jump = 10;
	else if (p->jump > 0 && p->diagonal == 0)
	{
		p->position.second -= get_pjwc(game);
		p->jump--;
	}
}

void	player_gravity(t_player p, char *map[])
{
	if ((p->action_code[0] != 4) && p->jump == 0)
		p->position.second += get_pgwc(game);
}