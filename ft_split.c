/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:57:37 by atouhami          #+#    #+#             */
/*   Updated: 2021/11/08 15:38:37 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

static char	**allocate_arr(int c)
{
	char	**arr;

	arr = malloc((c + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	return (arr);
}

static char	*allocate_and_fill(const char *s, int w_index, char c)
{
	int		counter;
	char	*str;
	int		i;

	i = 0;
	while (s[i])
	{
		if (((s[i] != c && i == 0) || (s[i] != c && (s[i - 1] == c)))
			&& w_index > -1)
		{
			w_index--;
			if (w_index == -1)
				break ;
		}
		i++;
	}
	counter = i;
	while (s[i] != c && s[i])
		i++;
	str = malloc((i - counter + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s[counter], i - counter + 1);
	return (str);
}

int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	if (!s)
		return (0);
	count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != c && i == 0) || ((s[i] != c && s[i] != '\n')
				&& (s[i - 1] == c)))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;
	int		i;

	if (s == NULL)
		return (NULL);
	count = count_words(s, c);
	arr = allocate_arr(count);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		arr[i] = allocate_and_fill(s, i, c);
		if (arr[i] == NULL)
		{
			while (i)
				free(arr[--i]);
			free(arr);
			return (NULL);
		}
		i++;
	}
	arr[count] = NULL;
	return (arr);
}
