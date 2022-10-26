/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 07:39:43 by dpalmer           #+#    #+#             */
/*   Updated: 2022/10/26 19:29:44 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	need_le;
	char	*str;

	i = 0;
	str = (char *)haystack;
	need_le = ft_strlen(needle);
	if (need_le == 0 || haystack == needle)
		return (str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] != '\0' && needle[j] != '\0'
			&& str[i + j] == needle[j] && i + j < len)
			j++;
		if (j == need_le)
			return (str + i);
		i++;
	}
	return (0);
}