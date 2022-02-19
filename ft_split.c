/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:07:19 by pngamcha          #+#    #+#             */
/*   Updated: 2022/02/18 21:05:47 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_word(char const *s, char c, char **split, size_t i)
{
	size_t	pos;

	pos = 0;
	while (s[pos] && s[pos] != c)
		pos++;
	split[i] = malloc(sizeof(char) * pos);
	if (!split[i])
		return (0);
	pos = 0;
	while (s[pos] && s[pos] != c)
	{
		split[i][pos] = s[pos];
		pos++;
	}
	split[i][pos] = '\0';
	return (split[i]);
}

static	char	*ft_wordstart(char const *s, char c, size_t n)
{
	size_t	i;

	i = 1;
	while (s[i - 1] == c && s[i] == c)
		i++;
	while (s[i])
	{
		if (n == 0 && s[i - 1] != c && i == 1)
			return ((char *)&s[i - 1]);
		if ((s[i - 1] == c && s[i] != c))
			return ((char *)&s[i]);
		i++;
	}
	return ((char *)s);
}

static	size_t	ft_count(char const *s, char c)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	n;
	size_t	i;

	n = ft_count(s, c) + 1;
	split = malloc(sizeof(char *) * (n));
	if (!split)
		return (0);
	i = 0;
	while (i < n - 1)
	{
		s = ft_wordstart(s, c, i);
		split[i] = ft_word(s, c, split, i);
		if (!split[i])
			return (0);
		i++;
	}
	split[i] = 0;
	return (split);
}
