/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:27:57 by fbruggem          #+#    #+#             */
/*   Updated: 2022/03/29 14:41:35 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c <= '9' && c >= '0')
		|| ((c <= 'Z' && c >= 'A' ) || (c <= 'z' && c >= 'a' )))
		return (1);
	return (0);
}
