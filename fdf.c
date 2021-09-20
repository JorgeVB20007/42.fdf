#include "fdf.h"

//			vv	DELETE STUFF BELOW  vv

void	printmaps(t_par par)
{
/*	int	x;
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
	}*/
}

// 			^^ DELETE STUFF ABOVE ^^

t_par	resetmaps(t_par	par)
{
	int	x;
	int	y;

	x = 0;
	while (x < par.somx)
	{
		y = 0;
		while (y < par.somy)
		{
			par.mapx[x][y] = 0;
			par.mapy[x][y] = 0;
			par.centerx = 0;
			par.centery = 0;
			par.highest = 0;
			par.lowest = 0;
			y++;
		}
		x++;
	}
	return (par);
}

t_par	magic_happening(t_par par)
{
//			vv	DELETE STUFF BELOW  vv
	int	f;

	f = -1;
	while (++f < TX)
	{
		mlx_pixel_put(par.gnrl_ptr, par.win_ptr, f, TX/4, 4342338);
		mlx_pixel_put(par.gnrl_ptr, par.win_ptr, TX/4, f, 4342338);
		mlx_pixel_put(par.gnrl_ptr, par.win_ptr, f, 3*TX/4, 4342338);
		mlx_pixel_put(par.gnrl_ptr, par.win_ptr, 3*TX/4, f, 4342338);
		mlx_pixel_put(par.gnrl_ptr, par.win_ptr, f, TX/2, 7895160);
		mlx_pixel_put(par.gnrl_ptr, par.win_ptr, TX/2, f, 7895160);
	}
// 			^^ DELETE STUFF ABOVE ^^
	par = calculatemappoints(par, par.gnrl_ptr, par.win_ptr);
	makinglines(par, par.gnrl_ptr, par.win_ptr);
	printmaps(par);
	par = resetmaps(par);
	return (par);
}

void	eraser(t_par par)
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

int	up_arrow(int keycode, t_par *par)
{
	if (keycode == 30)
		(*par).soa *= 1.2;
	if (keycode == 44 && (*par).soa > 5)
		(*par).soa /= 1.2;
	if (keycode == 13)
		(*par).prevcentery += (TY / 10);
	if (keycode == 0)
		(*par).prevcenterx += (TX / 10);
	if (keycode == 1)
		(*par).prevcentery -= (TY / 10);
	if (keycode == 2)
		(*par).prevcenterx -= (TX / 10);
	if (keycode == 125 && (*par).angle < 24)
		(*par).angle *= 1.2;
	if (keycode == 126 && (*par).angle > 2.9)
		(*par).angle /= 1.2;
	if (keycode == 53)
		exit (0);
	eraser(*par);
	*par = magic_happening(*par);
	return (0);
}

int main(int argc, char **argv)
{
	t_par	par;
	void	*gnrl_ptr;

	gnrl_ptr = mlx_init();
	if (argc != 2)
		exit(0);
	par = createstruct(argv);
	par.gnrl_ptr = gnrl_ptr;
	par.win_ptr = mlx_new_window(gnrl_ptr, TX, TY, "|");
	par = magic_happening(par);
	mlx_key_hook(par.win_ptr, up_arrow, &par);
	mlx_loop(par.gnrl_ptr);
}
