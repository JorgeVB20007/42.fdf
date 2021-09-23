/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:18:40 by jvacaris          #+#    #+#             */
/*   Updated: 2021/09/21 20:18:42 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_par	doingsomecallocs(t_par par)
{
	int	fd;

	par.map = ft_calloc(sizeof(int *), par.somx);
	par.mapx = ft_calloc(sizeof(int *), par.somx);
	par.mapy = ft_calloc(sizeof(int *), par.somx);
	fd = 0;
	while (fd < par.somx)
	{
		par.map[fd] = ft_calloc(sizeof(int), par.somy);
		par.mapx[fd] = ft_calloc(sizeof(int), par.somy);
		par.mapy[fd] = ft_calloc(sizeof(int), par.somy);
		fd++;
	}
	return (par);
}

t_par	doingsplitstwo(t_par par, char **first_split)
{
	int		x;
	int		y;
	char	**second_split;

	y = 0;
	while (y < par.somy)
	{
		x = 0;
		second_split = ft_split(first_split[y], ' ');
		while (second_split[x] != NULL)
		{
			if (!ft_isdigit(second_split[x][0]))
				par.map[x][y] = 0;
			else
				par.map[x][y] = ft_atoi(second_split[x]);
			x++;
		}
		while (x < par.somx)
			par.map[x++][y] = 0;
		y++;
	}
	return (par);
}

t_par	doingsplits(t_par par, char *full_line)
{
	char	**first_split;
	char	**second_split;
	int		x;
	int		y;

	y = 0;
	x = 0;
	first_split = ft_split(full_line, '\n');
	par.somx = 0;
	while (first_split[y] != NULL)
	{
		second_split = ft_split(first_split[y], ' ');
		while (second_split[x] != NULL)
			x++;
		if (x > par.somx)
			par.somx = x;
		y++;
	}
	par.somy = y;
	par = doingsomecallocs(par);
	par = doingsplitstwo(par, first_split);
	return (par);
}

t_par	createstruct(char **argv)
{
	int		fd;
	char	*linetoadd;
	char	*full_line;
	t_par	par;

	fd = open(argv[1], 0);
	full_line = ft_calloc(1, 1);
	par.somy = 0;
	while (get_next_line(fd, &linetoadd) > 0)
	{
		full_line = ft_strjoin(full_line, "\n");
		full_line = ft_strjoin(full_line, linetoadd);
		par.somy++;
	}
	if (linetoadd[1] == ' ')
		par.somy++;
	full_line = ft_strjoin(full_line, "\n");
	full_line = ft_strjoin(full_line, linetoadd);
	full_line = ft_strjoin(full_line, "\n\0");
	par = doingsplits(par, full_line);
	par.soa = TX / (sqrt(2.0) * 1.1 * ((par.somx / 2) + (par.somy / 2)));
	par.angle = 6.0;
	par.pcx = 0;
	par.pcy = 0;
	close (fd);
	return (par);
}
