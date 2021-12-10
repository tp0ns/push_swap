/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushplate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:49:31 by tpons             #+#    #+#             */
/*   Updated: 2021/12/10 11:53:44 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	link_plate(t_stack *stack, t_plate *new_plate)
{
	new_plate->stack = stack;
	stack->size++;
	if (!stack->bot)
	{
		stack->top = new_plate;
		stack->bot = new_plate;
	}
	else
	{
		stack->top->up = new_plate;
		stack->bot->down = new_plate;
		new_plate->up = stack->bot;
		new_plate->down = stack->top;
		stack->top = new_plate;
	}
}

t_plate	*ft_pushplate(t_stack *stack, int input)
{
	t_plate	*new_plate;

	new_plate = malloc(sizeof(t_plate));
	if (new_plate == NULL)
		return (NULL);
	new_plate->value = input;
	new_plate->index = -1;
	new_plate->move = 0;
	if (stack)
		link_plate(stack, new_plate);
	return (new_plate);
}
