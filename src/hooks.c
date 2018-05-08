/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 23:18:33 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/16 22:59:47 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		key_press(int keycode, t_rt *rt)
{
	rt->kp[keycode](rt);
	return (1);
}

int		key_release(int keycode, t_rt *rt)
{
	rt->kr[keycode](rt);
	return (1);
}

int		mouse_release(int button, int x, int y, t_rt *rt)
{
	if (rt)
		button = x + y;
	return (1);
}
