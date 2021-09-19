#include "fdf.h"

/*
t_line params:

	int	xi;
	int	yi;
	int	xf;
	int	yf;
	int	xa;
	int	ya;
*/

t_line	initline(void)
{
	t_line line;

	line.xi = 0;
	line.yi = 0;
	line.xf = 0;
	line.yf = 0;
	line.xa = 0;
	line.ya = 0;
	return (line);
}

void	traceline(int difx, int dify, int xi, int yi, void *gnrl_ptr, void *win_ptr)
{
	int	a;
	int	dir;

	a = 0;
	if (abs(difx) > abs(dify))
	{
		dir = difx / (abs(difx));
		while (a < abs(difx))
		{
			mlx_pixel_put (gnrl_ptr, win_ptr, xi + ((difx / (abs(difx))) * a), (int)(yi + ((float)dify / fabsf((float)difx)) * (float)a), 16776960);
//			printf("\nPixel placed at (%d,%d)", xi + (difx * a), yi + (dify / abs(difx)) * a);
			a++;
		}
	}
	else if (abs(difx) < abs(dify))
	{
		dir = dify / (abs(dify));
		while (a < abs(dify))
		{
			mlx_pixel_put (gnrl_ptr, win_ptr, (int)(xi + ((float)difx / fabsf((float)dify)) * (float)a), yi + ((dify / (abs(dify))) * a), 16753920);
//			printf("\nPixel placed at (%d,%d)", xi + (difx * a), yi + (dify / abs(difx)) * a);
			a++;
		}
	}
}

void	makinglines(t_par par, void *gnrl_ptr, void *win_ptr)
{
	int	x;
	int y;
	int	difx;
	int	dify;

	x = 0;
	while (x + 1 < par.somx)
	{
		y = 0;
		while (y < par.somy)
		{
			difx = par.mapx[x + 1][y] - par.mapx[x][y];
			dify = par.mapy[x + 1][y] - par.mapy[x][y];
			if (dify || difx)
				traceline(difx, dify, par.mapx[x][y], par.mapy[x][y], gnrl_ptr, win_ptr);
			y++;
		}
		x++;
	}
	y = 0;
	while (y + 1 < par.somy)
	{
		x = 0;
		while (x < par.somx)
		{
			difx = par.mapx[x][y + 1] - par.mapx[x][y];
			dify = par.mapy[x][y + 1] - par.mapy[x][y];
			if (dify || difx)
				traceline(difx, dify, par.mapx[x][y], par.mapy[x][y], gnrl_ptr, win_ptr);
			x++;
		}
		y++;
	}
//	mlx_pixel_put (gnrl_ptr, win_ptr, 250, 250, 16777215);

}
