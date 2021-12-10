/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_popplate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:55:59 by tpons             #+#    #+#             */
/*   Updated: 2021/12/10 12:06:43 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_stack	*ft_popplate(t_stack *stack)
{
	t_plate	*to_del;

	if (!stack)
		return (NULL);
	to_del = stack->top;
	to_del->down->up = stack->bot;
	stack->bot->down = to_del->down;
	stack->top = to_del->down;
	free(to_del);
	return (stack);
}
