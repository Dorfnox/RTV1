/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 15:08:50 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/16 16:47:03 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		trig_display_info_panel(t_rt *rt)
{
	TRIG->display_info_panel = TRIG->display_info_panel ^ 1;
	draw_stuff(rt);
}

void		display_info_panel(t_rt *rt)
{
	mlx_put_image_to_window(rt->mlx, rt->win, rt->info_panel->topleft->img,
			10, 10);
	mlx_put_image_to_window(rt->mlx, rt->win, rt->info_panel->topright->img,
			W - 250, 10);
	mlx_put_image_to_window(rt->mlx, rt->win, rt->info_panel->bot->img,
			0, H - 100);
}
