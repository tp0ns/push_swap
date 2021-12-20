/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:10:07 by tpons             #+#    #+#             */
/*   Updated: 2021/12/20 08:21:46 by tpons            ###   ########.fr       */
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
	while (index > temp->index && i < stack->size)
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
	while (index < temp->index && i < stack->size)
	{
		temp = temp->up;
		i++;
	}
	if (i >= stack->size)
		return (0);
	return (i);
}

/*
**	--------------------------find_right_place()-------------------------------
**	Compare search_index_top() and search_index_bot() returns to decide which
**	action is better to execute. Does this action until top of stack_b can be
**	rightly pushed.
*/

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
		return (ft_putstr_fd("Instructions use a or b as param\n", 2));
	if (search_index_top(receiver, sender->top->index)
		<= search_index_bot(receiver, sender->top->index))
		while (receiver->top->index < sender->top->index)
			rotate(data, c);
	else
		while (receiver->top->index > sender->top->index)
			rev_rotate(data, c);
	push(data, c);
}

/*
**	--------------------------rotate_until_sorted()----------------------------
**	Compare search_index_top() and search_index_bot() returns to decide which
**	action is better to execute. Does this action until lesser is on top.
*/

void	rotate_until_sorted(t_data *data)
{
	if (search_index_top(data->stack_a, 1)
		<= search_index_bot(data->stack_a, 1))
		while (data->stack_a->top->index != 1)
			rotate(data, 'a');
	else
		while (data->stack_a->top->index != 1)
			rev_rotate(data, 'a');
}
