/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:59:52 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/20 08:07:52 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	ft_parse_to_stack(t_stack a, char *str)
{
	int		i;
	char	**temp;

	temp = ft_split(str, ' ');
	i = 0;
	while (temp[i])
	{
		if (ft_stack_atoi(i) > INT_MAX || ft_stack_atoi(i) < INT_MIN)
		{
			ft_tab_unwind(temp);
			exit_on_error(&a, NULL);
		}
		
	}
	
	ft_tab_unwind(temp);
	return (a);
}

t_stack	*ft_make_new_stack(int i)
{
	t_stack	*new;

	new = malloc(sizeof(new));
	if (!new)
		return (NULL);
	new->value = i;
	new->next = NULL;
	return (new);
}

void	ft_stack_add_tail(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!*stack)
		*stack = new;
	else
	{
		temp = ft_stack_last(*stack);
		temp->next = new;
	}
}

t_stack	ft_build_stack(t_stack a, int i)
{
	if (ft_stack_atoi)
}