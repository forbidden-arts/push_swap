/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:03:53 by dpalmer           #+#    #+#             */
/*   Updated: 2022/10/27 12:08:47 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocate and return string trimmed of leading and trailing given characters.

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*beg;
	char	*end;


	if (!s1 || !set)
		return (NULL);
	beg = s1;
	end = s1[ft_strlen(s1) - 1];

	
}
