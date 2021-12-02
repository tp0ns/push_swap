/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:45:22 by tpons             #+#    #+#             */
/*   Updated: 2021/11/29 16:55:40 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_exit(void)
{
	write (2, "Error\n", 7);
	exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	int	*a;
	int	*b;
	int	length;

	length = ac - 1;
	if (length == 0)
		return (0);
	a = init_stack(length, &av[1]);
	b = malloc(sizeof(int) * length);
	if ((a == NULL) || (b == NULL))
		ft_exit();
	ft_bzero(b, length);
	
	return (0);
}
