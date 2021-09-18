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

int main(int argc, char **argv)
{
	void	*gnrl_ptr;
	void	*win_ptr;
	t_par	par;

	gnrl_ptr = mlx_init();
	if (argc != 2)
		exit(0);
	par = createstruct(argv);
	win_ptr = mlx_new_window(gnrl_ptr, TX, TY, "J.V.B.");
	par = calculatemappoints(par, gnrl_ptr, win_ptr);
	makinglines(par, gnrl_ptr, win_ptr);
	printmaps(par);
	mlx_loop(gnrl_ptr);
}