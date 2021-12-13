/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:07:03 by tpons             #+#    #+#             */
/*   Updated: 2021/12/13 17:19:19 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
**	--------------------------------push()-------------------------------------
**	Swap the first 2 elements at the top of the stack. Do nothing if there is 
**	only one or no elements.
*/

void	swap(t_data *data, char c)
{
	t_stack	*stack;
	t_plate	*first;
	t_plate	*second;

	if (c == 'a')
	{
		ft_putstr_fd("sa\n", 1);
		stack = data->stack_a;
	}
	else if (c == 'b')
	{
		ft_putstr_fd("sb\n", 1);
		stack = data->stack_b;
	}
	else
		return (ft_putstr_fd("Instructions use a or b as param\n", 2));
	first = stack->top;
	second = stack->top->down;
	if (stack->size > 1)
	{
		ft_popplate(stack);
		ft_popplate(stack);
		ft_pushplate(stack, first);
		ft_pushplate(stack, second);
	}
}

/*
**	-------------------------------rotate()------------------------------------
**	Shift up all elements of stack by 1.The first element becomes the last one.
*/

void	rotate(t_data *data, char c)
{
	t_stack	*stack;

	if (c == 'a')
	{
		ft_putstr_fd("ra\n", 1);
		stack = data->stack_a;
	}
	else if (c == 'b')
	{
		ft_putstr_fd("rb\n", 1);
		stack = data->stack_b;
	}
	else
		return (ft_putstr_fd("Instructions use a or b as param\n", 2));
	if (stack->size > 1)
	{
		stack->bot = stack->top;
		stack->top = stack->top->down;
	}
}

/*
**	---------------------------rev_rotate()------------------------------------
**	Shift up all elements of stack by 1.The last element becomes the first one.
*/

void	rev_rotate(t_data *data, char c)
{
	t_stack	*stack;

	if (c == 'a')
	{
		ft_putstr_fd("rra\n", 1);
		stack = data->stack_a;
	}
	else if (c == 'b')
	{
		ft_putstr_fd("rrb\n", 1);
		stack = data->stack_b;
	}
	else
		return (ft_putstr_fd("Instructions use a or b as param\n", 2));
	if (stack->size > 1)
	{
		stack->top = stack->bot;
		stack->bot = stack->bot->up;
	}
}

/*
**	---------------------------------push()------------------------------------
**	Take the first element at the top of the other stack and put it at the top
**	of the "c" stack. Do nothing if it's empty.
*/

void	push(t_data *data, char c)
{
	t_stack	*from;
	t_stack	*to;

	if (c == 'a')
	{
		ft_putstr_fd("pa\n", 1);
		from = data->stack_b;
		to = data->stack_a;
	}
	else if (c == 'b')
	{
		ft_putstr_fd("pb\n", 1);
		from = data->stack_a;
		to = data->stack_b;
	}
	else
		return (ft_putstr_fd("Instructions use a or b as param\n", 2));
	if (from->size > 0)
	{
		ft_pushplate(to, ft_popplate(from));
	}
}
