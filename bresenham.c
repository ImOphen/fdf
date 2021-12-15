/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:11:21 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/06 14:16:55 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	iso_2d(int *x, int *y)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x + previous_y);
	*y = (previous_y - previous_x);
}

void	bres_assign(t_bresenham *brs, t_positions pos)
{
	(*brs).dx = abs(pos.x1 - pos.x0);
	(*brs).dy = -abs(pos.y1 - pos.y0);
	(*brs).err = (*brs).dx + (*brs).dy;
	if (pos.x0 < pos.x1)
		(*brs).sx = 1;
	else
		(*brs).sx = -1;
	if (pos.y0 < pos.y1)
		(*brs).sy = 1;
	else
		(*brs).sy = -1;
}

void	bresenham(t_data *img, t_positions pos, int color, t_indexes *size)
{
	t_bresenham	brs;

	bres_assign(&brs, pos);
	while (1)
	{
		if (pos.x0 + (*img).start_x < (*size).x && pos.y0
			+ (*img).start_y + ((*size).y / 2) < (*size).y
			&& pos.x0 + (*img).start_x > 0 && pos.y0
			+ (*img).start_y + ((*size).y / 2) > 0)
			mlx_pixel_put(img -> mlx, img -> mlx_win, pos.x0 + (*img).start_x,
				pos.y0 + (*img).start_y + ((*size).y / 2), color);
		if (pos.x0 == pos.x1 && pos.y0 == pos.y1)
			break ;
		brs.e2 = 2 * brs.err;
		if (brs.e2 >= brs.dy)
		{
			brs.err += brs.dy;
			pos.x0 += brs.sx;
		}
		if (brs.e2 <= brs.dx)
		{
			brs.err += brs.dx;
			pos.y0 += brs.sy;
		}
	}
}
