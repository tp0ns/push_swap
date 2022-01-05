/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:05:18 by tpons             #+#    #+#             */
/*   Updated: 2022/01/05 10:16:58 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	search_chunk_top(t_stack *stack, int chunk_id)
{
	int		i;
	t_plate	*plate;

	i = 0;
	plate = stack->top;
	while (plate->chunk != chunk_id && i++ < stack->size)
		plate = plate->down;
	return (i);
}

int	search_chunk_bot(t_stack *stack, int chunk_id)
{
	int		i;
	t_plate	*plate;

	i = 0;
	plate = stack->bot;
	while (plate->chunk != chunk_id && i++ < stack->size)
		plate = plate->up;
	return (i);
}

/*
**	----------------------------is_sorted()------------------------------------
**	Check if the stack given as argument is sorted (return 1) or not (return 0)
*/

int	is_sorted(t_stack *stack)
{
	t_plate	*plate;	

	plate = stack->top;
	while (plate != stack->bot)
	{
		if (plate->index > plate->down->index)
			return (0);
		plate = plate->down;
	}
	return (1);
}

/*
**	--------------------------find_right_place()-------------------------------
**	Compare search_index_top() and search_index_bot() returns to decide which
**	action is better to execute. Does this action until top of stack_b can be
**	rightly pushed.
*/

static void	choose_rotate(t_stack *send, t_stack *rec, t_data *data, char c)
{
	if (search_index_top(rec, send->top->index)
		<= search_index_bot(rec, send->top->index))
		while (rec->top->index < send->top->index
			|| rec->top->up->index > send->top->index)
			rotate(data, c);
	else
		while (rec->top->index < send->top->index
			|| rec->top->up->index > send->top->index)
			rev_rotate(data, c);
}

void	find_right_place(t_data *data, char c)
{
	t_stack	*sender;
	t_stack	*receiver;

	if (c == 'a')
	{
		sender = data->stack_b;
		receiver = data->stack_a;
	}
	else if (c == 'b')
	{
		sender = data->stack_a;
		receiver = data->stack_b;
	}
	else
		return ;
	if (receiver->size <= 1)
		return (push(data, c));
	choose_rotate(sender, receiver, data, c);
	push(data, c);
}
