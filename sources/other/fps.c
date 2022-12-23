/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:43:12 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 13:43:16 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Get timestamp in milliseconds
long long	millitimestamp(void)
{
	struct timeval	timeval;
	long long		microtime;

	gettimeofday(&timeval, NULL);
	microtime = timeval.tv_sec * 1000LL + timeval.tv_usec / 1000;
	return (microtime);
}

#include <stdio.h>
// Show FPS in the window
void	show_fps(t_so_long *so_long)
{
	char	*debug_msg;
	char	*fps;

	fps = ft_itoa(so_long->fps);
	debug_msg = ft_strjoin("FPS: ", fps);
	mlx_string_put(so_long->mlx, so_long->window, 20, 30, 11001101, debug_msg);
	free(fps);
	free(debug_msg);
}

// Calculate FPS
void	fps(t_so_long *so_long)
{
	long long	now;

	now = millitimestamp();
	if (now > so_long->lm)
	{
		so_long->fps = 960 / (now - so_long->lm);
		so_long->lm = now;
	}
}
