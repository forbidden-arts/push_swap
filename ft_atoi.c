/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:04:37 by dpalmer           #+#    #+#             */
/*   Updated: 2022/10/25 19:36:19 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 	The standard AtoI breaks on numbers greater than (-)9223372036854775807(8) 
(outside of the LONG LONG range) and only returns -1 thereafter.	*/

int	ft_atoi(const char *str)
{
	int	i;
	int	sum;
	int	sign;

	i = 0;
	sum = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');
	while (str[i] >= '0' && str[i] <= '9')
		sum = 10 * sum - (str[i++] - '0');
	return (sum * -sign);
}
