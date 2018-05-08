/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_macros.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:55:35 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/07 20:58:01 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_MACROS_H
# define RTV1_MACROS_H

/*
** Keys
*/

# define A__ 0
# define B__ 11
# define C__ 8
# define D__ 2
# define E__ 14
# define F__ 3
# define G__ 5
# define H__ 4
# define I__ 34
# define J__ 38
# define K__ 40
# define L__ 37
# define M__ 46
# define N__ 45
# define O__ 31
# define P__ 35
# define Q__ 12
# define R__ 15
# define S__ 1
# define T__ 17
# define U__ 32
# define V__ 9
# define W__ 13
# define X__ 7
# define Y__ 16
# define Z__ 6
# define UP__ 126
# define DOWN__ 125
# define RIGHT__ 124
# define LEFT__ 123
# define MOUSE1__ 1
# define MOUSE2__ 2
# define MOUSESCROLLUP__ 4
# define MOUSESCROLLDOWN__ 5
# define SPACE__ 49
# define LSHIFT__ 257
# define RSHIFT__ 258
# define RCTRL__ 269
# define DIVIDE__ 75
# define MULTIPLY__ 67
# define LESSTHAN__ 43
# define GREATERTHAN__ 47
# define ESC__ 53
# define NUM0__ 82
# define NUM1__ 83
# define NUM2__ 84
# define NUM3__ 85
# define NUM4__ 86
# define NUM5__ 87
# define NUM6__ 88
# define NUM7__ 89
# define NUM8__ 91
# define NUM9__ 92
# define NUMADD__ 69
# define NUMSUBTRACT__ 78
# define KEY0__ 29
# define KEY1__ 18
# define KEY2__ 19
# define KEY3__ 20
# define KEY4__ 21
# define KEY5__ 23
# define KEY6__ 22
# define KEY7__ 26
# define KEY8__ 28
# define KEY9__ 25
# define KEYADD__ 24
# define KEYSUBTRACT__ 27

/*
** Ease of understanding macros ------------------------------------------------
*/

# define LIGHT 1
# define PLANE 2
# define SPHERE 3
# define CYLINDER 4
# define CONE 5

# define NO_LIGHT 0
# define LINEAR_FALLOFF 1
# define SQUARE_FALLOFF 2
# define NO_FALLOFF 3

# define OBJT rt->obj
# define TRIG rt->trig
# define IMAG rt->img
# define SETT rt->settings
# define EDIT rt->settings->shortcut_to_object_currently_being_edited
# define LGHT rt->light
# define KP rt->kp
# define KR rt->kr

# define EQU ft_strequ
# define STR ft_strstr

# define TCR o->colour.r
# define TCG o->colour.g
# define TCB o->colour.b
# define SET_HEX_COLOUR o->colour_hex = ft_rgb_to_hex(TCR, TCG, TCB)
# define XY (x + (y * W))
# define MXY (m.x + (m.y * W))

# define ONR_X (TRIG->rotate_object_pos_x ^ TRIG->rotate_object_neg_x)
# define ONR_Y (TRIG->rotate_object_pos_y ^ TRIG->rotate_object_neg_y)
# define ONR_Z (TRIG->rotate_object_pos_z ^ TRIG->rotate_object_neg_z)
# define OBJECT_NEEDS_ROTATION ((ONR_X) || (ONR_Y) || (ONR_Z))

# define ONT_X (TRIG->translate_object_pos_x ^ TRIG->translate_object_neg_x)
# define ONT_Y (TRIG->translate_object_pos_y ^ TRIG->translate_object_neg_y)
# define ONT_Z (TRIG->translate_object_pos_z ^ TRIG->translate_object_neg_z)
# define OBJECT_NEEDS_TRANSLATION ((ONT_X) || (ONT_Y) || (ONT_Z))

# define CNR_X (TRIG->rotate_camera_pos_x ^ TRIG->rotate_camera_neg_x)
# define CNR_Y (TRIG->rotate_camera_pos_y ^ TRIG->rotate_camera_neg_y)
# define CNR_Z (TRIG->rotate_camera_pos_z ^ TRIG->rotate_camera_neg_z)
# define CAMERA_NEEDS_ROTATION ((CNR_X) || (CNR_Y) || (CNR_Z))

# define CNT_X (TRIG->translate_camera_pos_x ^ TRIG->translate_camera_neg_x)
# define CNT_Y (TRIG->translate_camera_pos_y ^ TRIG->translate_camera_neg_y)
# define CNT_Z (TRIG->translate_camera_pos_z ^ TRIG->translate_camera_neg_z)
# define CAMERA_NEEDS_TRANSLATION ((CNT_X) || (CNT_Y) || (CNT_Z))

/*
** Mathy stuff -----------------------------------------------------------------
*/

# define PX1 ((2.0 * ((x + 0.5) / (double)W)) - 1.0)
# define PX2 (tan((s->fov / 2.0) * (M_PI / 180.0)) * s->aspect_ratio)
# define PX (PX1) * (PX2)
# define PY1 ((y + 0.5) / (double)H)
# define PY (1.0 - (2.0 * PY1 * tan((s->fov / 2.0) * (M_PI / 180.0))))

# define CLAMP_ZERO(x) (((x) < 0.02) ? (0.02) : (x))
# define MAX(a, b) ((a) > (b) ? (a) : (b))
# define ABS(a) ((a) < 0 ? ((a) * -1.0) : (a))

/*
** Usage -----------------------------------------------------------------------
*/

# define USAGE1 "usage:./rtv1 [shapes/anyfile.shape] [-h]\n\n"
# define USAGE2 "shapes/ ... contains all the .shape files\n"
# define USAGE USAGE1 USAGE2 "-h      ... brings up the key controls in the terminal\n"

# define LEGEND1 "[93mInformation\n-----------\n[0m"
# define LEGEND2 "[i] HUD screen with key controls\n\n"

# define LEGEND3 "[94mChanging the view\n-----------------\n[0m"
# define LEGEND4 "[1] Quick Object Manipulation view\n"
# define LEGEND5 "[2] Normal Raytrace view\n\n"

# define LEGEND6 "[95mLight manipulation\n------------------\n[0m"
# define LEGEND7 "[7] No light falloff\n"
# define LEGEND8 "[8] Linear light falloff\n"
# define LEGEND9 "[9] Square light falloff\n"
# define LEGEND10 "[0] No light\n\n"

# define LEGEND11 "[96mObject Manipulation\n-------------------\n[0m"
# define LEGEND12 "[Arrow Keys, rShift, rCtrl]     Rotate Object\n"
# define LEGEND13 "[Numpad 2, 4, 6, 7, 8, 9,]      Translate Object\n\n"

# define LEGEND14 "[97mCamera Manipulation\n-------------------\n[0m"
# define LEGEND15 "[W, A, S, D, Z, X]              Translate Camera x, y, z axis\n"
# define LEGEND16 "[(SHIFT) + (W, A, S, D, Z, X)]  Rotate Camera x, y, z axis\n"
# define LEGEND17 LEGEND1 LEGEND2 LEGEND3 LEGEND4 LEGEND5 LEGEND6 LEGEND7 LEGEND8
# define LEGEND18 LEGEND9 LEGEND10 LEGEND11 LEGEND12 LEGEND13 LEGEND14 LEGEND15 LEGEND16
# define LEGEND LEGEND17 LEGEND18

#endif
