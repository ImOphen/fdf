/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:26:20 by atouhami          #+#    #+#             */
/*   Updated: 2021/11/19 10:19:57 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_valid(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'p'
		|| c == 'x' || c == 'X')
		return (1);
	return (0);
}

void	ft_putchar(int *ret, char c)
{
	write(1, &c, 1);
	*ret += 1;
}

static void	print_argument(int *ret, char c, va_list args)
{
	if (c == 'c')
		ft_putchar(ret, va_arg(args, int));
	if (c == 's')
		ft_putstr(ret, va_arg(args, char *));
	if (c == 'd' || c == 'i')
		ft_putnbr(ret, va_arg(args, int));
	if (c == 'u')
		ft_put_unsigned_nbr(ret, va_arg(args, unsigned int));
	if (c == 'p')
	{
		ft_putstr(ret, "0x");
		ft_put_adress(ret, va_arg(args, unsigned long));
	}
	if (c == 'x' || c == 'X')
		ft_convert_hex(ret, c, va_arg(args, unsigned int));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		ret;

	va_start(args, format);
	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				ft_putchar(&ret, format[i + 1]);
			else if (is_valid(format[i + 1]))
				print_argument(&ret, format[i + 1], args);
			else
				ft_putchar(&ret, format[i + 1]);
			i++;
		}
		else
			ft_putchar(&ret, format[i]);
		i++;
	}
	va_end(args);
	return (ret);
}
