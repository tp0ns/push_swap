/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:10:07 by tpons             #+#    #+#             */
/*   Updated: 2021/12/15 10:35:21 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	search_from_top(t_stack	*stack, int index)
{
	int		i;
	t_plate	*temp;

	i = 0;
	temp = stack->top;
	while (index > temp->index && i < stack->size)
	{
		temp = temp->down;
		i++;
	}
	if (i >= stack->size)
		return (0);
	return (i);
}

int	search_from_bot(t_stack *stack, int index)
{
	int		i;
	t_plate	*temp;

	i = 0;
	temp = stack->bot;
	while (index < temp->index && i < stack->size)
	{
		temp = temp->up;
		i++;
	}
	if (i >= stack->size)
		return (0);
	return (i + 1);
}

void	find_right_place(t_data *data, int top_b)
{
	if (search_from_top(data->stack_a, top_b)
		<= search_from_bot(data->stack_a, top_b))
		while (data->stack_a->top->index < data->stack_b->top->index)
			rotate(data, 'a');
	else
		while (data->stack_a->top->index > data->stack_b->top->index)
			rev_rotate(data, 'a');
	push(data, 'a');
}

void	rotate_until_sorted(t_data *data)
{
	if (search_from_top(data->stack_a, 1) <= search_from_bot(data->stack_a, 1))
		while (data->stack_a->top->index != 1)
			rotate(data, 'a');
	else
		while (data->stack_a->top->index != 1)
			rev_rotate(data, 'a');
}
