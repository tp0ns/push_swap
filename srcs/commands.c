/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:07:03 by tpons             #+#    #+#             */
/*   Updated: 2021/12/13 15:52:20 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	ft_popplate(stack);
	ft_popplate(stack);
	ft_pushplate(stack, first);
	ft_pushplate(stack, second);
}

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
	stack->bot = stack->top;
	stack->top = stack->top->down;
}

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
	stack->top = stack->bot;
	stack->bot = stack->bot->up;
}
