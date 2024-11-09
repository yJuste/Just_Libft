/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	size_t		total_size;
	void		*ptr;

	i = 0;
	if (count == 0 || size == 0)
		total_size = 0;
	else
		total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	while (i < total_size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
