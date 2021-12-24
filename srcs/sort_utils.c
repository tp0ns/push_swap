/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:10:07 by tpons             #+#    #+#             */
/*   Updated: 2021/12/24 14:48:13 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
**	--------------------------search_index_top()--------------------------------
**	Search how much actions it will take to put the right plate on top of the
**	stack by executing rotate. Return the number of actions.
**	if num_actions >= size_of_stack, return(0).
*/

int	search_index_top(t_stack	*stack, int index)
{
	int		i;
	t_plate	*temp;

	i = 0;
	temp = stack->top;
	if (index == smallest_id(stack))
	{
		while (temp->index != index)
		{
			temp = temp->down;
			i++;
		}
		return (i);
	}
	while ((temp->index < index || temp->up->index > index)
		&& i < stack->size)
	{
		temp = temp->down;
		i++;
	}
	if (i >= stack->size)
		return (0);
	return (i);
}

/*
**	--------------------------search_index_bot()--------------------------------
**	Search how much actions it will take to put the right plate on top of the
**	stack by executing rev_rotate. Return the number of actions.
**	if num_actions >= size_of_stack, return(0).
*/

int	search_index_bot(t_stack *stack, int index)
{
	int		i;
	t_plate	*temp;

	i = 0;
	temp = stack->bot;
	if (index == smallest_id(stack))
	{
		while (temp->index != index)
		{
			temp = temp->down;
			i++;
		}
		return (i);
	}
	while ((temp->index < index || temp->up->index > index)
		&& i < stack->size)
	{
		temp = temp->up;
		i++;
	}
	if (i >= stack->size)
		return (0);
	return (i);
}

/*
**	--------------------------rotate_until_sorted()----------------------------
**	Compare search_index_top() and search_index_bot() returns to decide which
**	action is better to execute. Does this action until lesser is on top.
*/

int	smallest_id(t_stack *stack)
{
	int		i;
	t_plate	*plate;

	plate = stack->top;
	i = plate->index;
	while (plate && plate != stack->bot)
	{
		if (i > plate->index)
			i = plate->index;
		plate = plate->down;
	}
	if (i > plate->index)
		i = plate->index;
	return (i);
}

int	biggest_id(t_stack *stack)
{
	int		i;
	t_plate	*plate;

	plate = stack->top;
	i = plate->index;
	while (plate && plate != stack->bot)
	{
		if (i < plate->index)
			i = plate->index;
		plate = plate->down;
	}
	if (i < plate->index)
		i = plate->index;
	return (i);
}

void	rotate_until_sorted(t_data *data)
{
	int	smallest;

	smallest = smallest_id(data->stack_a);
	if (search_index_top(data->stack_a, smallest)
		<= search_index_bot(data->stack_a, smallest))
		while (data->stack_a->top->index != smallest)
			rotate(data, 'a');
	else
		while (data->stack_a->top->index != smallest)
			rev_rotate(data, 'a');
}
