/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:29:37 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/08 20:29:42 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_rot_r(int *x, int *y, int z, t_graphics *graphical)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = -(previous_y - previous_x) * 0.6 + z + (*graphical).elements_nb
		+ (*graphical).lines_nb;
	*y = (previous_x + previous_y) - ((*graphical).lines_nb
			+ (*graphical).elements_nb);
}

void	ft_draw_horizontal_r(t_graphics *graphical,
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
		iso_rot_r(&pos.x0, &pos.y0, point[i].z * (*size).zoom_height,
			graphical);
		iso_rot_r(&pos.x1, &pos.y1, point[i + 1].z
			* (*size).zoom_height, graphical);
		bresenham(img, pos, point[i + 1].color, size);
		i++;
	}
}

void	ft_draw_vertical_r(t_graphics *graphical,
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
		iso_rot_r(&pos.x0, &pos.y0, point[i].z * (*size).zoom_height,
			graphical);
		iso_rot_r(&pos.x1, &pos.y1, point[i + (*graphical).elements_nb].z
			* (*size).zoom_height, graphical);
		bresenham(img, pos, point[i].color, size);
		i++;
	}
}
