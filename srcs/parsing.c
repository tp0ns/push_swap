/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:30:58 by tpons             #+#    #+#             */
/*   Updated: 2021/12/11 01:14:26 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
**	Code a function that iterate in stack and check if there is a smaller or 
**	equal value in same stack if == then call ft_error, if < keep changing
**	index in plate
*/

int	check_if_int(t_data *data, char *str)
{
	double	big;
	int		num;

	if (!ft_strisdigit(str))
		ft_error("One of your argument isn't a number", data);
	big = ft_atod(str);
	if (big < INT_MIN || big > INT_MAX)
		ft_error("One of the params isn't an int", data);
	num = (int)big;
	return (num);
}

void	parse(int ac, char **av, t_data *data)
{
	int	cursor;

	if (!data->stack_a || !data->stack_b)
		ft_error("Stacks weren't initialized right", data);
	cursor = ac - 1;
	while (cursor >= 1)
	{
		if (!ft_pushplate(data->stack_a, check_if_int(data, av[cursor])))
			ft_error("One of the plates failed initializing", data);
		cursor--;
	}
}
