/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 10:41:03 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/09 18:30:58 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* How many moves (RA) to put a number less than B to the top of the stack */
int	ft_find_fwd(t_stack *stack, int b)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack->index >= b && !stack->sorted)
	{
		if (!stack->next)
			break ;
		stack = stack->next;
		i++;
	}
	return (i);
}

/* How many moves (RRA) to put a number less than B to the top of the stack */
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
		if (stack->index < b && !stack->sorted)
			i = stack->index;
		stack = stack->next;
	}
	if (stack->index < b)
		i = stack->index;
	return (ft_s_size(tmp) - ft_get_pos(tmp, i) + 1);
}


/* Not currently used. Remnant of bucketing */
// int	ft_find_next(t_stack *stack, int b)
// {
// 	int	i;

// 	i = 1;
// 	while (stack->bucket != b)
// 	{
// 		if (!stack->next)
// 			break ;
// 		stack = stack->next;
// 		i++;
// 	}
// 	return (i);
// }

// /* Not currently used. Remnant of bucketing */
// int	ft_find_last(t_stack *stack, int b)
// {
// 	int		i;
// 	t_stack	*tmp;

// 	i = 0;
// 	tmp = stack;
// 	while (stack->next)
// 	{
// 		if (stack->bucket == b)
// 			i = stack->index;
// 		stack = stack->next;
// 	}
// 	if (stack->bucket == b)
// 		i = stack->index;
// 	return (ft_get_pos(tmp, i));
// }
