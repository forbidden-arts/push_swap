/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:30:48 by dpalmer           #+#    #+#             */
/*   Updated: 2022/10/31 18:46:23 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*list;

	if (!lst || !del)
		return ;
	list = *lst;
	while (list)
	{
		temp = list->next;
		(del)(list->content);
		free(list);
		list = temp;
	}
	*lst = NULL;
}
