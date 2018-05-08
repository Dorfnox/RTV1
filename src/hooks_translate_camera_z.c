/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_translate_camera_z.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 22:53:39 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/29 16:02:53 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	trig_translate_camera_pos_z(t_rt *rt)
{
	TRIG->translate_camera_pos_z = 1;
}

void	untrig_translate_camera_pos_z(t_rt *rt)
{
	TRIG->translate_camera_pos_z = 0;
}

void	trig_translate_camera_neg_z(t_rt *rt)
{
	TRIG->translate_camera_neg_z = 1;
}

void	untrig_translate_camera_neg_z(t_rt *rt)
{
	TRIG->translate_camera_neg_z = 0;
}
