/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_gravity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/12/16 17:49:53 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Player_gravity
void	player_gravity(t_so_long *so_long)
{
	t_player	*p;

	p = &so_long->player;
	if ((p->action_code[0] != 4) && p->jump == 0)
		p->position.second += get_pgwc(so_long);
}
