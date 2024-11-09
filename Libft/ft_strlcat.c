/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlongin <jlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:18:02 by jlongin           #+#    #+#             */
/*   Updated: 2024/11/08 23:18:03 by jlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dl;
	size_t		sl;
	size_t		i;
	size_t		j;

	sl = 0;
	while (src[sl])
		sl++;
	if (!dst && dstsize == 0)
		return (sl);
	dl = 0;
	while (dst[dl] && dl < dstsize)
		dl++;
	if (dstsize <= dl)
		return (sl + dstsize);
	i = 0;
	j = dl;
	while (src[i] && (dl + i < dstsize - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dl + sl);
}
