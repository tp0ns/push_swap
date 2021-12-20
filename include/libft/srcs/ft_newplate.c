/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newplate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:49:31 by tpons             #+#    #+#             */
/*   Updated: 2021/12/13 14:49:04 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_plate	*ft_newplate(t_stack *stack, int input)
{
	t_plate	*new_plate;

	new_plate = malloc(sizeof(t_plate));
	if (new_plate == NULL)
		return (NULL);
	new_plate->value = input;
	new_plate->index = -1;
	new_plate->chunk = 0;
	if (stack)
		ft_pushplate(stack, new_plate);
	return (new_plate);
}
