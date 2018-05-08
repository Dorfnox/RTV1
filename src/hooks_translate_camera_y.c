/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_translate_camera_y.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 22:53:39 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/29 16:02:42 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	trig_translate_camera_pos_y(t_rt *rt)
{
	TRIG->translate_camera_pos_y = 1;
}

void	untrig_translate_camera_pos_y(t_rt *rt)
{
	TRIG->translate_camera_pos_y = 0;
}

void	trig_translate_camera_neg_y(t_rt *rt)
{
	TRIG->translate_camera_neg_y = 1;
}

void	untrig_translate_camera_neg_y(t_rt *rt)
{
	TRIG->translate_camera_neg_y = 0;
}
