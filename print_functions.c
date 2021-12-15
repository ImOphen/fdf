/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:21:41 by atouhami          #+#    #+#             */
/*   Updated: 2021/11/19 10:21:42 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putstr(int *ret, char *str)
{
	int	i;

	if (!str)
	{
		*ret += 6;
		write(1, "(null)", 6);
		return ;
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
		*ret += 1;
	}
}

void	ft_putnbr(int *ret, int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*ret += 11;
		return ;
	}
	else if (n < 0)
	{
		*ret += 1;
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(ret, n / 10);
		ft_putnbr(ret, n % 10);
	}
	else if (n <= 9)
	{
		ft_putchar(ret, n + 48);
	}
}

void	ft_put_unsigned_nbr(int *ret, unsigned int n)
{
	if (n > 9)
	{
		ft_put_unsigned_nbr(ret, n / 10);
		ft_put_unsigned_nbr(ret, n % 10);
	}
	else if (n <= 9)
		ft_putchar(ret, n + 48);
}

void	ft_convert_hex(int *ret, char c, unsigned int n)
{
	char	*base;

	if (c == 'X')
		base = "0123456789ABCDEF";
	if (c == 'x')
		base = "0123456789abcdef";
	if (n > 15)
	{
		ft_convert_hex(ret, c, n / 16);
		ft_putchar(ret, base[n % 16]);
	}
	else
		ft_putchar(ret, base[n % 16]);
}

void	ft_put_adress(int *ret, unsigned long adrs)
{
	char	*base;

	base = "0123456789abcdef";
	if (adrs > 15)
	{
		ft_put_adress(ret, adrs / 16);
		ft_putchar(ret, base[adrs % 16]);
	}
	else
		ft_putchar(ret, base[adrs % 16]);
}
