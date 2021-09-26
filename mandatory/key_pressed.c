/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:18:53 by jvacaris          #+#    #+#             */
/*   Updated: 2021/09/21 20:18:55 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_pressed(int keycode, t_par *par)
{
	int	a;

	a = 0;
	if (keycode == 53)
	{
		while (a < (*par).somx)
		{
			free((*par).map[a]);
			free((*par).mapx[a]);
			free((*par).mapy[a]);
			a++;
		}
		free((*par).map);
		free((*par).mapx);
		free((*par).mapy);
		mlx_clear_window((*par).gnrl_ptr, (*par).win_ptr);
		mlx_destroy_window((*par).gnrl_ptr, (*par).win_ptr);
		exit (0);
	}
	return (0);
}
