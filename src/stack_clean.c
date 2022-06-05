/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 08:47:06 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/05 13:12:18 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	node_free(t_list *node)
{
	if (node)
	{
		if (node->content)
			free(node->content);
		free(node);
	}
}

void	stack_clean_lst_helper(t_list *current, int *changed_something)
{
	t_list	*temp;

	while (current && current->next && current->next->next)
	{
		if ((!ft_strncmp(current->next->content, "pb", 2)
				&& !ft_strncmp(current->next->next->content, "pa", 2))
			|| (!ft_strncmp(current->next->content, "pa", 2)
				&& !ft_strncmp(current->next->next->content, "pb", 2)))
		{
			*changed_something = 1;
			temp = current->next;
			current->next = current->next->next->next;
			node_free(temp->next);
			node_free(temp);
		}
		current = current->next;
	}
}

void	stack_clean_lst(t_list **head)
{
	t_list	*current;
	int		changed_something;

	changed_something = 1;
	while (changed_something)
	{
		current = *head;
		changed_something = 0;
		if (current != NULL)
		{
			stack_clean_lst_helper(current, &changed_something);
		}
	}
}
