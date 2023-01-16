/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:54:52 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/16 16:03:30 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	More QuickSort inspired than actual Q-Sort. The two stack limitation is a
	major pain in the ass, and makes what could potentially be a rather simple
	implementation a mind-bending nightmare. */

void	ft_part_a(t_stack **a, t_stack **b)
{
	int	pivot;

	if (ft_s_size(*b) || (*a)->pushed)
		return ;
	pivot = ((ft_find_min(*a) + ft_find_max(*a)) / 2 + 1 -(ft_s_size(*a) % 2));
	if (ft_unsort(*a) < STACKMAX / 2)
		pivot += pivot / 2;
	while (ft_find_min(*a) < pivot)
	{
		if (!ft_find_fwd(*a, pivot))
			ft_do_op(a, b, PB);
		else if (ft_unsort(*a) == ft_s_size(*a))
			ft_smart_rotate_a(a, b, pivot);
		else
			ft_do_op(a, b, RA);
	}
}

void	ft_part_b(t_stack **a, t_stack **b)
{
	int	pivot;

	if (ft_unsort(*a) < ft_s_size(*a))
		ft_sort_to_bot(a, b);
	if (ft_s_size(*b) < STACKMAX)
		return ;
	pivot = (ft_find_min(*b) + ft_find_max(*b)) / 2 + 1 -(ft_s_size(*b) % 2);
	if (ft_s_size(*b) > STACKMAX * 2)
		pivot += pivot / 2;
	while (ft_find_max(*b) > pivot)
	{
		if (ft_opportunity_b(a, b))
			pivot += 1;
		if (!ft_find_fwd_a(*b, pivot))
			ft_do_op(a, b, PA);
		else
			ft_smart_rotate_b(a, b, ft_find_max(*b));
	}
}

void	ft_push_back(t_stack **a, t_stack **b)
{
	int		pushme;
	t_stack	*tmp;

	tmp = ft_stack_last(*a);
	pushme = (*a)->pushed;
	if ((*a)->index == tmp->index + 1 && tmp->sorted)
	{
		(*a)->sorted = 1;
		ft_do_op(a, b, RA);
		ft_push_back(a, b);
	}
	else if (!pushme || ft_s_size(*b))
		return ;
	while ((*a)->pushed == pushme && !((*a)->sorted))
	{
		tmp = ft_stack_last(*a);
		if ((*a)->index == tmp->index + 1 && tmp->sorted)
		{
			(*a)->sorted = 1;
			ft_do_op(a, b, RA);
		}
		else
			ft_do_op(a, b, PB);
	}
}

void	ft_empty_b(t_stack **a, t_stack **b)
{
	while (ft_s_size(*b))
	{
		if (ft_opportunity_b(a, b))
			continue ;
		else if ((*b)->index == ft_find_max(*b))
			ft_do_op(a, b, PA);
		else
			ft_smart_rotate_b(a, b, ft_find_max(*b));
	}
}

void	ft_quick(t_stack **a, t_stack **b)
{
	// ft_printf("***Pushback Init***\n\n");
	// ft_print_stack(*a);
	// ft_print_stack(*b);
	ft_push_back(a, b);
	// ft_printf("***Partitioning A***\n\n");
	// ft_print_stack(*a);
	// ft_print_stack(*b);
	ft_part_a(a, b);
	// ft_printf("***Partitioning B***\n\n");
	// ft_print_stack(*a);
	// ft_print_stack(*b);
	ft_part_b(a, b);
	// ft_printf("***Emptying B***\n\n");
	// ft_print_stack(*a);
	// ft_print_stack(*b);
	ft_empty_b(a, b);
	// ft_printf("***Moving Sort to Bottom***\n\n");
	ft_sort_to_bot(a, b);
	if (ft_unsort(*a))
		ft_quick(a, b);
}
