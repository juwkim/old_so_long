/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:16:19 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 17:17:56 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "main.h"

int	keydown_hook(int keycode, t_game *game);
int	keyup_hook(int keycode, t_game *game);
int	close_hook(int keycode, t_game *game);

#endif