/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:26:49 by dpalmer           #+#    #+#             */
/*   Updated: 2022/10/26 07:31:11 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Finds the first instance of a char in a string. Otherwise returns NULL 

char	*strchr(const char *s, int c)
{
	if (c == '/0')
		return ((char *)s);
	while (*(s++))
		if (*s == c)
			return ((char *)s);
	return (0);
}
