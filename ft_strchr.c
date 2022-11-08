/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:26:49 by dpalmer           #+#    #+#             */
/*   Updated: 2022/11/08 18:21:11 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Finds the first instance of a char in a string. Adjusts for non-ascii. 
** UPDATE: Post-LIBFT submission: added in a protection check for the existence
** of the string. Was causing a shit-storm in the get_next_line project. */

char	*ft_strchr(const char *s, int c)
{
	char	*chr;

	if (!s)
		return (NULL);
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
