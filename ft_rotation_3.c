/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:29:55 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/08 20:29:59 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_string_to_win_2(t_data *img)
{
	mlx_string_put((*img).mlx, (*img).mlx_win, 0, 160,
		0xFFFFFF, "DECREASE HEIGHT : J");
	mlx_string_put((*img).mlx, (*img).mlx_win, 0, 180,
		0xFFFFFF, "CHANGE PERSPECTIVE : P");
	mlx_string_put((*img).mlx, (*img).mlx_win, 0, 200,
		0xFFFFFF, "RESET PESPERCTIVE : R");
	mlx_string_put((*img).mlx, (*img).mlx_win, 0, 220,
		0xFFFFFF, "ROTATE DOWN : S");
	mlx_string_put((*img).mlx, (*img).mlx_win, 0, 240,
		0xFFFFFF, "ROTATE LEFT : A");
	mlx_string_put((*img).mlx, (*img).mlx_win, 0, 260,
		0xFFFFFF, "ROTATE RIGHT : D");
	mlx_string_put((*img).mlx, (*img).mlx_win, 0, 280,
		0xFFFFFF, "EXIT : ESCAPE");
}

void	iso_rot_l(int *x, int *y, int z, t_graphics *graphical)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_y - previous_x) * 0.6 - z
		+ (*graphical).elements_nb + (*graphical).lines_nb;
	*y = (previous_x + previous_y) - ((*graphical).lines_nb
			+ (*graphical).elements_nb);
}

void	ft_draw_horizontal_l(t_graphics *graphical,
		t_map_element *point, t_data *img, t_indexes *size)
{
	int			i;
	t_positions	pos;

	i = 0;
	while (i < (*graphical).points_number - 1)
	{
		if (point[i].x == (*graphical).elements_nb - 1)
			i++;
		pos.x0 = point[i].x * (*size).zoom;
		pos.x1 = point[i + 1].x * (*size).zoom;
		pos.y0 = point[i].y * (*size).zoom;
		pos.y1 = point[i + 1].y * (*size).zoom;
		iso_rot_l(&pos.x0, &pos.y0, point[i].z * (*size).zoom_height,
			graphical);
		iso_rot_l(&pos.x1, &pos.y1, point[i + 1].z * (*size).zoom_height,
			graphical);
		bresenham(img, pos, point[i + 1].color, size);
		i++;
	}
}

void	ft_draw_vertical_l(t_graphics *graphical,
		t_map_element *point, t_data *img, t_indexes *size)
{
	int			i;
	t_positions	pos;

	i = 0;
	while (i < (*graphical).points_number - (*graphical).elements_nb)
	{
		pos.x0 = point[i].x * (*size).zoom;
		pos.x1 = point[i + (*graphical).elements_nb].x * (*size).zoom;
		pos.y1 = point[i + (*graphical).elements_nb].y * (*size).zoom;
		pos.y0 = point[i].y * (*size).zoom;
		iso_rot_l(&pos.x0, &pos.y0, point[i].z
			* (*size).zoom_height, graphical);
		iso_rot_l(&pos.x1, &pos.y1, point[i + (*graphical).elements_nb].z
			* (*size).zoom_height, graphical);
		bresenham(img, pos, point[i].color, size);
		i++;
	}
}
