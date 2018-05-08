/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_speed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 14:39:46 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/16 14:57:20 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	increase_translation_speed(t_rt *rt)
{
	SETT->translate_speed += 0.1;
	if (SETT->translate_speed > 100)
		SETT->translate_speed = 100;
}

void	decrease_translation_speed(t_rt *rt)
{
	SETT->translate_speed -= 0.1;
	if (SETT->translate_speed < 0)
		SETT->translate_speed = 0;
}

void	increase_rotation_speed(t_rt *rt)
{
	SETT->rotate_speed += 1;
	if (SETT->rotate_speed > 180)
		SETT->rotate_speed = 180;
}

void	decrease_rotation_speed(t_rt *rt)
{
	SETT->rotate_speed -= 1;
	if (SETT->rotate_speed < 0)
		SETT->rotate_speed = 0;
}
