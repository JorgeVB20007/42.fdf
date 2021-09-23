/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:18:53 by jvacaris          #+#    #+#             */
/*   Updated: 2021/09/21 20:18:55 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	eraser_bonus(t_par par)
{
	int	x;
	int	y;

	x = 0;
	while (x < TX)
	{
		y = 0;
		while (y < TY)
		{
			mlx_pixel_put(par.gnrl_ptr, par.win_ptr, x, y, 0);
			y++;
		}
		x++;
	}
}

float	angles_bonus(float prevang, int dir)
{
	int	backtodegrees;

	backtodegrees = 180 / prevang;
	if (backtodegrees > 360)
		backtodegrees -= 360;
	else if (backtodegrees < 0)
		backtodegrees = 360 - backtodegrees;
	backtodegrees = backtodegrees + (15 * dir);
	if (backtodegrees == 0)
		backtodegrees = 360;
	return (180.0 / (float)backtodegrees);
}

static void	resetview_bonus(t_par *par)
{
	(*par).angle = 6.0;
	(*par).pcx = 0;
	(*par).pcy = 0;
	(*par).soa = TX / (sqrt(2.0) * 1.15 * \
	(((*par).somx / 2) + ((*par).somy / 2)) + 1);
}

int	key_pressed_bonus(int keycode, t_par *par)
{
	if (keycode == 30)
		(*par).soa *= 1.2;
	else if (keycode == 44 && (*par).soa > 1.3)
		(*par).soa /= 1.2;
	else if (keycode == 13)
		(*par).pcy += (TY / 10);
	else if (keycode == 0)
		(*par).pcx += (TX / 10);
	else if (keycode == 1)
		(*par).pcy -= (TY / 10);
	else if (keycode == 2)
		(*par).pcx -= (TX / 10);
	else if (keycode == 125)
		(*par).angle = angles_bonus((*par).angle, -1);
	else if (keycode == 126)
		(*par).angle = angles_bonus((*par).angle, 1);
	else if (keycode == 53)
		exit (0);
	else if (keycode == 29)
		resetview_bonus(par);
	eraser_bonus(*par);
	*par = magic_happening_bonus(*par);
	return (0);
}
