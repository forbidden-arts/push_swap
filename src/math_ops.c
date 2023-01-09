/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 10:41:03 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/02 21:29:35 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_fwd(t_stack *stack, int b)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack->index >= b)
	{
		if (!stack->next)
			break ;
		stack = stack->next;
		i++;
	}
	return (i);
}

int	ft_find_bwd(t_stack *stack, int b)
{
	int		i;
	t_stack	*tmp;

	if (!stack)
		return (0);
	i = 0;
	tmp = stack;
	while (stack->next)
	{
		if (stack->index < b)
			i = stack->index;
		stack = stack->next;
	}
	if (stack->index < b)
		i = stack->index;
	return (ft_stack_size(tmp) - ft_get_pos(tmp, i) + 1);
}

int	ft_find_next(t_stack *stack, int b)
{
	int	i;

	i = 1;
	while (stack->bucket != b)
	{
		if (!stack->next)
			break ;
		stack = stack->next;
		i++;
	}
	return (i);
}

int	ft_find_last(t_stack *stack, int b)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (stack->next)
	{
		if (stack->bucket == b)
			i = stack->index;
		stack = stack->next;
	}
	if (stack->bucket == b)
		i = stack->index;
	return (ft_get_pos(tmp, i));
}
