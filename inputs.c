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

#include "fdf.h"

static int	countandcheckbs(char *str)
{
	int		n;
	int		a;

	a = 0;
	n = 0;
	while (str[a])
	{
		while (str[a] == ' ' || str[a] == '\n')
			a++;
		if (str[a] == '-' || str[a] == '+')
			a++;
		if (ft_isdigit(str[a]))
		{
			while (ft_isdigit(str[a]))
				a++;
			n++;
			if ((str[a] != ' ' && str[a] != '\n') && str[a])
				exit (0);
		}
		else if (str[a])
			exit (0);
		while ((str[a] == ' ' || str[a] == '\n') && str[a])
			a++;
	}
	return (n);
}

t_par	putthingsinmaptwo(t_par par, char *full_line, int y, int *p)
{
	int	x;

	x = 0;
	while (x < par.somx)
	{
		if (full_line[*p] == '\n')
			(*p)++;
		while (full_line[*p] == ' ')
			(*p)++;
		par.map[x][y] = ft_atoi(&full_line[(*p)++]);
		if (par.map[x][y] > par.highest)
			par.highest = par.map[x][y];
		if (par.map[x][y] < par.lowest)
			par.lowest = par.map[x][y];
		while (ft_isdigit(full_line[*p]))
			(*p)++;
		x++;
	}
	return (par);
}

t_par	putthingsinmap(t_par par, char	*full_line)
{
	int	x;
	int	y;
	int	p;

	y = 0;
	p = 0;
	par.highest = -2147483648;
	par.lowest = 2147483647;
	while (y < par.somy)
	{
		par = putthingsinmaptwo(par, full_line, y, &p);
		y++;
	}
	return (par);
}

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
	full_line = ft_strjoin(full_line, "\n");
	full_line = ft_strjoin(full_line, linetoadd);
	par.somx = countandcheckbs(full_line) / par.somy;
	par = doingsomecallocs(par);
	par = putthingsinmap(par, full_line);
	par.soa = SOA;
	par.angle = 6.0;
	par.pcx = 0;
	par.pcy = 0;
	return (par);
}
