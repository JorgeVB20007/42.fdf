/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:18:08 by jvacaris          #+#    #+#             */
/*   Updated: 2021/09/21 20:18:09 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//			vv	DELETE STUFF BELOW  vv
/*
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
*/
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
			par.cx = 0;
			par.cy = 0;
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
	par = calculatemappoints(par);
	makinglines(par);
	par = resetmaps(par);
	return (par);
}

int	main(int argc, char **argv)
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
	mlx_key_hook(par.win_ptr, key_pressed, &par);
	mlx_loop(par.gnrl_ptr);
}
