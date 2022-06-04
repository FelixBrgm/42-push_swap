/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 08:23:34 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/04 16:28:12 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void del_operation(char *content)
{
	free(content);
}

int main(int argc, char **argv)
{	
	t_stack *stack;
	t_list  **head;

	if (argc <= 1)
		return(-1);	
	if (input_check(argv))
	{
		ft_putstr_fd("Error\n",1);
		return(-1);
	}

	stack = stack_create_argv(argv);
	head = stack_sort(stack);
	operations_print(*head);

	stack_free(stack);
	if (!head)
		ft_lstdelone(*head, (void (*)(void *))&del_operation);
	return (0);
}

