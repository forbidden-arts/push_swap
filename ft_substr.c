/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:22:48 by dpalmer           #+#    #+#             */
/*   Updated: 2022/10/28 12:04:01 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates and returns a string from a given starting point.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s || len < 0)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	if (start >= ft_strlen(s))
		return (sub);
	ft_memmove(sub, &s[start], len);
	sub[len] = '\0';
	return (sub);
}
