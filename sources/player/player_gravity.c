/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_gravity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:44:53 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 13:44:58 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Player_gravity
void	player_gravity(t_so_long *so_long)
{
	t_player	*p;

	p = &so_long->player;
	if ((p->action_code[0] != 4) && p->jump == 0)
		p->position.second += get_pgwc(so_long);
}
