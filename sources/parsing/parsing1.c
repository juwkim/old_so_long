/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/12/16 19:43:31 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	open_map(char *relative_path, t_so_long *so_long)
{
	const int	path_len = ft_strlen(relative_path);

	if (path_len <= 4)
		return (0);
	if (ft_strncmp(relative_path + (path_len - 4), ".ber", 4) != 0)
		return (0);
	so_long->map_fd = open(relative_path, O_RDONLY);
	return (so_long->map_fd > 0);
}

int	fill_lst(t_so_long *so_long)
{
	char	*line;

	line = "";
	while (line)
	{
		line = get_next_line(so_long->map_fd);
		if (line == NULL)
			return (so_long->game_width != -1);
		if (so_long->game_width == -1)
			so_long->game_width = ft_strlen(line) - 1;
		if (so_long->lst_map == NULL)
			so_long->lst_map = ft_lstnew(line);
		else
			ft_lstadd_back(&so_long->lst_map, ft_lstnew(line));
	}
	return (1);
}

int	convert_lst(t_so_long *so_long)
{
	t_list	*lst;
	int		i;

	so_long->game_height = ft_lstsize(so_long->lst_map);
	if (so_long->game_height < 3)
		return (0);
	so_long->map = ft_calloc(so_long->game_height + 1, sizeof(char *));
	if (so_long->map == NULL)
		exit(EXIT_FAILURE);
	lst = so_long->lst_map;
	i = 0;
	while (lst)
	{
		so_long->map[i] = ft_strdup(lst->content);
		if (!so_long->map[i])
			exit(EXIT_FAILURE);
		i++;
		lst = lst->next;
	}
	so_long->game_width = ft_strlen(so_long->map[0]);
	return (so_long->game_width > 3);
}

int	size_check(t_so_long *so_long)
{
	int	i;

	i = 0;
	while (i < so_long->game_height)
	{
		if (i == so_long->game_height - 1)
		{
			if ((int) ft_strlen(so_long->map[i]) != so_long->game_width - 1)
				break ;
		}
		else if ((int) ft_strlen(so_long->map[i]) != so_long->game_width)
			break ;
		i++;
	}
	return (i == so_long->game_height);
}
