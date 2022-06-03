/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:22:33 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/03 11:26:14 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list *sort_stack_basic(t_stack a, t_stack b);
t_list *ft_create_operation(char *operation);
void ft_lstprintoperation(void *content);


void sort_stack(t_stack *a, t_stack *b)
{
	t_list *basic;

	basic = sort_stack_basic(*a,*b);

	ft_lstiter(basic->next,&ft_lstprintoperation);
}

t_list *sort_stack_basic(t_stack a, t_stack b)
{
	t_list *head;
	int min_index;
	int i;
	while (a.count > 0)
	{
		min_index = 0;
		i = 0;
		while (i < a.count)
		{
			if (a.numbers[a.index + i] > a.numbers[a.index + min_index])
				min_index = i;
			i++;
		}
		// fastes_way_rotate = 1;
		// if (min_index - a.index < a.index + a.count - min_index)
		// 	fastes_way_rotate = 0;
		i = 0;
		while (i < a.count - min_index - 1)
		{
			stack_rotate(&a);
			ft_lstadd_back(&head, ft_create_operation("ra"));
			i++;
		}
		stack_push(&a,&b);
			ft_lstadd_back(&head, ft_create_operation("pb"));
	}
	while (b.count > 0)
	{
		stack_push(&b,&a);
			ft_lstadd_back(&head, ft_create_operation("pa"));
	}
	return (head);
}

t_list *ft_create_operation(char *operation)
{
	char *content;

	content = ft_strdup(operation);
	return (ft_lstnew(content));
}

void ft_lstprintoperation(void *content)
{
	printf("%s\n",(char *)content);
}