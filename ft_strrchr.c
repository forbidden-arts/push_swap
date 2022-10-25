/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:51:38 by dpalmer           #+#    #+#             */
/*   Updated: 2022/10/25 09:55:04 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*strrchr(const char *s, int c)
{
	char	*last;

	last = 0;
	if (c == '/0')
		return ((char *)s);
	while (*s)
	{
		if (*s == c)
			last = ((char *)s);
		s++;
	}
	return (last);
}