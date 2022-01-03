/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 06:26:20 by tpons             #+#    #+#             */
/*   Updated: 2022/01/03 11:50:40 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_chunk_moved(t_stack *stack, int chunk_id)
{
	int		i;
	t_plate	*plate;

	i = 0;
	plate = stack->top;
	while (plate && i < stack->size)
	{
		if (plate->chunk == chunk_id)
			return (0);
		plate = plate->down;
		i++;
	}
	return (1);
}

static int	search_chunk_top(t_stack *stack, int chunk_id)
{
	int		i;
	t_plate	*plate;

	i = 0;
	plate = stack->top;
	while (plate->chunk != chunk_id && i++ < stack->size)
		plate = plate->down;
	return (i);
}

static int	search_chunk_bot(t_stack *stack, int chunk_id)
{
	int		i;
	t_plate	*plate;

	i = 0;
	plate = stack->bot;
	while (plate->chunk != chunk_id && i++ < stack->size)
		plate = plate->up;
	return (i);
}

static void	treat_chunk(t_data *data, int chunk_id)
{
	while (!is_chunk_moved(data->stack_a, chunk_id))
	{
		if (search_chunk_top(data->stack_a, chunk_id)
			<= search_chunk_bot(data->stack_a, chunk_id))
			while (data->stack_a->top->chunk != chunk_id)
				rotate(data, 'a');
		else
			while (data->stack_a->top->chunk != chunk_id)
				rev_rotate(data, 'a');
		if (data->stack_a->top->index > biggest_id(data->stack_b)
			|| data->stack_a->top->index < smallest_id(data->stack_b))
		{
			rotate_until_sorted(data, 'b');
			push(data, 'b');
			if (data->stack_b->top->index > biggest_id(data->stack_b)
				&& data->stack_b->size > 1)
				rotate(data, 'b');
		}
		else
			find_right_place(data, 'b');
	}
}

static void	send_to_a(t_data *data)
{
	if (search_index_top(data->stack_b, biggest_id(data->stack_b))
		<= search_index_bot(data->stack_b, biggest_id(data->stack_b)))
		while (data->stack_b->top->index != biggest_id(data->stack_b))
			rotate(data, 'b');
	else
		while (data->stack_a->top->index != biggest_id(data->stack_b))
			rev_rotate(data, 'b');
	while (data->stack_b->top)
		push(data, 'a');
}

void	sort_big(t_data *data)
{
	int	num_chunks;
	int	i;

	i = 0;
	num_chunks = 5;
	if (data->stack_a->size > 100)
		num_chunks = 11;
	while (i <= num_chunks)
		treat_chunk(data, i++);
	send_to_a(data);
	rotate_until_sorted(data, 'a');
}
