/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:23:13 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 16:38:25 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "main.h"

int	open_map(t_game *game, char *path);
int	read_map(t_game *game, int fd);
int	check_map(t_game *game);
int	check_side(t_game *game);

#endif
