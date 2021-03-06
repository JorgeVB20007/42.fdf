/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:18:27 by jvacaris          #+#    #+#             */
/*   Updated: 2021/09/21 20:18:28 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "../libftjvb/libft.h"
# include <string.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>

# define TX	1000
# define TY 1000
# define SOA 40
# define COLOR 16777215

typedef struct s_par
{
	void	*gnrl_ptr;
	void	*win_ptr;
	int		**map;
	int		**mapx;
	int		**mapy;
	int		somx;
	int		somy;
	int		soa;
	int		cx;
	int		cy;
	int		pcx;
	int		pcy;
	int		highest;
	int		lowest;
	float	angle;
}					t_par;

typedef struct s_line
{
	int	dfx;
	int	dfy;
}					t_line;

int		main(int argc, char **argv);
t_par	createstruct_bonus(char **argv);
void	makinglines_bonus(t_par par);
t_par	calculatemappoints_bonus(t_par par);
int		key_pressed_bonus(int keycode, t_par *par);
t_par	magic_happening_bonus(t_par par);

#endif
