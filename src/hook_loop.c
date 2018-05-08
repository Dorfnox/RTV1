/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 13:05:20 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/16 14:37:32 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		draw_stuff(t_rt *rt)
{
	t_thready	t[SETT->num_of_threads];
	pthread_t	t_id[SETT->num_of_threads];
	int			i;

	i = -1;
	bzero(IMAG->pix, W * H * 4);
	while (++i < SETT->num_of_threads)
	{
		t[i].rt = rt;
		t[i].g.start_x = (W / SETT->num_of_threads) * i;
		t[i].g.start_y = -1;
		t[i].g.end_x = (W / SETT->num_of_threads) * (i + 1);
		t[i].g.end_y = H;
		pthread_create(&t_id[i], NULL, SETT->raytrace_func, &t[i]);
	}
	i = -1;
	while (++i < SETT->num_of_threads)
		pthread_join(t_id[i], NULL);
	mlx_put_image_to_window(rt->mlx, rt->win, IMAG->img, 0, 0);
	if (TRIG->display_info_panel)
		display_info_panel(rt);
}

static int	forever_loop_even_more(t_rt *rt)
{
	if (CAMERA_NEEDS_TRANSLATION)
	{
		if (CNT_X)
			SETT->camera.x += TRIG->translate_camera_pos_x ?
				SETT->translate_speed : -SETT->translate_speed;
		if (CNT_Y)
			SETT->camera.y += TRIG->translate_camera_pos_y ?
				SETT->translate_speed : -SETT->translate_speed;
		if (CNT_Z)
			SETT->camera.z += TRIG->translate_camera_pos_z ?
				SETT->translate_speed : -SETT->translate_speed;
		draw_stuff(rt);
	}
	return (1);
}

static int	forever_loop_some_more(t_rt *rt)
{
	if (CAMERA_NEEDS_ROTATION)
	{
		if (CNR_X)
			rotate_camera_x(SETT->normalized_vector_ray, &SETT->camera,
				((TRIG->rotate_camera_pos_x ? SETT->rotate_speed :
				-SETT->rotate_speed) * M_PI / 180));
		if (CNR_Y)
			rotate_camera_y(SETT->normalized_vector_ray, &SETT->camera,
				((TRIG->rotate_camera_pos_y ? SETT->rotate_speed :
				-SETT->rotate_speed) * M_PI / 180));
		if (CNR_Z)
			rotate_camera_z(SETT->normalized_vector_ray, &SETT->camera,
				((TRIG->rotate_camera_pos_z ? SETT->rotate_speed :
				-SETT->rotate_speed) * M_PI / 180));
		draw_stuff(rt);
	}
	return (forever_loop_even_more(rt));
}

static int	forever_loop_more(t_rt *rt)
{
	if (OBJECT_NEEDS_TRANSLATION)
	{
		if (ONT_X)
			EDIT->pos.x += TRIG->translate_object_pos_x ?
				SETT->translate_speed : -SETT->translate_speed;
		if (ONT_Y)
			EDIT->pos.y += TRIG->translate_object_pos_y ?
				SETT->translate_speed : -SETT->translate_speed;
		if (ONT_Z)
			EDIT->pos.z += TRIG->translate_object_pos_z ?
				SETT->translate_speed : -SETT->translate_speed;
		draw_stuff(rt);
	}
	return (forever_loop_some_more(rt));
}

int			forever_loop(t_rt *rt)
{
	if (OBJECT_NEEDS_ROTATION)
	{
		if (ONR_X)
			rotate_vector_x(&EDIT->vector, (TRIG->rotate_object_pos_x ?
				SETT->rotate_speed : -SETT->rotate_speed) * M_PI / 180);
		if (ONR_Y)
			rotate_vector_y(&EDIT->vector, (TRIG->rotate_object_pos_y ?
				SETT->rotate_speed : -SETT->rotate_speed) * M_PI / 180);
		if (ONR_Z)
			rotate_vector_z(&EDIT->vector, (TRIG->rotate_object_pos_z ?
				SETT->rotate_speed : -SETT->rotate_speed) * M_PI / 180);
		draw_stuff(rt);
	}
	return (forever_loop_more(rt));
}
