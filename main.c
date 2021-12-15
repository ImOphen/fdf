/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:31:15 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/06 14:09:46 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	handle_file_open(char *str, int argc)
{
	int	fd;

	if (argc == 1 || argc > 4)
		return (ft_printf("\x1b[31m"), ft_printf(ERROR_MSG), -1);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ft_printf("\x1b[31m"), ft_printf("%s\n", strerror(errno)), -1);
	return (fd);
}

int	main(int argc, char *argv[])
{
	int			fd;
	char		*line;
	t_numbers	count;

	line = NULL;
	count.elements_nb = 0;
	count.lines_nb = 0;
	fd = handle_file_open(argv[1], argc);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	count.elements_nb = count_words(line, ' ');
	while (line)
	{
		count.lines_nb++;
		free(line);
		line = get_next_line(fd);
		if (count.elements_nb > count_words(line, ' ') && line != NULL)
			return (ft_printf("\x1b[31m"),
				ft_printf(INVALID_LEN), free(line), 0);
	}
	close(fd);
	fd = handle_file_open(argv[1], argc);
	fdf(fd, count, argc, argv);
	close(fd);
}
