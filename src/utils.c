/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:55:34 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/10 18:34:50 by dpalmer          ###   ########.fr       */
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

/* Checks whether a stack is sorted. */
int	ft_is_sorted(t_stack *a, int dir)
{
	if (dir > 0)
	{
		while (a->next)
		{
			if (a->value > a->next->value)
				return (0);
			a = a->next;
		}
		return (1);
	}
	else
	{
		while (a->next)
		{
			if (a->value < a->next->value)
				return (0);
			a = a->next;
		}
		return (1);
	}
}

/* Returns the position relative to the top of the stack of N */
int	ft_get_pos(t_stack *stack, int n)
{
	int	pos;

	pos = 1;
	if (n < 1)
		return (0);
	while (stack->index != n)
	{
		if (!stack->next)
			break ;
		stack = stack->next;
		pos++;
	}
	return (pos);
}

/* Counts the number of elements in a stack. */
int	ft_s_size(t_stack *stack)
{
	if (!stack)
		return (0);
	return (1 + (ft_s_size(stack->next)));
}

int	ft_unsort(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		if (!stack->sorted)
			i++;
		stack = stack->next;
	}
	return (i);
}
