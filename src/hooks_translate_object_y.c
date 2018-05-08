/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_translate_object_y.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 13:53:25 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/12 21:32:46 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	trig_translate_object_pos_y(t_rt *rt)
{
	TRIG->translate_object_pos_y = 1;
}

void	trig_translate_object_neg_y(t_rt *rt)
{
	TRIG->translate_object_neg_y = 1;
}

void	untrig_translate_object_pos_y(t_rt *rt)
{
	TRIG->translate_object_pos_y = 0;
}

void	untrig_translate_object_neg_y(t_rt *rt)
{
	TRIG->translate_object_neg_y = 0;
}
