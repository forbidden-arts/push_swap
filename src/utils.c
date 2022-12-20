/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:55:34 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/20 11:05:56 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_stk_atoi(const char *str)
{
	int			i;
	long		sum;
	int			sign;
	const long	long_max = (ULONG_MAX - 1) / 2;

	i = 0;
	sum = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sum >= long_max / 10 && str[i + 1] > 7 && sign == 1)
			return (-1);
		else if (sum >= long_max / 10 && str[i + 1] > 8 && sign == -1)
			return (0);
		sum = 10 * sum - (str[i++] - '0');
	}
	return (sum * -sign);
}

void	ft_print_stack(t_stack *a)
{
	t_stack	*temp;

	temp = a;
	while (temp != NULL)
	{
		ft_printf("%d ", temp->value);
		temp = temp->next;
	}
	ft_printf("\n");
}
