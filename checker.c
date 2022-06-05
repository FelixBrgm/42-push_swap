/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:57:03 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/05 21:33:38 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "includes/get_next_line/get_next_line.h"

int	check_input_numbers(int argc, char ***argv);
char **get_operations(void);
int	stack_excecute_operations(t_stack *stack, char **operations);

int	main(int argc, char **argv)
{
	char **operations;
	t_stack	*stack;
	int		erg;
	
	if(check_input_numbers(argc, &argv))
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	operations = get_operations();
	
	stack = stack_create_argv(argv);
	
	erg = stack_excecute_operations(stack, operations);
	if (erg == -1)
		ft_putstr_fd("KO\n", 1);
	else if (erg == 0)
		ft_putstr_fd("OK\n", 1);
	else 
		ft_putstr_fd("Error\n", 1);
	return (0);
}

int	check_input_numbers(int argc, char ***argv)
{
	if (argc <= 1)
		return (-1);
	if ((*argv)++ && argc == 2)
		*argv = ft_split(**argv, ' ');
	if (input_check(*argv))
		return (-1);
	return (0);
}

char **get_operations(void)
{
	char	*lines;
	char	*line;
	char	**operations;

	lines = ft_strdup("");
	line = get_next_line(0);
	while (line)
	{
		lines = ft_strjoin_free(lines,line);
		free(line);
		line = get_next_line(0);
	}
	operations = ft_split(lines, '\n');
	free(lines);
	return (operations);
}

int	stack_excecute_operations(t_stack *a, char **operations)
{
	int	i;
	t_stack *b;
	
	b = stack_create(a->length / 3);
	i = 0;
	printf("%i %i %i\n", a->numbers[a->index + 2],a->numbers[a->index + 1],a->numbers[a->index]);
	while (operations[i])
	{
		if (!ft_strncmp(operations[i],"sa",3))
			stack_swap(a);
		else if (!ft_strncmp(operations[i],"sb",3))
			stack_swap(b);
		else if (!ft_strncmp(operations[i],"ss",3))
		{
			stack_swap(a);
			stack_swap(b);
		}
		else if (!ft_strncmp(operations[i],"rra",4))
			stack_rotate_reverse(a);
		else if (!ft_strncmp(operations[i],"rrb",4))
			stack_rotate_reverse(b);
		else if (!ft_strncmp(operations[i],"rrr",4))
		{
			stack_rotate_reverse(a);
			stack_rotate_reverse(b);
		}
		else if (!ft_strncmp(operations[i],"ra",3))
			stack_rotate(a);
		else if (!ft_strncmp(operations[i],"rb",3))
			stack_rotate(b);
		else if (!ft_strncmp(operations[i],"rr",3))
		{
			stack_rotate(a);
			stack_rotate(b);
		}
		else if (!ft_strncmp(operations[i],"pa",2))
			stack_push(b, a);
		else if (!ft_strncmp(operations[i],"pb",2))
			stack_push(a, b);
		else
			return (1);
		i++;

	}
	if (stack_is_sorted(a) && b->count == 0)
		return (0);
	else
		return (-1);
}