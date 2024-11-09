/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlongin <jlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:21:04 by jlongin           #+#    #+#             */
/*   Updated: 2024/11/08 23:21:06 by jlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	size_t		length;
	char		*n_tab;

	if (!s)
		return (NULL);
	length = 0;
	while (s[length])
		length++;
	n_tab = ft_calloc(length + 1, sizeof(char));
	if (!n_tab)
		return (NULL);
	i = 0;
	while (i < length)
	{
		n_tab[i] = f(i, s[i]);
		i++;
	}
	n_tab[length] = '\0';
	return (n_tab);
}
