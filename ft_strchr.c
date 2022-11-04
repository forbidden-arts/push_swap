/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:26:49 by dpalmer           #+#    #+#             */
/*   Updated: 2022/11/04 11:48:58 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Finds the first instance of a char in a string. Adjusts for non-ascii. */

char	*ft_strchr(const char *s, int c)
{
	char	*chr;

	chr = (char *)s;
	c %= 128;
	while (*chr != c)
	{
		if (!*chr)
			return (NULL);
		chr++;
	}
	return (chr);
}
