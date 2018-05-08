/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 18:08:04 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/16 22:48:53 by bpierce          ###   ########.fr       */
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

static int		calculate_light_contribution(
		t_rt *rt, t_obj *o_to_math, t_xyz *o_hitpos, t_xyz *o_normal)
{
	double		l_dist;
	t_light		*l;
	t_xyz		l_vector;
	t_colour	lc;
	t_colour	newcolour;

	l = LGHT;
	newcolour.r = 0;
	newcolour.g = 0;
	newcolour.b = 0;
	*o_hitpos = vector_add(o_hitpos, o_normal, 0.00001);
	while (l)
	{
		l_vector = vector_diff(&l->pos, o_hitpos);
		normalize_and_set_light_colour(l, &l_vector, &lc, &l_dist);
		if (!trace(o_hitpos, &l_vector, OBJT, &l_dist))
			add_light_contribution(&newcolour, &lc, &o_to_math->colour,
					((o_to_math->albedo) * l->intensity *
					CLAMP_ZERO(dot_product(&l_vector, o_normal))));
		l = l->next;
	}
	newcolour.r = newcolour.r > 255 ? 255 : newcolour.r;
	newcolour.g = newcolour.g > 255 ? 255 : newcolour.g;
	newcolour.b = newcolour.b > 255 ? 255 : newcolour.b;
	return ((newcolour.r << 16) | (newcolour.g << 8) | (newcolour.b));
}

static void		do_trace_stuff(t_rt *rt, int x, int y)
{
	double		d;
	t_obj		*o_to_math;
	t_xyz		o_hitpos;
	t_xyz		o_normal;

	d = SETT->max_draw_dist;
	if (!(o_to_math = trace(&SETT->camera,
					&SETT->normalized_vector_ray[XY], OBJT, &d)))
		IMAG->pix[XY] = 0xCCDDEE;
	else
	{
		o_hitpos = pos_on_object(d, &SETT->normalized_vector_ray[XY]);
		o_hitpos = convert_hitpos_to_worldspace(&o_hitpos, &SETT->camera);
		o_normal = o_to_math->normal(o_to_math, &o_hitpos);
		IMAG->pix[XY] = calculate_light_contribution(
				rt, o_to_math, &o_hitpos, &o_normal);
	}
}

void			*raytrace(void *container)
{
	t_thready	*t;
	int			x_restart;

	t = (t_thready *)container;
	x_restart = t->g.start_x - 1;
	while (++t->g.start_y < t->g.end_y)
	{
		t->g.start_x = x_restart;
		while (++t->g.start_x < t->g.end_x)
			do_trace_stuff(t->rt, t->g.start_x, t->g.start_y);
	}
	return (NULL);
}
