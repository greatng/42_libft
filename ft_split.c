/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:07:19 by pngamcha          #+#    #+#             */
/*   Updated: 2022/02/21 16:42:48 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_word(char const *s, char c, char **split, size_t i)
{
	size_t	pos;

	pos = 0;
	while (s[pos] && s[pos] != c)
		pos++;
	split[i] = malloc(sizeof(char) * pos);
	if (!split[i])
		return ;
	pos = 0;
	while (s[pos] && s[pos] != c)
	{
		split[i][pos] = s[pos];
		pos++;
	}
	split[i][pos] = '\0';
	return ;
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
	char	*cur;
	size_t	n;
	size_t	i;

	if (!s)
		return (0);
	n = ft_count(s, c) + 1;
	split = malloc(sizeof(char *) * (n));
	if (!split)
		return (0);
	i = 0;
	cur = (char *)s;
	while (i < n - 1)
	{
		cur = ft_wordstart(cur, c, i);
		ft_word(cur, c, split, i);
		if (!split[i])
			return (0);
		i++;
	}
	split[i] = 0;
	return (split);
}
