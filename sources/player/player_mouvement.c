/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/12/16 18:34:30 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Player move in horizontal axis
void	player_move_y(t_so_long *so_long)
{
	t_player	*p;

	p = &so_long->player;
	if (p->action_code[0] == 2)
		p->position.first += get_prwc(so_long);
	else if (p->action_code[0] == 1)
		p->position.first -= get_plwc(so_long);
}

// Player move in vertical axis
void	player_move_z(t_so_long *so_long)
{
	t_player	*p;

	p = &so_long->player;
	if (p->action_code[0] == 3)
		p->position.second -= get_pjwc(so_long);
	else if (p->action_code[0] == 4)
		p->position.second += get_pdwc(so_long);
}

// Player move in diagonal
void	player_move_d(t_so_long *so_long)
{
	t_player *const	p = &so_long->player;

	if ((((p->action_code[0] == 10 && p->action_code[1] == 1) || \
		(p->action_code[0] == 1 && p->action_code[1] == 10)) || \
		((p->action_code[0] == 10 && p->action_code[1] == 2) || \
		(p->action_code[0] == 2 && p->action_code[1] == 10))
		) && get_pgwc(so_long) == 0)
	{
		p->jump = 10;
		if (p->action_code[1] == 1)
			p->di = 1;
		else if (p->action_code[1] == 2)
			p->di = 2;
	}
	if (p->jump > 0 && p->di > 0)
	{
		p->position.first -= get_pjwc(so_long);
		if (p->di == 2)
			p->position.first += get_prwc(so_long) / 2;
		else if (p->di == 1)
			p->position.first -= get_plwc(so_long) / 2;
		p->jump--;
		if (p->jump == 0)
			p->di = 0;
	}
}

// Player jump in vertical axis
void	player_jump(t_so_long *so_long)
{
	t_player	*p;

	p = &(so_long->player);
	if ((p->action_code[0] == 10 \
		|| p->action_code[1] == 10) && p->jump == 0 && \
		get_pgwc(so_long) == 0)
		p->jump = 10;
	else if (p->jump > 0 && p->di == 0)
	{
		p->position.second -= get_pjwc(so_long);
		p->jump--;
	}
}
