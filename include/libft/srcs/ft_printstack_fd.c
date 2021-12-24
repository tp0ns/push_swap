/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstack_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:14:35 by tpons             #+#    #+#             */
/*   Updated: 2021/12/24 12:34:28 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_printstack_fd(t_stack *stack, int fd)
{
	int		i;
	t_plate	*temp;

	i = 0;
	temp = stack->top;
	while (i < stack->size)
	{
		ft_putnbr_fd(temp->value, fd);
		ft_putstr_fd("	index: ", fd);
		ft_putnbr_fd(temp->index, fd);
		ft_putstr_fd("\n", fd);
		temp = temp->down;
		i++;
	}
}
