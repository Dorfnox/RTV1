/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 15:25:47 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/16 16:27:07 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		initialize_hooks(t_rt *rt)
{
	mlx_do_key_autorepeatoff(rt->mlx);
	mlx_hook(rt->win, 2, 0, key_press, rt);
	mlx_hook(rt->win, 3, 0, key_release, rt);
	mlx_hook(rt->win, 4, 0, mouse_press, rt);
	mlx_hook(rt->win, 5, 0, mouse_release, rt);
	mlx_hook(rt->win, 6, 0, mouse_move, rt);
	mlx_hook(rt->win, 12, 0, expose_i_guess, rt);
	mlx_hook(rt->win, 17, 0, exit_window, rt);
	mlx_loop_hook(rt->mlx, forever_loop, rt);
}

t_rt			*more_initializing_of_stuff(t_rt *new)
{
	set_arrays(new);
	initialize_hooks(new);
	if (!(new->info_panel = get_info_panels(new)))
		return (ft_putnull("Failed to get info panels in initialize.c"));
	if (!(new->img = new_image(new, W, H)))
		return (ft_putnull("Failed to get new image\n"));
	return (new);
}

t_rt			*initialize_rt(void *mlx, char *f)
{
	t_rt	*new;

	if (!(new = (t_rt *)ft_memalloc(sizeof(t_rt))))
		return (ft_putnull("Failed to malloc space for t_rt *\n"));
	if (!(new->trig = (t_trig *)ft_memalloc(sizeof(t_trig))))
		return (ft_putnull("Failed to malloc space for t_trig *\n"));
	if (EQU(f, "-e"))
	{
		new->obj = NULL;
		new->light = NULL;
	}
	else
	{
		if (!(new->obj = get_obj_list(f)))
			return (ft_putnull("Failed to get new object list\n"));
		if (!(new->light = get_light_list(f)))
			return (ft_putnull("Failed to get new light list\n"));
	}
	new->mlx = mlx;
	if (!(new->settings = get_settings(new, (f[0] != '-' ? f : NULL))))
		return (ft_putnull("Failed to get new settings\n"));
	new->win = mlx_new_window(new->mlx, W, H, "Raytracing to Infinity");
	return (more_initializing_of_stuff(new));
}
