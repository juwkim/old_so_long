/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:45:01 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 02:49:35 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	move_count_update(t_game *game)
{
	if (game->player.lpp.first != game->player.position.first || \
		game->player.lpp.second != game->player.position.second)
		game->move_count++;
}

// Player move in horizontal axis
void	player_move_y(t_game *game)
{
	t_player	*p;

	p = &game->player;
	if (p->action_code[0] == 2)
		p->position.first += get_prwc(game);
	else if (p->action_code[0] == 1)
		p->position.first -= get_plwc(game);
}

// Player move in vertical axis
void	player_move_z(t_game *game)
{
	t_player	*p;

	p = &game->player;
	if (p->action_code[0] == 3)
		p->position.second -= get_pjwc(game);
	else if (p->action_code[0] == 4)
		p->position.second += get_pdwc(game);
}

// Player move in diagonal
void	player_move_d(t_game *game)
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

// Player jump in vertical axis
void	player_jump(t_game *game)
{
	t_player	*p;

	p = &(game->player);
	if ((p->action_code[0] == 10 \
		|| p->action_code[1] == 10) && p->jump == 0 && \
		get_pgwc(game) == 0)
		p->jump = 10;
	else if (p->jump > 0 && p->di == 0)
	{
		p->position.second -= get_pjwc(game);
		p->jump--;
	}
}
