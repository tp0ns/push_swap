/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delplate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:55:59 by tpons             #+#    #+#             */
/*   Updated: 2021/12/13 15:02:28 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_stack	*ft_delplate(t_stack *stack, t_plate *plate)
{
	if (stack && plate == stack->top)
		free(ft_popplate(stack));
	else if (!stack)
		free(plate);
	return (stack);
}
