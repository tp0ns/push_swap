/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:34:12 by tpons             #+#    #+#             */
/*   Updated: 2021/12/13 21:29:01 by tpons            ###   ########.fr       */
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
	if (data->stack_a->top->index + data->stack_a->top->down->index == 3)
		swap(data, 'a');
	else if (data->stack_a->top->index + data->stack_a->top->down->index == 4)
	{
		if (data->stack_a->bot->index + data->stack_a->bot->up->index == 5)
			swap(data, 'a');
		rotate(data, 'a');
	}
	//   /!\ doesn't work when reused !!!!!
	else
	{
		if (data->stack_a->bot->index + data->stack_a->bot->up->index == 3)
			swap(data, 'a');
		rev_rotate(data, 'a');
	}
}

/*
**	----------------------------sort_five()------------------------------------
**	
*/

static void	sort_five(t_data *data)
{
	int	top_a;
	int	top_b;

	while (data->stack_a->size > 3)
		push(data, 'b');
	sort_three(data); //fix this
	while (data->stack_b->size != 0)
	{
		top_a = data->stack_a->top->index;
		top_b = data->stack_b->top->index;
		if (top_b == data->len || top_b == 1)
		{
			push(data, 'a');
			if (top_b == data->len)
				rotate(data, 'a');
		}
		else
			while (top_a < top_b)
				rotate(data, 'a');
	}
}

/*
**	----------------------------is_sorted()------------------------------------
**	Check if the stack given as argument is sorted (return 1) or not (return 0)
*/

int	is_sorted(t_stack *stack)
{
	int		i;
	t_plate	*plate;	

	i = 1;
	plate = stack->top;
	while (i <= stack->size)
	{
		if (plate->index != i)
			return (0);
		plate = plate->down;
		i++;
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
}
