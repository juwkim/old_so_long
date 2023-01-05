/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_stamp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:43:12 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 08:01:17 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools/time_stamp_bonus.h"

// Get timestamp in milliseconds
long long	time_stamp(void)
{
	struct timeval	timeval;
	long long		microtime;

	gettimeofday(&timeval, NULL);
	microtime = timeval.tv_sec * 1000LL + timeval.tv_usec / 1000;
	return (microtime);
}
