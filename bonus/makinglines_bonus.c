/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makinglines_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 22:33:26 by jvacaris          #+#    #+#             */
/*   Updated: 2021/09/26 22:33:29 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	tracelinetwo_bonus(t_line line, t_par par, int xi, int yi)
{
	int	a;
	int	dir;

	a = 0;
	dir = line.dfx / (abs(line.dfx));
	while (a <= abs(line.dfx))
	{
		mlx_pixel_put (par.gnrl_ptr, par.win_ptr, xi + ((line.dfx \
		/ (abs(line.dfx))) * a), (int)(yi + ((float)line.dfy / \
		fabsf((float)line.dfx)) * (float)a), COLOR);
		a++;
	}
}

void	traceline_bonus(t_line line, t_par par, int xi, int yi)
{
	int	a;
	int	dir;

	a = 0;
	if (abs(line.dfx) > abs(line.dfy))
		tracelinetwo_bonus(line, par, xi, yi);
	else if (abs(line.dfx) <= abs(line.dfy))
	{
		dir = line.dfy / (abs(line.dfy));
		while (a <= abs(line.dfy))
		{
			mlx_pixel_put (par.gnrl_ptr, par.win_ptr, (int)(xi + \
			((float)line.dfx / fabsf((float)line.dfy)) * (float)a), \
			yi + ((line.dfy / (abs(line.dfy))) * a), COLOR);
			a++;
		}
	}
}

void	makinglinesx_bonus(t_par par)
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
				traceline_bonus(line, par, par.mapx[x][y], par.mapy[x][y]);
			y++;
		}
		x++;
	}
}

void	makinglines_bonus(t_par par)
{
	t_line	line;
	int		x;
	int		y;

	makinglinesx_bonus(par);
	y = 0;
	while (y + 1 < par.somy)
	{
		x = 0;
		while (x < par.somx)
		{
			line.dfx = par.mapx[x][y + 1] - par.mapx[x][y];
			line.dfy = par.mapy[x][y + 1] - par.mapy[x][y];
			if (line.dfy || line.dfx)
				traceline_bonus(line, par, par.mapx[x][y], par.mapy[x][y]);
			x++;
		}
		y++;
	}
}
