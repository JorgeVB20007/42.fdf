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
			if ((str[a] != ' ' || str[a] == '\n') && str[a])
				exit (0);
		}
		else if (str[a])
			exit (0);
		while ((str[a] == ' ' || str[a] == '\n') && str[a])
			a++;
	}
	return (n);
}

t_par	putthingsinmap(t_par par, char	*full_line)
{
	int	x;
	int	y;
	int p;

	x = 0;
	y = 0;
	p = 0;
	while (x < par.somx)
	{
		y = 0;
		if (full_line[p] == '\n')
			p++;
		while (y < par.somy)
		{
			while (full_line[p] == ' ' && full_line[p])
				p++;
/*			if (full_line[p] == '\n')
				break ;*/
			par.map[x][y] = ft_atoi(&full_line[p++]);
			while (ft_isdigit(full_line[p]) && full_line[p])
				p++;
			y++;
		}
		p++;
		x++;
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
	par.somx = countandcheckbs(full_line) / par.somy;
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
	par = putthingsinmap(par, full_line);
	par.soa = SOA;
	return (par);
}
