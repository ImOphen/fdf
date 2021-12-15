/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buttons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:44:09 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/07 11:44:11 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_buttons_one(int keycode, t_structures *ss)
{
	if (keycode == 34)
	{
		mlx_clear_window(ss -> img -> mlx, ss -> img -> mlx_win);
		(*ss).size->zoom += 1;
		ft_draw_horizontal((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
		ft_draw_vertical((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
	}
	if (keycode == 31)
	{
		mlx_clear_window(ss -> img -> mlx, ss -> img -> mlx_win);
		(*ss).size->zoom -= 1;
		ft_draw_horizontal((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
		ft_draw_vertical((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
	}
	if (keycode == 126)
	{
		mlx_clear_window(ss -> img -> mlx, ss -> img -> mlx_win);
		(*ss).img->start_y -= 10;
		ft_draw_horizontal((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
		ft_draw_vertical((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
	}
	return (0);
}

int	ft_buttons_two(int keycode, t_structures *ss)
{
	if (keycode == 123)
	{
		mlx_clear_window(ss -> img -> mlx, ss -> img -> mlx_win);
		(*ss).img->start_x -= 10;
		ft_draw_horizontal((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
		ft_draw_vertical((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
	}
	if (keycode == 125)
	{
		mlx_clear_window(ss -> img -> mlx, ss -> img -> mlx_win);
		(*ss).img->start_y += 10;
		ft_draw_horizontal((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
		ft_draw_vertical((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
	}
	if (keycode == 124)
	{
		mlx_clear_window(ss -> img -> mlx, ss -> img -> mlx_win);
		(*ss).img->start_x += 10;
		ft_draw_horizontal((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
		ft_draw_vertical((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
	}
	return (0);
}

int	ft_buttons_three(int keycode, t_structures *ss)
{
	if (keycode == 35)
	{
		mlx_clear_window(ss -> img -> mlx, ss -> img -> mlx_win);
		ft_draw_horizontal_2d((*ss).graphical, (*ss).point,
			(*ss).img, (*ss).size);
		ft_draw_vertical_2d((*ss).graphical, (*ss).point,
			(*ss).img, (*ss).size);
	}
	if (keycode == 15)
	{
		mlx_clear_window(ss -> img -> mlx, ss -> img -> mlx_win);
		ft_draw_horizontal((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
		ft_draw_vertical((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
	}
	if (keycode == 4)
	{
		mlx_clear_window(ss -> img -> mlx, ss -> img -> mlx_win);
		(*ss).size->zoom_height += 2;
		ft_draw_horizontal((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
		ft_draw_vertical((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
	}
	return (0);
}

int	ft_buttons_four(int keycode, t_structures *ss)
{
	if (keycode == 2)
	{
		mlx_clear_window(ss -> img -> mlx, ss -> img -> mlx_win);
		ft_draw_horizontal_r((*ss).graphical, (*ss).point,
			(*ss).img, (*ss).size);
		ft_draw_vertical_r((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
	}
	if (keycode == 0)
	{
		mlx_clear_window(ss -> img -> mlx, ss -> img -> mlx_win);
		ft_draw_horizontal_l((*ss).graphical, (*ss).point,
			(*ss).img, (*ss).size);
		ft_draw_vertical_l((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
	}
	if (keycode == 1)
	{
		mlx_clear_window(ss -> img -> mlx, ss -> img -> mlx_win);
		ft_draw_horizontal_rot((*ss).graphical, (*ss).point,
			(*ss).img, (*ss).size);
		ft_draw_vertical_rot((*ss).graphical,
			(*ss).point, (*ss).img, (*ss).size);
	}
	return (0);
}

int	ft_buttons(int keycode, t_structures *ss)
{
	if (keycode == 53)
	{
		free(ss -> point);
		exit(1);
	}
	ft_buttons_one(keycode, ss);
	ft_buttons_two(keycode, ss);
	ft_buttons_three(keycode, ss);
	ft_buttons_four(keycode, ss);
	if (keycode == 38)
	{
		mlx_clear_window(ss -> img -> mlx, ss -> img -> mlx_win);
		(*ss).size->zoom_height -= 2;
		ft_draw_horizontal((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
		ft_draw_vertical((*ss).graphical, (*ss).point, (*ss).img, (*ss).size);
	}
	ft_put_string_to_win((*ss).img);
	return (0);
}
