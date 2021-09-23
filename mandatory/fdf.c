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

#include "../includes/fdf.h"

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
	if (par.somx == 1 && par.somy == 1)
		mlx_pixel_put (par.gnrl_ptr, par.win_ptr, TX / 2, TY / 2, 16776960);
	if (!par.somx && !par.somy)
		return (par);
	makinglines(par);
	par = resetmaps(par);
	return (par);
}

int	main(int argc, char **argv)
{
	t_par	par;
	void	*gnrl_ptr;

	if (argc != 2)
		exit(0);
	par = createstruct(argv);
	gnrl_ptr = mlx_init();
	par.gnrl_ptr = gnrl_ptr;
	par.win_ptr = mlx_new_window(gnrl_ptr, TX, TY, "jvacaris' fdf");
	par = magic_happening(par);
	mlx_key_hook(par.win_ptr, key_pressed, (void *)0);
	mlx_loop(par.gnrl_ptr);
}
