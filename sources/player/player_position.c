/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/12/16 17:47:49 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
