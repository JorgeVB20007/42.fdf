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

#include "../includes/fdf_bonus.h"

static t_par	doingsomecallocs_bonus(t_par par)
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

t_par	doingsplitstwo_bonus(t_par par, char **first_split)
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
			free (second_split[x++]);
		}
		free (second_split);
		free (first_split[y]);
		while (x < par.somx)
			par.map[x++][y] = 0;
		y++;
	}
	free (first_split[y]);
	return (par);
}

t_par	doingsplits_bonus(t_par par, char *full_line)
{
	char	**first_split;
	char	**second_split;
	int		x;
	int		y;

	y = 0;
	first_split = ft_split(full_line, '\n');
	par.somx = 0;
	while (first_split[y] != NULL)
	{
		x = 0;
		second_split = ft_split(first_split[y++], ' ');
		while (second_split[x] != NULL)
			free (second_split[x++]);
		free (second_split);
		if (x > par.somx)
			par.somx = x;
	}
	par.somy = y;
	par = doingsomecallocs_bonus(par);
	par = doingsplitstwo_bonus(par, first_split);
	free (first_split);
	return (par);
}

static t_par	default_par_bonus(t_par par)
{
	par.soa = TX / (sqrt(2.0) * 1.1 * ((par.somx / 2) + (par.somy / 2)));
	par.angle = 6.0;
	par.pcx = 0;
	par.pcy = 0;
	return (par);
}

t_par	createstruct_bonus(char **argv)
{
	int		fd;
	char	*linetoadd;
	char	*full_line;
	t_par	par;

	fd = open(argv[1], 0);
	full_line = ft_calloc(1, 1);
	linetoadd = ft_calloc(1, 100001);
	par.somy = 0;
	while (read(fd, linetoadd, 100000) > 0)
	{
		full_line = ft_strjoin(full_line, linetoadd);
		if (linetoadd[0] == '\n')
			par.somy++;
		free (linetoadd);
		linetoadd = ft_calloc(1, 100001);
	}
	free (linetoadd);
	full_line = ft_strjoin(full_line, "\n\0");
	par = doingsplits_bonus(par, full_line);
	free (full_line);
	par = default_par_bonus(par);
	close (fd);
	return (par);
}
