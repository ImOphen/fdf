/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:32:40 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/06 14:09:24 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_elements(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	assign_colors(t_map_element *point, int i, char *hex)
{
	unsigned int	total;
	int				index;

	index = 0;
	total = 0;
	while (hex[index])
	{
		if (hex[index] >= 'A' && hex[index] <= 'F')
			total = (total * 16) + hex[index] - 55;
		else if (hex[index] >= 'a' && hex[index] <= 'f')
			total = (total * 16) + hex[index] - 87;
		else if (hex[index] >= '0' && hex[index] <= '9')
			total = (total * 16) + hex[index] - 48;
		index++;
	}
	point[i].color = total;
}

void	fdf_utils(t_fdf_utils *fc, t_map_element **point,
			t_graphics *graphical, t_indexes *index)
{
	while ((*fc).line_iter < (*graphical).lines_nb)
	{
		(*index).x = 0;
		(*fc).line = get_next_line((*fc).fd);
		(*fc).elements = ft_split((*fc).line, ' ');
		while ((*index).x < (*graphical).elements_nb)
		{
			(*point)[(*graphical).pn].x = (*index).x;
			(*point)[(*graphical).pn].y = (*index).y;
			(*point)[(*graphical).pn].z = ft_atoi((*fc).elements[(*index).x]);
			if ((*point)[(*graphical).pn].z > (*graphical).max_z)
				(*graphical).max_z = (*point)[(*graphical).pn].z;
			(*fc).comma_pos = ft_strchr((*fc).elements[(*index).x], ',');
			if ((*fc).comma_pos)
				assign_colors((*point), (*graphical).pn, (*fc).comma_pos + 3);
			else
				(*point)[(*graphical).pn].color = 0xFFFFFF;
			(*index).x++;
			(*graphical).pn++;
		}
		free((*fc).line);
		free_elements((*fc).elements);
		(*index).y++;
		(*fc).line_iter++;
	}
}

void	fdf(int fd, t_numbers count, int argc, char *argv[])
{
	t_indexes		index;
	t_map_element	*point;
	t_graphics		graphical;
	t_fdf_utils		fc;

	fc.fd = fd;
	graphical.points_number = 0;
	graphical.pn = 0;
	graphical.max_z = 0;
	graphical.lines_nb = count.lines_nb;
	graphical.elements_nb = count.elements_nb;
	point = malloc(((count.lines_nb * count.elements_nb) + 1)
			* sizeof(t_map_element));
	if (!point)
		return ;
	fc.line_iter = 0;
	index.y = 0;
	fdf_utils(&fc, &point, &graphical, &index);
	graphical.points_number = graphical.pn;
	graphics_engine(point, graphical, argc, argv);
	free(point);
}
