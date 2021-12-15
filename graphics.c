/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:19:24 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/07 11:05:21 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_zoom(t_indexes *size, int elements_nb, int max_z)
{
	if (max_z < 5)
		(*size).zoom_height = 30;
	else if (max_z < 50)
		(*size).zoom_height = 10;
	else
		(*size).zoom_height = 1;
	if (elements_nb < 10)
		(*size).zoom = 50;
	else if (elements_nb < 50)
		(*size).zoom = 25;
	else if (elements_nb < 100)
		(*size).zoom = 5;
	else if (elements_nb < 250)
		(*size).zoom = 3;
	else
		(*size).zoom = 1;
}

int	ft_exit(t_map_element *point)
{
	free(point);
	exit(1);
}

void	ft_set_zoom_args(t_indexes *size, int c_size, int z_size)
{
	(*size).zoom_height = z_size;
	(*size).zoom = c_size;
}

void	ft_put_string_to_win(t_data *img)
{
	mlx_string_put((*img).mlx, (*img).mlx_win, 0, 0,
		0x00FFFF, "42 FDF BY ATOUHAMI :");
	mlx_string_put((*img).mlx, (*img).mlx_win, 0, 20,
		0xFFFFFF, "MOVE UP : Up arrow key");
	mlx_string_put((*img).mlx, (*img).mlx_win, 0, 40,
		0xFFFFFF, "MOVE DOWN : Down arrow key");
	mlx_string_put((*img).mlx, (*img).mlx_win, 0, 60,
		0xFFFFFF, "MOVE Left : Left arrow key");
	mlx_string_put((*img).mlx, (*img).mlx_win, 0, 80,
		0xFFFFFF, "MOVE right : Right arrow key");
	mlx_string_put((*img).mlx, (*img).mlx_win, 0, 100,
		0xFFFFFF, "ZOOM IN : I");
	mlx_string_put((*img).mlx, (*img).mlx_win, 0, 120,
		0xFFFFFF, "ZOOM OUT : O");
	mlx_string_put((*img).mlx, (*img).mlx_win, 0, 140,
		0xFFFFFF, "INCREASE HEIGHT : H");
	ft_put_string_to_win_2(img);
}

void	graphics_engine(t_map_element *point
		, t_graphics graphical, int argc, char *argv[])
{
	t_data			img;
	t_indexes		size;
	t_structures	ss;

	img.start_x = 0;
	img.start_y = 0;
	ft_set_zoom(&size, graphical.elements_nb, graphical.max_z);
	size.x = (graphical.elements_nb + graphical.lines_nb) * size.zoom;
	size.y = (graphical.elements_nb + graphical.lines_nb) * size.zoom * 1.5;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, size.x, size.y, "fdf");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	if (argc == 4 && atoi(argv[2]) < 10000 && atoi(argv[3]) < 10000
		&& atoi(argv[2]) > 0 && atoi(argv[3]) > 0)
		ft_set_zoom_args(&size, atoi(argv[2]), atoi(argv[3]));
	ft_draw_horizontal(&graphical, point, &img, &size);
	ft_draw_vertical(&graphical, point, &img, &size);
	ss.point = point;
	ss.graphical = &graphical;
	ss.img = &img;
	ss.size = &size;
	mlx_hook(img.mlx_win, 17, 2, &ft_exit, ss.point);
	mlx_key_hook(img.mlx_win, &ft_buttons, (void *)&ss);
	ft_put_string_to_win(&img);
	mlx_loop(img.mlx);
}
