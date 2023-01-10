/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:10:20 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/10 15:31:00 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp != NULL)
	{
		ft_printf("num: %d idx: %d sort: %d, push:%d, loc: %s\n",
			tmp->value, tmp->index, tmp->sorted, tmp->pushed, tmp->loc);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	ft_stk_chk_valid(argv);
	a = ft_build_stack(a, argv);
	ft_chk_dup_stack(a);
	ft_sort_control(&a, &b);
	return (0);
}

	// ft_printf("min: %d avg: %d\n", ft_find_min(a), (ft_find_max(a)+ft_find_min(a))/2);
	// ft_printf("first unsorted: %d last unsorted: %d u_size: %d\n", ft_find_fwd(a, 4), ft_find_bwd(a, 4), ft_unsort(a));
	// a->sorted = 1;
	// a->next->sorted = 1;
	// ft_printf("min: %d avg: %d\n", ft_find_min(a), (ft_find_max(a)+ft_find_min(a))/2);
	// ft_do_op_n(&a, &b, PB, 3);
	// ft_do_op_n(&a, &b, PA, 3);
	// ft_print_stack(a);
	// ft_printf("first unsorted: %d last unsorted: %d u_size: %d\n", ft_find_fwd(a, 4), ft_find_bwd(a, 4), ft_unsort(a));
// ft_printf("dir: %d", ft_top_a(&a, 5));
//TODO: FIX AVERAGE, ADJUST FOR UNSORTED.
	// ft_print_stack(a);
	// ft_do_op_n(&a, &b, PB, 5);
	// // ft_printf("%d, %d\n", ft_find_fwd(a, ft_stack_avg(a)), ft_find_bwd(a, ft_stack_avg(a)));
	// // ft_printf("%d\n", ft_stack_avg(a));
	// // ft_smart_rotate_a_a(&a, ft_stack_avg(a));

	// ft_top_a(&a, &b, 3);
	// ft_print_stack(b);
	// // ft_do_op_n(&a, &b, PB, 3);
	// // ft_printf("Min: %d, Max: %d\n", ft_find_min(b), ft_find_max(b));
	// // ft_printf("%d\n", ft_stack_avg(b));
	// ft_printf("size: %d\n", ft_unsort(a));
	// a->sorted = 1;
	// a->next->sorted = 1;
	// ft_printf("size: %d\n", ft_unsort(a));
