/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:50:02 by tpons             #+#    #+#             */
/*   Updated: 2021/12/09 16:56:28 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_stack	*ft_init_stack(int length, char **av)
{
    t_stac  *stack;

    stack = malloc(sizeof(t_stack *));
    if (stack == NULL)
        return (0);
    stack->size = 0;
    stack->first = NULL;
    stack->last = NULL;
    return (stack);
}
