/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:34:12 by tpons             #+#    #+#             */
/*   Updated: 2021/12/20 08:26:27 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
**	---------------------------sort_three()------------------------------------
**	Sort_three sorts a stack of size 3, comparing 2 first then 2 last element
**	of the stack and deciding which instructions are needed.
*/

static void	sort_three(t_data *data)
{
	int	top;
	int	mid;
	int	bot;

	while (!is_sorted(data->stack_a))
	{
		top = data->stack_a->top->index;
		mid = data->stack_a->top->down->index;
		bot = data->stack_a->bot->index;
		if (((mid < top) && (mid < bot)) && top > bot)
			rotate(data, 'a');
		else if (((mid > top) && (mid > bot)) && top > bot)
			rev_rotate(data, 'a');
		else
			swap(data, 'a');
	}
}

/*
**	----------------------------sort_five()------------------------------------
**	push to B first two elements, sorts A with sort_three(). Push back in A
**	B elements verifying its pushed in the right place. (Special case for max
**	and min index). Proceed to rotate the stack until its fully sorted.
*/

static void	sort_five(t_data *data)
{
	int	top_b;

	while (data->stack_a->size > 3)
		push(data, 'b');
	sort_three(data);
	while (data->stack_b->size != 0)
	{
		top_b = data->stack_b->top->index;
		if (top_b == data->len || top_b == 1)
		{
			if (data->stack_a->top->index == data->len)
				rotate(data, 'a');
			push(data, 'a');
		}
		else
			find_right_place(data, 'a');
	}
	rotate_until_sorted(data);
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
**	------------------------------sort()---------------------------------------
**	Sort, chooses the best sort depending on the size of the stack's size.
*/

void	sort(t_data *data)
{
	if (data->stack_a->size == 1 || is_sorted(data->stack_a))
		return ;
	else if (data->stack_a->size <= 3)
		sort_three(data);
	else if (data->stack_a->size <= 5)
		sort_five(data);
	else
		sort_big(data);
}
