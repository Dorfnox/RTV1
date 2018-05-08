/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_lighting_model.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 14:44:43 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/13 15:02:48 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		trig_no_falloff_light(t_rt *rt)
{
	t_light	*l;

	l = LGHT;
	while (l)
	{
		l->falloff = NO_FALLOFF;
		l = l->next;
	}
	draw_stuff(rt);
}

void		trig_linear_falloff_light(t_rt *rt)
{
	t_light	*l;

	l = LGHT;
	while (l)
	{
		l->falloff = LINEAR_FALLOFF;
		l = l->next;
	}
	draw_stuff(rt);
}

void		trig_square_falloff_light(t_rt *rt)
{
	t_light	*l;

	l = LGHT;
	while (l)
	{
		l->falloff = SQUARE_FALLOFF;
		l = l->next;
	}
	draw_stuff(rt);
}

void		trig_no_light(t_rt *rt)
{
	t_light	*l;

	l = LGHT;
	while (l)
	{
		l->falloff = NO_LIGHT;
		l = l->next;
	}
	draw_stuff(rt);
}
