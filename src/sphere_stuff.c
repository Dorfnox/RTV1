/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 15:36:08 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/16 22:49:25 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double			sphere_intersect(t_obj *o, t_xyz *ro, t_xyz *rv)
{
	t_sphere_intersect	s;

	s.dist = vector_diff(&o->pos, ro);
	s.b = dot_product(rv, &s.dist);
	if ((s.d = ((s.b * s.b) - dot_product(&s.dist, &s.dist)
					+ (o->radius * o->radius))) < 0)
		return (0);
	s.sqroot = sqrt(s.d);
	s.t0 = s.b - s.sqroot;
	s.t1 = s.b + s.sqroot;
	s.t = NULL;
	if (s.t0 > 0.0001 && s.t0 < s.t1)
		s.t = &s.t0;
	if (s.t1 > 0.0001 && s.t1 < s.t0)
		s.t = &s.t1;
	return (s.t ? *s.t : 0);
}

t_xyz			sphere_normal(t_obj *o, t_xyz *hitpos)
{
	t_xyz	vecdiff;

	vecdiff = vector_diff(hitpos, &o->pos);
	normalize_vector(&vecdiff);
	return (vecdiff);
}

void			set_sphere_reqs(t_obj *o)
{
	if (o->type == SPHERE)
	{
		if (!o->radius)
			o->radius = 1;
		if (o->albedo <= 0)
			o->albedo = 1;
	}
}
