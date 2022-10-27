/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:38:00 by dpalmer           #+#    #+#             */
/*   Updated: 2022/10/27 19:09:25 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] != c && i == 0) || (str[i] != c && str[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	wrdlen(char *str, char c)
{
	int	i;

	i = 0;
	while (*str == c)
		str++;
	while (str && str[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		w_count;
	int		i;
	char	*str;
	char	**result;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	w_count = word_count(str, c);
	result = (char **)malloc(sizeof(char *) * w_count);
	if (!result)
		return (NULL);
	while (i < w_count)
	{
		while (*str == c)
			str++;
		result[i] = (char *)malloc(sizeof(char) * (wrdlen(str, c) + 1));
		ft_strlcpy(result[i], ft_substr(str, 0, wrdlen(str, c)),
			wrdlen(str, c) + 1);
		str += (wrdlen(str, c) + 1);
		i++;
	}
	return (result);
}
