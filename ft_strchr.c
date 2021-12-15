/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:31:01 by atouhami          #+#    #+#             */
/*   Updated: 2021/11/20 18:31:02 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strchr(char *string, int searchedChar)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == (char)searchedChar)
			return (string + i);
		i++;
	}
	if (string[i] == searchedChar)
	{
		return (string + i);
	}
	return (NULL);
}
