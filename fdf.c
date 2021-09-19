#include "fdf.h"

void	printmaps(t_par par)
{
	int	x;
	int	y;

	y = 0;
	printf("\n\n ----  Map given (top view) ----\n");
	while (par.somy > y)
	{
		x = 0;
		while (par.somx > x)
		{
			printf("%3d ", par.map[x][y]);
			x++;
		}
		printf("\n");
		y++;
	}
	y = 0;
	printf("\n\n ----  Map point x coordinate ----\n");
	while (par.somy > y)
	{
		x = 0;
		while (par.somx > x)
		{
			printf("%3d ", par.mapx[x][y]);
			x++;
		}
		printf("\n");
		y++;
	}
	y = 0;
	printf("\n\n ----  Map point y coordinate ----\n");
	while (par.somy > y)
	{
		x = 0;
		while (par.somx > x)
		{
			printf("%3d ", par.mapy[x][y]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	magic_happening(t_par *par, void *gnrl_ptr, void *win_ptr)
{
	int f = -1;
	while (++f < TX)
	{
		mlx_pixel_put(gnrl_ptr, win_ptr, f, TX/4, 4342338);
		mlx_pixel_put(gnrl_ptr, win_ptr, TX/4, f, 4342338);
		mlx_pixel_put(gnrl_ptr, win_ptr, f, 3*TX/4, 4342338);
		mlx_pixel_put(gnrl_ptr, win_ptr, 3*TX/4, f, 4342338);
		mlx_pixel_put(gnrl_ptr, win_ptr, f, TX/2, 7895160);
		mlx_pixel_put(gnrl_ptr, win_ptr, TX/2, f, 7895160);
	}
	*par = calculatemappoints(*par, gnrl_ptr, win_ptr);
	makinglines(*par, gnrl_ptr, win_ptr);
	printmaps(*par);
}

int	up_arrow(t_par par)
{
	par.soa--;
	magic_happening(&par, par.gnrl_ptr, par.win_ptr);
	return (0);
}

int main(int argc, char **argv)
{
	t_par	par;

	par.gnrl_ptr = mlx_init();
	if (argc != 2)
		exit(0);
	par = createstruct(argv);
	par.win_ptr = mlx_new_window(par.gnrl_ptr, TX, TY, "|");
	magic_happening(&par, par.gnrl_ptr, par.win_ptr);
	mlx_key_hook(par.win_ptr, up_arrow, &par);
	mlx_loop(par.gnrl_ptr);
}