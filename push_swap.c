/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 08:23:34 by fbruggem          #+#    #+#             */
/*   Updated: 2022/05/14 10:51:41 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char** argv)
{
	t_list **list;
	if (argc <= 1)
		exit(-1);	
	if (check_input(argv))
	{
		ft_putstr_fd("Error\n",1);
		exit(-1);
	}
	*list = convert_input(argv);
	if (!list)
	{
		ft_putstr_fd("Error\n",1);
		exit(-1);
	}
	
	printf("OK!\n");
	return (0);
}