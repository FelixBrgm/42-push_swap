/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 08:23:34 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/03 18:49:26 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b; 
	
	if (argc <= 1)
		return(-1);	
	if (check_input(argv))
	{
		ft_putstr_fd("Error\n",1);
		return(-1);
	}
	
	a = init_stack(argv);
	b = create_stack(ft_2ptrlen((void **) argv));
	sort_stack(a, b);
	return (0);
}