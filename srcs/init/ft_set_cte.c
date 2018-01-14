/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_cte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:55:44 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 15:30:07 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_set_cte.c                                             |
**   |     ft_set_cte(4 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <fdf.h>

int			ft_set_cte(t_a *a)
{
	a->zoom_speed = (double)a->map_h / ZOOM_SPEED * (double)a->zoom / 30;
	a->para_cte = (PARA_CTE / pow(a->max_z * ((a->max_z < 5) ? 10 : 1), 2) *
			a->zoom) * 5 * a->add_cte;
	a->isom_cte1 = (ISOM_CTE1 / a->max_z * 3) * 100;
	a->isom_cte2 = (ISOM_CTE2 / a->max_z * 3) * 100;
	return (1);
}
