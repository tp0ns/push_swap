/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:45:22 by tpons             #+#    #+#             */
/*   Updated: 2021/12/13 21:31:36 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	free_data(t_data *data)
{
	if (data->stack_a)
	{
		while (data->stack_a->size > 0)
			ft_delplate(data->stack_a, data->stack_a->top);
		free(data->stack_a);
	}
	if (data->stack_b)
	{
		while (data->stack_b->size > 0)
			ft_delplate(data->stack_b, data->stack_b->top);
		free(data->stack_b);
	}
}

void	ft_error(char *str, t_data *data)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	free_data(data);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		exit(EXIT_SUCCESS);
	data.stack_a = ft_init_stack();
	data.stack_b = ft_init_stack();
	parse(ac, av, &data);
	sort(&data);
	free_data(&data);
	return (0);
}
	// t_plate	*temp = data.stack_a->top;
	// int	i = 0;
	// while (i < data.stack_a->size)
	// {
	// 	printf("Value : %d, Index : %d\n", temp->value, temp->index);
	// 	temp = temp->down;
	// 	i++;
	// }

	// temp = data.stack_a->top;
	// i = 0;
	// while (i < data.stack_a->size)
	// {
	// 	printf("Value : %d\n", temp->value);
	// 	temp = temp->down;
	// 	i++;
	// }