#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <unistd.h>
# include <mlx.h>

# define TX	1000
# define TY 1000
# define SOA 40

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
	int		centerx;
	int		centery;
	int		prevcenterx;
	int		prevcentery;
	int		highest;
	int		lowest;
	float	angle;
}					t_par;

typedef struct s_line
{
	int	xi;
	int	yi;
	int	xf;
	int	yf;
	int	xa;
	int	ya;
}					t_line;

int		main(int argc, char **argv);
t_par	createstruct(char **argv);
void	makinglines(t_par par, void *gnrl_ptr, void *win_ptr);
t_par	calculatemappoints(t_par par, void *gnrl_ptr, void *win_ptr);

#endif