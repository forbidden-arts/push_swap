/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:16:36 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/27 19:05:47 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_match(char *a, char *b)
{
	if (ft_strncmp(a, b, 3) == 0)
		return (1);
	return (0);
}

static void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b, int dir)
{
	if (dir >= 0)
	{
		ft_rotate_stack(stack_a, 1);
		ft_rotate_stack(stack_b, 1);
	}
	else
	{
		ft_rotate_stack(stack_a, -1);
		ft_rotate_stack(stack_b, -1);
	}
}

static void	ft_swap_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_stack_swap(stack_a);
	ft_stack_swap(stack_b);
}

void	ft_do_op(t_stack **a, t_stack **b, char *op)
{
	if (ft_match(op, SA))
		ft_stack_swap(a);
	else if (ft_match(op, SB))
		ft_stack_swap(b);
	else if (ft_match(op, SS))
		ft_swap_both(a, b);
	else if (ft_match(op, PA))
		ft_push_stack(b, a);
	else if (ft_match(op, PB))
		ft_push_stack(a, b);
	else if (ft_match(op, RA))
		ft_rotate_stack(a, 1);
	else if (ft_match(op, RB))
		ft_rotate_stack(b, 1);
	else if (ft_match(op, RR))
		ft_rotate_both(a, b, 1);
	else if (ft_match(op, RRA))
		ft_rotate_stack(a, -1);
	else if (ft_match(op, RRB))
		ft_rotate_stack(b, -1);
	else if (ft_match(op, RRR))
		ft_rotate_both(a, b, -1);
	ft_printf("%s\n", op);
}

void	ft_do_op_n(t_stack **a, t_stack **b, char *op, int n)
{
	if (!n)
		return ;
	ft_do_op(a, b, op);
	ft_do_op_n(a, b, op, n - 1);
}
