/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:04:28 by dan               #+#    #+#             */
/*   Updated: 2022/11/04 09:24:05 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*s_temp;
	size_t		i;

	s_temp = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (s_temp[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
