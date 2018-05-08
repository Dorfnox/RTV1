/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_raytrace_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 14:49:19 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/30 14:53:56 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		trig_raytrace(t_rt *rt)
{
	SETT->raytrace_func = &raytrace;
	draw_stuff(rt);
}

void		trig_raytrace_light(t_rt *rt)
{
	SETT->raytrace_func = &raytrace_light;
	draw_stuff(rt);
}
