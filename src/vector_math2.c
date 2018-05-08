/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 23:09:48 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/13 17:15:20 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		flip_vector(t_xyz *v)
{
	v->x = -v->x;
	v->y = -v->y;
	v->z = -v->z;
}

t_xyz		vector_add(t_xyz *a, t_xyz *b, double b_mult_constant)
{
	t_xyz	new;

	new.x = a->x + (b->x * b_mult_constant);
	new.y = a->y + (b->y * b_mult_constant);
	new.z = a->z + (b->z * b_mult_constant);
	return (new);
}

t_xyz		vector_subtract(t_xyz *a, t_xyz *b, double b_mult_constant)
{
	t_xyz	new;

	new.x = a->x - (b->x * b_mult_constant);
	new.y = a->y - (b->y * b_mult_constant);
	new.z = a->z - (b->z * b_mult_constant);
	return (new);
}

t_xyz		pos_on_object(double distance, t_xyz *view_vector)
{
	t_xyz	point_on_dat_object;

	point_on_dat_object.x = view_vector->x * distance;
	point_on_dat_object.y = view_vector->y * distance;
	point_on_dat_object.z = view_vector->z * distance;
	return (point_on_dat_object);
}

t_xyz		convert_hitpos_to_worldspace(t_xyz *p, t_xyz *camera_pos)
{
	t_xyz	res;

	res.x = p->x + camera_pos->x;
	res.y = p->y + camera_pos->y;
	res.z = p->z + camera_pos->z;
	return (res);
}
