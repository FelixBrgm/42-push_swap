/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:55:21 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/05 18:28:17 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	high(int base, int high);
static int	sort_get_nth_bit(int number, int index);
static void	sort_radix_helper(t_stack *a, t_stack *b,
				t_list **head, int *digit);

t_list	**sort_radix(t_stack *stack)
{
	t_list	**head;
	t_stack	*a;
	t_stack	*b;
	int		digit;

	head = ft_calloc(1, sizeof(t_list *));
	if (!head)
		return (NULL);
	a = stack_duplicate(stack);
	b = stack_create(stack->length / 3);
	digit = 0;
	while (!stack_is_sorted(a) && digit < 16)
	{
		sort_radix_helper(a, b, head, &digit);
	}
	stack_free(a);
	stack_free(b);
	return (head);
}

static void	sort_radix_helper(t_stack *a, t_stack *b, t_list **head, int *digit)
{
	int	i;

	i = 0;
	while (i < a->count)
	{
		if (sort_get_nth_bit(a->numbers[a->index + a->count - 1], *digit)
			== 0)
		{
			stack_pb(a, b, head);
			i--;
		}
		else
			stack_ra(a, head);
		i++;
	}
	while (b->count)
		stack_pa(a, b, head);
	*digit = *digit + 1;
}

static int	high(int base, int high)
{
	int	res;

	res = 1;
	while (high-- > 1)
		res *= base;
	return (res);
}

static int	sort_get_nth_bit(int number, int index)
{
	return ((number / high(2, index + 1)) % 2);
}
