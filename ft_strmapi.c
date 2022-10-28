/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:59:10 by dpalmer           #+#    #+#             */
/*   Updated: 2022/10/28 11:11:39 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	char	*str;
	int		i;
	int		len;

	str = (char *)s;
	i = 0;
	len = ft_strlen(str);
	map = ft_calloc(len + 1, sizeof(char));
	if (!map)
		return (NULL);
	while (i < len)
	{
		map[i] = (*f)(i, str[i]);
		i++;
	}
	return (map);
}

// int	*ft_map(int *tab, int length, int (*f)(int))
// {
// 	int	i;
// 	int	*map;

// 	i = 0;
// 	map = (int *)malloc(sizeof(int) * length);
// 	while (i < length)
// 	{
// 		map[i] = (*f)(tab[i]);
// 		i++;
// 	}
// 	return (map);
// }
