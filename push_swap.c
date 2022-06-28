/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 08:23:34 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/08 18:35:03 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{	
	t_stack	*stack;
	t_list	**head;

	if (argc <= 1)
		return (-1);
	if (argv++ && argc == 2)
		argv = ft_split(argv[0], ' ');
	if (input_check(argv))
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	stack = stack_create_argv(argv);
	if (!stack)
		return (-1);
	head = stack_sort(stack);
	if (head)
	{
		stack_clean_lst(head);
		operations_print(*head);
		operations_free(*head);
		free(head);
	}
	stack_free(stack);
	return (0);
}