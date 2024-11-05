/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlongin <jlongin@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:42:42 by jlongin           #+#    #+#             */
/*   Updated: 2024/11/04 21:42:42 by jlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char		**ft_split(const char *s, char c);
static size_t	ft_count_words(const char *s, char c);
static char	**ft_split_next(char **out, const char *s, char c);
static char	**ft_split_error(char **out, size_t k);
static char	*ft_strncpy(char *dst, const char *src, size_t n);

char	**ft_split(const char *s, char c)
{
	size_t		wc;
	char		**out;

	if (!s)
		return (NULL);
	wc = ft_count_words(s, c);
	out = ft_calloc(wc + 1, sizeof(char *));
	if (!out)
		return (NULL);
	return (ft_split_next(out, s, c));
}

static size_t	ft_count_words(const char *s, char c)
{
	size_t		i;
	size_t		wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i])
			wc++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (wc);
}

static char	**ft_split_next(char **out, const char *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		j = i;
		while (s[i] && (s[i] != c))
			i++;
		if (i > j)
		{
			out[k] = ft_calloc(i - j + 1, sizeof(char));
			if (!out[k])
				return (ft_split_error(out, k));
			ft_strncpy(out[k++], &s[j], (i - j));
		}
	}
	out[k] = NULL;
	return (out);
}

static char	**ft_split_error(char **out, size_t k)
{
	size_t		f;

	f = 0;
	while (f < k)
	{
		free(out[f]);
		f++;
	}
	free(out);
	return (NULL);
}

static char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
