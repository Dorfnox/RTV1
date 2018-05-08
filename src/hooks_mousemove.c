/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mousemove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 23:10:05 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/08 20:32:18 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		mouse_move(int x, int y, t_rt *rt)
{
	static int	oldx;
	static int	oldy;

	if (rt)
		oldx = x;
	if (rt)
		oldy = y;
	return (1);
}
