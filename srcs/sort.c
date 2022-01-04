/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:34:12 by tpons             #+#    #+#             */
/*   Updated: 2022/01/03 15:06:51 by tpons            ###   ########.fr       */
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
		if (top_b > biggest_id(data->stack_a)
			|| top_b < smallest_id(data->stack_a))
		{
			rotate_until_sorted(data, 'a');
			push(data, 'a');
			if (data->stack_a->top->index > biggest_id(data->stack_a))
				rotate(data, 'a');
		}
		else
			find_right_place(data, 'a');
	}
	rotate_until_sorted(data, 'a');
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
