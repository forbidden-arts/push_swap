/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:04:28 by dan               #+#    #+#             */
/*   Updated: 2022/10/26 15:08:01 by dpalmer          ###   ########.fr       */
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
		if (s_temp[i] == c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
