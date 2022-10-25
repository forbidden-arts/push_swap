/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:18:28 by dpalmer           #+#    #+#             */
/*   Updated: 2022/10/25 12:30:16 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst2;
	const char	*src2;

	dst2 = (char *)(dst);
	src2 = (const char *)(src);
	if (dst == src || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	while (n-- > 0)
		dst2[n] = src2[n];
	return (dst);
}