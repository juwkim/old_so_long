/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:44:12 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 13:44:16 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// get action code
int	get_action_keycode(int keycode)
{
	if (keycode == 123 || keycode == 0)
		return (1);
	else if (keycode == 124 || keycode == 2)
		return (2);
	else if (keycode == 126 || keycode == 13)
		return (10);
	else if (keycode == 125 || keycode == 1)
		return (4);
	else if (keycode == 14 || keycode == 82)
		return (5);
	else if (keycode == 49)
		return (10);
	return (0);
}

// set action
void	set_action(int keycode, t_so_long *so_long)
{
	t_player	*p;

	p = &so_long->player;
	if (get_action_keycode(keycode) != 5)
	{
		if (p->action_code[0] == 0
			|| p->action_code[0] == get_action_keycode(keycode))
			p->action_code[0] = get_action_keycode(keycode);
		else if (p->action_code[1] == 0 || \
			p->action_code[1] == get_action_keycode(keycode))
			p->action_code[1] = get_action_keycode(keycode);
	}
	else
		p->action_code[2] = get_action_keycode(keycode);
	if (p->action_code[0] == 1 || p->action_code[1] == 1)
		p->direction = 0;
	if (p->action_code[0] == 2 || p->action_code[1] == 2)
		p->direction = 1;
}

// unset action
void	unset_action(int keycode, t_so_long *so_long)
{
	t_player	*p;

	p = &so_long->player;
	if (p->action_code[0] == get_action_keycode(keycode))
		p->action_code[0] = 0;
	if (p->action_code[1] == get_action_keycode(keycode))
		p->action_code[1] = 0;
	if (p->action_code[0] == 0 && p->action_code[1] != 0)
	{
		p->action_code[0] = p->action_code[1];
		p->action_code[1] = 0;
	}
	if (p->action_code[2] == get_action_keycode(keycode))
		p->action_code[2] = 0;
}
