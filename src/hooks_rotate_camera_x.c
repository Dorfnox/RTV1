/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_rotate_camera_x.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 22:53:39 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/27 22:57:11 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	trig_rotate_camera_pos_x(t_rt *rt)
{
	TRIG->rotate_camera_pos_x = 1;
}

void	untrig_rotate_camera_pos_x(t_rt *rt)
{
	TRIG->rotate_camera_pos_x = 0;
}

void	trig_rotate_camera_neg_x(t_rt *rt)
{
	TRIG->rotate_camera_neg_x = 1;
}

void	untrig_rotate_camera_neg_x(t_rt *rt)
{
	TRIG->rotate_camera_neg_x = 0;
}
