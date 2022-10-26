/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 07:39:43 by dpalmer           #+#    #+#             */
/*   Updated: 2022/10/26 10:18:47 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)(haystack));
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[j] != '\0' && i + j < len)
		{
			if (needle[j] == '\0')
				return ((char *)(&haystack[i]));
			if (haystack[j] != needle[j])
				break ;
			j++;
		}
	i++;
	}
	return (0);
}
