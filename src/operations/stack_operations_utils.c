/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:10:28 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/05 11:05:50 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*operation_create(char *operation)
{
	char	*content;

	if (!operation)
		return (NULL);
	content = ft_strdup(operation);
	return (ft_lstnew(content));
}

void	operations_print_func(void *content)
{
	if (content)
	{
		ft_putstr_fd((char *)content, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	operations_print(t_list *head)
{
	if (head)
		ft_lstiter(head,&operations_print_func);
}
void operations_free(t_list *head)
{
	t_list *temp;
	
	while (head)
	{
		temp = head;
		head = head->next;
		if (temp->content)
			free(temp->content);
		free(temp);
	}
}