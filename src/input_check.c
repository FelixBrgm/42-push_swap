/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:24:48 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/05 18:52:03 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_numbers(char **argv);
static int	check_if_int(char **argv);
static int	check_duplicates(char **argv);

int	input_check(char **argv)
{
	if (!argv)
		return (-1);
	if (check_numbers(argv))
		return (-1);
	if (check_if_int(argv))
		return (-1);
	if (check_duplicates(argv))
		return (-1);
	return (0);
}

static int	check_numbers(char **argv)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (argv[i])
	{
		y = 0;
		while (argv[i] && argv[i][y])
		{
			if (!ft_isdigit(argv[i][y]) && argv[i][y] != '-')
				return (-1);
			y++;
		}
		i++;
	}
	return (0);
}

static int	check_if_int(char **argv)
{
	int		i;
	long	max_int;
	long	min_int;

	i = 0;
	max_int = 2147483647;
	min_int = -2147483648;
	while (argv[i])
	{	
		if (ft_strlen(argv[i]) > 11)
			return (-1);
		if (ft_atoi_l(argv[i]) > max_int || ft_atoi_l(argv[i]) < min_int)
			return (-1);
		i++;
	}
	return (0);
}

static int	check_duplicates(char **argv)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (argv[x])
	{
		i = 0;
		while (argv[i])
		{
			if (i != x && !ft_strncmp(argv[i], argv[x], 12))
				return (-1);
			i++;
		}
		x++;
	}
	return (0);
}
