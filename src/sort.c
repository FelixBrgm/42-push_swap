/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:22:33 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/03 18:57:31 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list *sort_stack_basic(t_stack a, t_stack b);
t_list *ft_create_operation(char *operation);
void ft_lstprintoperation(void *content);
t_list *sort_stack_radix(t_stack a);

void sort_stack(t_stack *a, t_stack *b)
{
	t_list *basic;
	t_list *radix;
	
	basic = sort_stack_basic(*a,*b);
	radix = sort_stack_radix(*a);
	print_stack(*a);
	//ft_lstiter(basic->next,&ft_lstprintoperation);
}

t_list *sort_stack_basic(t_stack a, t_stack b)
{
	t_list *head = NULL;
	int fastes_way_rotate;
	int max_index;
	int max_number;
	int i;
	while (a.count > 0)
	{
		max_index = 0;
		i = 0;
		max_number = a.numbers[a.index];
		while (i < a.count)
		{
			if (a.numbers[a.index + i] < a.numbers[a.index + max_index])
			{
				max_index = i;
				max_number = a.numbers[a.index + i];
			}
			i++;
		}

		
		fastes_way_rotate = 1;
		if (a.count / 2 > max_index)
			fastes_way_rotate = 0;

		
		if (fastes_way_rotate)
		{
			while (a.numbers[a.index + a.count -1] != max_number)
			{
				stack_rotate(&a);
				ft_lstadd_back(&head, ft_create_operation("ra"));
			}
		}
		else 
		{
			while (a.numbers[a.index + a.count -1] != max_number)
			{
				stack_rotate_reverse(&a);
				ft_lstadd_back(&head, ft_create_operation("rra"));
			}
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

t_list *sort_stack_radix(t_stack a)
{
	t_stack c;
	c = a;

	c.numbers = create_stack(c.length/3);
	c.index = a.index;
	c.length = a.length;
	c.count = a.count;
	
	
	
	c.numbers[c.index] = 123123;

	
	print_stack(a);
	print_stack(c);
	return (NULL);
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