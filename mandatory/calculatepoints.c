/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculatepoints.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:17:40 by jvacaris          #+#    #+#             */
/*   Updated: 2021/09/21 20:17:42 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_par	calculatemappointstwo(t_par par)
{
	int	x;
	int	y;

	x = 0;
	while (x < par.somx)
	{
		y = 0;
		while (y < par.somy)
		{
			par.mapx[x][y] = ((sqrt(2.0) * 0.5 * (float)x) - (sqrt(2.0) * 0.5 \
			* (float)y)) * par.soa + par.cx + par.pcx;
			par.mapy[x][y] = (sqrt(2.0) * 0.5 * sin((float)M_PI / par.angle) * \
			(y + x)) * par.soa - (0.5 * cos((float)M_PI / par.angle) * \
			(par.map[x][y])) * (par.soa) + par.cy + par.pcy;
			y++;
		}
		x++;
	}
	return (par);
}

t_par	calculatemappoints(t_par par)
{
	par.cx = TX / 2 - (sqrt(2.0) * (par.somx / 4.0 - par.somy / 4.0) * par.soa);
	if (par.somx > par.somy)
		par.cy = TY / 2 - (sqrt(2.0) * sin((float)M_PI / par.angle) \
		* (par.somx / 3.0) * par.soa);
	else
		par.cy = TY / 2 - (sqrt(2.0) * sin((float)M_PI / par.angle) \
		* (par.somy / 3.0) * par.soa);
	par = calculatemappointstwo(par);
	return (par);
}
