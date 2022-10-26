/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 08:06:36 by dpalmer           #+#    #+#             */
/*   Updated: 2022/10/26 08:21:34 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char *)malloc(sizeof(*s2) * (ft_strlen(s1) + 1));
	while (s1[i++] != '\0')
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}
