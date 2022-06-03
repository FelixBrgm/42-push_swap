/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:18:39 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/03 18:23:43 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void print_stack(t_stack stack)
{
	int i = 0;

	printf("| ");
	while (i < stack.length)
	{
		if (i < stack.index || i >= stack.index + stack.count)
			printf("   ");
		else
			printf("%i, ",stack.numbers[i]);
		i++;
	}
	printf("|\n");
}