/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:20:19 by dpalmer           #+#    #+#             */
/*   Updated: 2022/10/25 15:25:14 by dpalmer          ###   ########.fr       */
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
	while (src[j] && (dst_len + j) < dstsize)
		dst[i++] = src[j++];
	if ((dst_len + j) == dstsize && dst_len < dstsize)
		dst[--i] = '\0';
	else
		dst[i] = '\0';
	return (src_len + dst_len);
}
