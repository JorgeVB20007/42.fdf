#include "fdf.h"

t_par	calculatemappoints(t_par par, void *gnrl_ptr, void *win_ptr)
{
	int	x;
	int	y;

	x = 0;
	while (x < par.somx)
	{
		y = 0;
		while (y < par.somy)
		{
			par.mapx[x][y] = ((sqrt((float)2) * 0.5 * (float)x) - (sqrt((float)2) * 0.5 * (float)y)) * par.soa + 500;
			par.mapy[x][y] = (sqrt((float)2) * 0.5 * tan((float)M_PI / 6.0) * (y + x)) * par.soa /*+ ((sqrt((float)2) * 0.5 * tan((float)M_PI / 6.0) * (par.map[x][y])) * par.soa) */+ 300;
			y++;
		}
		x++;
	}
	x = 0;
	while (x < par.somx)
	{
		y = 0;
		while (y < par.somy)
		{
			mlx_pixel_put(gnrl_ptr, win_ptr, par.mapx[x][y], par.mapy[x][y], 4386805);
			mlx_pixel_put(gnrl_ptr, win_ptr, par.mapx[x][y] + 1, par.mapy[x][y], 4386805);
			mlx_pixel_put(gnrl_ptr, win_ptr, par.mapx[x][y], par.mapy[x][y] + 1, 4386805);
			mlx_pixel_put(gnrl_ptr, win_ptr, par.mapx[x][y] - 1, par.mapy[x][y], 4386805);
			mlx_pixel_put(gnrl_ptr, win_ptr, par.mapx[x][y], par.mapy[x][y] - 1, 4386805);
			mlx_pixel_put(gnrl_ptr, win_ptr, par.mapx[x][y] + 2, par.mapy[x][y], 4386805);
			mlx_pixel_put(gnrl_ptr, win_ptr, par.mapx[x][y], par.mapy[x][y] + 2, 4386805);
			mlx_pixel_put(gnrl_ptr, win_ptr, par.mapx[x][y] - 2, par.mapy[x][y], 4386805);
			mlx_pixel_put(gnrl_ptr, win_ptr, par.mapx[x][y], par.mapy[x][y] - 2, 4386805);
			y++;
		}
		x++;
	}
	return (par);
}
