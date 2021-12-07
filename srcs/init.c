/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:04:22 by tpons             #+#    #+#             */
/*   Updated: 2021/12/07 16:16:19 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*init_stack(int length, char **av)
{
	int	*stack;
	int	i;

	i = 0;
	stack = malloc(sizeof(int) * length);
	if (stack == NULL)
		return (NULL);
	while (i < length)
	{
		if (!is_num(av[i]))
		{
			free(stack);
			return (NULL);
		}
		stack[i] = ft_atoi(av[i++]);
	}
	return (stack);
}
