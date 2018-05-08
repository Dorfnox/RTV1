/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mouse_press.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 13:53:25 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/16 22:50:04 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	select_object_to_edit(int x, int y, t_rt *rt)
{
	t_obj	*o;
	double	d;
	double	dcheck;

	o = OBJT;
	d = SETT->max_draw_dist;
	while (o)
	{
		if ((dcheck = o->intersect(o, &SETT->camera,
					&SETT->normalized_vector_ray[x + (y * W)])))
		{
			if (dcheck < d)
			{
				EDIT = o;
				d = dcheck;
			}
		}
		o = o->next;
	}
}

int			mouse_press(int button, int x, int y, t_rt *rt)
{
	if (button == 1)
		select_object_to_edit(x, y, rt);
	return (1);
}
