/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:42:52 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 08:00:53 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monster/monster_bonus.h"

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
	t_monster *const	monster = malloc(sizeof(t_monster));

	if (monster == NULL)
		exit(EXIT_FAILURE);
	monster->position.second = second * BLOCK_SIZE;
	monster->position.first = first * BLOCK_SIZE;
	monster->hited = 0;
	monster->move = 0;
	monster->image_update = 0;
	if (first + second & 1)
	{
		monster->move_horizontal = MOVE_RIGHT;
		monster->image_idx = 0;
	}
	else
	{
		monster->move_horizontal = MOVE_LEFT;
		monster->image_idx = 11;
	}
	monster->move = MONSTER_MOVE_COUNT;
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
		monster_move(monster, game->map);
		monster_collision(game, monster);
		mlx_put_image_to_window(game->mlx, game->window,
			get_monster_image(game, monster),
			monster->position.first + game->offset.first,
			monster->position.second + game->offset.second);
		lst = lst->next;
	}
}
