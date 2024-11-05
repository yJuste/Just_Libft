/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlongin <jlongin@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:42:42 by jlongin           #+#    #+#             */
/*   Updated: 2024/11/04 21:42:42 by jlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	size_t		length;
	char		*n_tab;

	length = 0;
	if (!s)
		return (NULL);
	while (s[length])
		length++;
	n_tab = malloc(sizeof(char) * (length + 1));
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
