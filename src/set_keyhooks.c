/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_keyhooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:11:44 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/16 14:47:13 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	set_more_key_presses(void (**kp)(t_rt *))
{
	kp[NUM6__] = &trig_translate_object_pos_x;
	kp[NUM4__] = &trig_translate_object_neg_x;
	kp[NUM8__] = &trig_translate_object_pos_y;
	kp[NUM2__] = &trig_translate_object_neg_y;
	kp[NUM9__] = &trig_translate_object_pos_z;
	kp[NUM7__] = &trig_translate_object_neg_z;
	kp[UP__] = &trig_rotate_object_pos_x;
	kp[DOWN__] = &trig_rotate_object_neg_x;
	kp[LEFT__] = &trig_rotate_object_pos_y;
	kp[RIGHT__] = &trig_rotate_object_neg_y;
	kp[RSHIFT__] = &trig_rotate_object_pos_z;
	kp[RCTRL__] = &trig_rotate_object_neg_z;
	kp[D__] = &trig_translate_camera_pos_x;
	kp[A__] = &trig_translate_camera_neg_x;
	kp[W__] = &trig_translate_camera_pos_y;
	kp[S__] = &trig_translate_camera_neg_y;
	kp[Z__] = &trig_translate_camera_pos_z;
	kp[X__] = &trig_translate_camera_neg_z;
}

void		set_key_presses(void (**kp)(t_rt *))
{
	kp[I__] = &trig_display_info_panel;
	kp[KEY1__] = &trig_raytrace_light;
	kp[KEY2__] = &trig_raytrace;
	kp[KEY7__] = &trig_no_falloff_light;
	kp[KEY8__] = &trig_linear_falloff_light;
	kp[KEY9__] = &trig_square_falloff_light;
	kp[KEY0__] = &trig_no_light;
	kp[ESC__] = &exit_window_kp;
	kp[LSHIFT__] = &shift_keys;
	kp[NUMADD__] = &increase_translation_speed;
	kp[NUMSUBTRACT__] = &decrease_translation_speed;
	kp[KEYADD__] = &increase_rotation_speed;
	kp[KEYSUBTRACT__] = &decrease_rotation_speed;
	set_more_key_presses(kp);
}

void		set_key_releases(void (**kr)(t_rt *))
{
	kr[ESC__] = &exit_window_kp;
	kr[NUM6__] = &untrig_translate_object_pos_x;
	kr[NUM4__] = &untrig_translate_object_neg_x;
	kr[NUM8__] = &untrig_translate_object_pos_y;
	kr[NUM2__] = &untrig_translate_object_neg_y;
	kr[NUM9__] = &untrig_translate_object_pos_z;
	kr[NUM7__] = &untrig_translate_object_neg_z;
	kr[UP__] = &untrig_rotate_object_pos_x;
	kr[DOWN__] = &untrig_rotate_object_neg_x;
	kr[LEFT__] = &untrig_rotate_object_pos_y;
	kr[RIGHT__] = &untrig_rotate_object_neg_y;
	kr[RSHIFT__] = &untrig_rotate_object_pos_z;
	kr[RCTRL__] = &untrig_rotate_object_neg_z;
	kr[D__] = &untrig_translate_camera_pos_x;
	kr[A__] = &untrig_translate_camera_neg_x;
	kr[W__] = &untrig_translate_camera_pos_y;
	kr[S__] = &untrig_translate_camera_neg_y;
	kr[Z__] = &untrig_translate_camera_pos_z;
	kr[X__] = &untrig_translate_camera_neg_z;
	kr[LSHIFT__] = &unshift_keys;
}

void		shift_keys(t_rt *rt)
{
	KP[W__] = &trig_rotate_camera_pos_x;
	KP[S__] = &trig_rotate_camera_neg_x;
	KP[D__] = &trig_rotate_camera_pos_y;
	KP[A__] = &trig_rotate_camera_neg_y;
	KP[X__] = &trig_rotate_camera_pos_z;
	KP[Z__] = &trig_rotate_camera_neg_z;
	KR[W__] = &untrig_rotate_camera_pos_x;
	KR[S__] = &untrig_rotate_camera_neg_x;
	KR[D__] = &untrig_rotate_camera_pos_y;
	KR[A__] = &untrig_rotate_camera_neg_y;
	KR[X__] = &untrig_rotate_camera_pos_z;
	KR[Z__] = &untrig_rotate_camera_neg_z;
}

void		unshift_keys(t_rt *rt)
{
	set_key_presses(KP);
	set_key_releases(KR);
}
