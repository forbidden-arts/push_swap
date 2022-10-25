/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:35:39 by dpalmer           #+#    #+#             */
/*   Updated: 2022/10/25 16:18:52 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	if (dstsize == 0)
		return (ft_strlen(src));
	if (!dst || !src)
		return (0);
	while (--dstsize)
		*dst++ = *src++;
	*dst = '\0';
	return (ft_strlen(src));
}
