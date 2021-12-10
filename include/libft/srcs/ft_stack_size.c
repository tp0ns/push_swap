/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:55:10 by tpons             #+#    #+#             */
/*   Updated: 2021/12/10 12:12:52 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_stack_size(t_stack *stack)
{
	int		size;
	t_plate	*cursor;

	cursor = stack->top;
	if (!stack || !cursor)
		return (0);
	size = 1;
	while (cursor != stack->bot)
	{
		cursor = cursor->down;
		size++;
	}
	return (size);
}
