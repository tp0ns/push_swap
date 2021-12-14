/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:10:07 by tpons             #+#    #+#             */
/*   Updated: 2021/12/14 13:19:01 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	search_from_top(t_stack	*stack, int index)
{
	int		i;
	t_plate	*temp;
	
	i = 0;
	temp = stack->top;
	while (index > temp->index)
	{
		temp = temp->down;
		i++;
	}
	return (i);
}

int	search_from_bot(t_stack *stack, int index)
{
	int	i;
	t_plate *temp;

	i = 0;
	temp = stack->bot;
	while (index < temp->index)
	{
		temp = temp->up;
		i++;
	}
	return (i + 1);
}
