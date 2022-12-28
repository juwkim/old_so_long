/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:42:52 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 21:54:48 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monster/monster.h"

void	set_monster(t_game *game)
{
	int	second;
	int	first;
	int	count;

	count = 0;
	second = 0;
	while (second < game->map_size.second)
	{
		first = 0;
		while (first < game->map_size.first)
		{	
			if (game->map[second][first] == CHAR_EMPTY)
			{
				count = (count + 1) % MOSTER_FREQUENCY;
				if (count == 0)
					new_monster(game, second, first);
			}
			++first;
		}
		++second;
	}
}

void	new_monster(t_game *game, int second, int first)
{
	t_monster *const	monster = ft_calloc(sizeof(t_monster), 1);

	if (monster == NULL)
		exit(EXIT_FAILURE);
	monster->position.second = second * BLOCK_SIZE;
	monster->position.first = first * BLOCK_SIZE;
	monster->direction = MOVE_RIGHT;
	if (game->monsters == NULL)
		game->monsters = ft_lstnew(monster);
	else
		ft_lstadd_front(&game->monsters, ft_lstnew(monster));
}

void	monster_update(t_game *game)
{
	t_list		*lst;
	t_monster	*monster;

	lst = game->monsters;
	while (lst)
	{
		monster = (t_monster *) lst->content;
		monster_move(monster, game);
		monster_interaction(game);
		mlx_put_image_to_window(game->mlx, game->window,
			get_monster_image(monster, game),
			monster->position.first + game->offset_window.first,
			monster->position.second + game->offset_window.second);
		lst = lst->next;
	}
}
