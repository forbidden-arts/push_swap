/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:20:19 by dpalmer           #+#    #+#             */
/*   Updated: 2022/10/25 15:13:02 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	j = dst_len;
	if (dstsize == 0 || dstsize < dst_len)
		return (src_len + dstsize);
	// index to end of dst
	// appending
	// null terminate
	while (src_len--)
	{
		dst[dst_len]
	}
}
