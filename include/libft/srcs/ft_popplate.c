/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_popplate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:36:58 by tpons             #+#    #+#             */
/*   Updated: 2021/12/13 14:46:32 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_plate	*ft_popplate(t_stack *stack)
{
	t_plate	*plate;

	if (!stack)
		return (NULL);
	plate = stack->top;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bot = NULL;
	}
	else
	{
		plate->down->up = stack->bot;
		stack->bot->down = plate->down;
		stack->top = plate->down;
	}
	stack->size--;
	return (plate);
}
