/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:45:08 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 13:45:12 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Setting player collision points
void	player_position(t_so_long *so_long)
{
	t_player	*p;

	p = &so_long->player;
	p->a[0] = p->position.first;
	p->a[1] = p->position.second;
	p->b[0] = p->a[0];
	p->b[1] = p->a[1] + BPX;
	p->c[0] = p->a[0] + BPX;
	p->c[1] = p->a[1];
	p->d[0] = p->a[0] + BPX;
	p->d[1] = p->a[1] + BPX;
}
