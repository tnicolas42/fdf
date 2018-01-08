/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 19:35:34 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 17:39:11 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | init.c                                                   |
**   |     ft_init_a(16 lines)                                  |
**   |     ft_init_file(45 lines)                               |
**   |         MEUUUU too many lines                            |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <fdf.h>

void		ft_init_a(t_a *a)
{
	a->width = WIDTH;
	a->height = HEIGHT;
	a->img.bpp = 32;
	a->img.sz_ln = a->width * 4;
	a->img.endian = 0;
	a->map = NULL;
	if (!(a->mlx = mlx_init()))
		ft_error();
	if (!(a->win = mlx_new_window(a->mlx, a->width, a->height, "fdf")))
		ft_error();
	if (!(a->img.img = mlx_new_image(a->mlx, a->width, a->height)))
		ft_error();
	if (!(a->img.str = mlx_get_data_addr(a->img.img, &a->img.bpp, &a->img.sz_ln,
			&a->img.endian)))
		ft_error();
}

void		ft_init_file(t_a *a, char *file)
{
	char	*line;
	char	**tab;
	int		i;
	int		fd;
	t_map	*new_map;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error();
	while (get_next_line(fd, &line) == GNL_LINE_READ)
	{
		tab = ft_strsplit(line, ' ');
		i = -1;
		while (tab[++i] != 0)
			;
		if (!(new_map = malloc(sizeof(t_map))))
			ft_error();
		if (!(new_map->m = malloc(sizeof(new_map->m) * i)))
			ft_error();
		new_map->w = i;
		i = -1;
		while (++i < new_map->w)
		{
			new_map->m[i] = ft_atoi(tab[i]);
		}
		new_map->next = a->map;
		a->map = new_map;
		ft_fruit(2, line, tab);
	}
	close(fd);

	////////////////////////////////////////////
	new_map = a->map;
	while (new_map->next)
	{
		i = -1;
		while (++i < new_map->w)
			ft_printf("%3d", new_map->m[i]);
		ft_printf("\n");
		new_map = new_map->next;
	}
	i = -1;
	while (++i < new_map->w)
		ft_printf("%3d", new_map->m[i]);
	ft_printf("\n");
	///////////////////////////////////////////
}