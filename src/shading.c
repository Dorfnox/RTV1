/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:07:02 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/16 21:36:41 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** In computer graphics, a shading function is defined as a function
** which yields the intensity value of each point on the body of an object
** from the characteristics of the light source, the object, and the position
** of the observer. Mr. Phongy Phongums Phong - 1975.
**
** When a ray of light reflects off a surface,
** the angle of incidence is equal to the angle of reflection.
**
** Albedo: the color of an object can be defined as
** the ratio of reflected light over the amount of incident light.
** For example, in an orange this ratio would be:
** 0.1 for blue, 0.6 for green and 0.9 for red.
**
** The following applies several falloff laws for light intensity
** based on distance
*/

static void	set_light_according_to_type_of_falloff(
		t_light *l, double r2, double dist, t_colour *c)
{
	if (l->falloff == NO_LIGHT)
	{
		c->r = 0;
		c->g = 0;
		c->b = 0;
	}
	else if (l->falloff == LINEAR_FALLOFF)
	{
		c->r /= dist;
		c->g /= dist;
		c->b /= dist;
	}
	else if (l->falloff == SQUARE_FALLOFF)
	{
		c->r /= (4 * M_PI * r2);
		c->g /= (4 * M_PI * r2);
		c->b /= (4 * M_PI * r2);
	}
}

void		normalize_and_set_light_colour(
		t_light *l, t_xyz *l_v, t_colour *c, double *l_dist)
{
	double	r2;

	r2 = (l_v->x * l_v->x) + (l_v->y * l_v->y) + (l_v->z * l_v->z);
	*l_dist = sqrt(r2);
	l_v->x /= *l_dist;
	l_v->y /= *l_dist;
	l_v->z /= *l_dist;
	c->r = l->intensity * l->colour.r;
	c->g = l->intensity * l->colour.g;
	c->b = l->intensity * l->colour.b;
	set_light_according_to_type_of_falloff(l, r2, *l_dist, c);
}

void		add_light_contribution(t_colour *new_c,
		t_colour *light_c, t_colour *obj_c, double ratio)
{
	new_c->r += (light_c->r * ratio) * (obj_c->r / 255.0);
	new_c->g += (light_c->g * ratio) * (obj_c->g / 255.0);
	new_c->b += (light_c->b * ratio) * (obj_c->b / 255.0);
}
