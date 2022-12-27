/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:10:20 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/27 15:12:38 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp != NULL)
	{
		ft_printf("%d.%d\n", tmp->value, tmp->index);
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

/* TODO:

1) Define actions (DONE)
2) Sort 3 (in-place)
3) Choose sorting algo
	3b) Run bucketting tests.
*/

	// ft_print_stack(a);
	// ft_push_stack(&b, &a);
	// ft_push_stack(&b, &a);
	// ft_print_stack(a);
	// ft_print_stack(b);
	// ft_stack_swap(&a);
	// ft_print_stack(a);
	// ft_rotate_both(&a, &b, 1);
	// ft_print_stack(a);
	// ft_print_stack(b);
	// ft_rotate_both(&a, &b, -1);
	// ft_print_stack(a);
	// ft_print_stack(b);
	// ft_rotate_both(&a, &b, -1);
	// ft_rotate_a(&a, -1);
	// ft_rotate_stack(&a, -1);
	// ft_print_stack(a);
	// ft_print_stack(b);
