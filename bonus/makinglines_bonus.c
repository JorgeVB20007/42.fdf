/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makinglines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:19:04 by jvacaris          #+#    #+#             */
/*   Updated: 2021/09/21 20:19:06 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
t_line	initline(void)
{
	t_line	line;

	line.xi = 0;
	line.yi = 0;
	line.xf = 0;
	line.yf = 0;
	line.xa = 0;
	line.ya = 0;
	return (line);
}
*/
void	tracelinetwo(t_line line, t_par par, int xi, int yi)
{
	int	a;
	int	dir;

	a = 0;
	dir = line.dfx / (abs(line.dfx));
	while (a <= abs(line.dfx))
	{
		mlx_pixel_put (par.gnrl_ptr, par.win_ptr, xi + ((line.dfx \
		/ (abs(line.dfx))) * a), (int)(yi + ((float)line.dfy / \
		fabsf((float)line.dfx)) * (float)a), 16776960);
		a++;
	}
}

void	traceline(t_line line, t_par par, int xi, int yi)
{
	int	a;
	int	dir;

	a = 0;
	if (abs(line.dfx) > abs(line.dfy))
		tracelinetwo(line, par, xi, yi);
	else if (abs(line.dfx) <= abs(line.dfy))
	{
		dir = line.dfy / (abs(line.dfy));
		while (a <= abs(line.dfy))
		{
			mlx_pixel_put (par.gnrl_ptr, par.win_ptr, (int)(xi + \
			((float)line.dfx / fabsf((float)line.dfy)) * (float)a), \
			yi + ((line.dfy / (abs(line.dfy))) * a), 16753920);
			a++;
		}
	}
}

void	makinglinesx(t_par par)
{
	t_line	line;
	int		x;
	int		y;

	x = 0;
	while (x + 1 < par.somx)
	{
		y = 0;
		while (y < par.somy)
		{
			line.dfx = par.mapx[x + 1][y] - par.mapx[x][y];
			line.dfy = par.mapy[x + 1][y] - par.mapy[x][y];
			if (line.dfy || line.dfx)
				traceline(line, par, par.mapx[x][y], par.mapy[x][y]);
			y++;
		}
		x++;
	}
}

void	makinglines(t_par par)
{
	t_line	line;
	int		x;
	int		y;

	makinglinesx(par);
	y = 0;
	while (y + 1 < par.somy)
	{
		x = 0;
		while (x < par.somx)
		{
			line.dfx = par.mapx[x][y + 1] - par.mapx[x][y];
			line.dfy = par.mapy[x][y + 1] - par.mapy[x][y];
			if (line.dfy || line.dfx)
				traceline(line, par, par.mapx[x][y], par.mapy[x][y]);
			x++;
		}
		y++;
	}
}
