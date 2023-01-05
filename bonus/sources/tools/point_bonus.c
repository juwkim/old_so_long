/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 02:51:56 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 08:01:14 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools/point_bonus.h"

int	is_equal(t_point a, t_point b)
{
	return (a.first == b.first && a.second == b.second);
}
