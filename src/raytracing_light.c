/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 18:08:04 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/13 17:16:29 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_obj	*trace(t_xyz *pos, t_xyz *normal_vect, t_obj *ob, double *dist)
{
	double	dcheck;
	t_obj	*o;
	t_obj	*closest_object;

	closest_object = NULL;
	o = ob;
	while (o)
	{
		if ((dcheck = o->intersect(o, pos, normal_vect)))
		{
			if (dcheck < *dist && (*dist = dcheck))
				closest_object = o;
		}
		o = o->next;
	}
	return (closest_object);
}

static void		do_trace_stuff_light(t_rt *rt, int x, int y)
{
	double		d;
	t_obj		*o_to_math;

	d = SETT->max_draw_dist;
	if (!(o_to_math = trace(&SETT->camera, &SETT->normalized_vector_ray[XY],
					OBJT, &d)))
		IMAG->pix[XY] = 0xCCDDEE;
	else
		IMAG->pix[XY] = ft_rgb_to_hex(o_to_math->colour.r, o_to_math->colour.g,
				o_to_math->colour.b);
}

void			*raytrace_light(void *container)
{
	t_thready	*t;
	int			x_restart;

	t = (t_thready *)container;
	x_restart = t->g.start_x - 1;
	while (++t->g.start_y < t->g.end_y)
	{
		t->g.start_x = x_restart;
		while (++t->g.start_x < t->g.end_x)
			do_trace_stuff_light(t->rt, t->g.start_x, t->g.start_y);
	}
	return (NULL);
}
