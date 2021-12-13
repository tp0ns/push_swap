/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushplate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:33:52 by tpons             #+#    #+#             */
/*   Updated: 2021/12/13 14:51:08 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_plate	*ft_pushplate(t_stack *stack, t_plate *new_plate)
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
