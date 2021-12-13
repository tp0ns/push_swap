/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:30:58 by tpons             #+#    #+#             */
/*   Updated: 2021/12/13 21:22:07 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
**	------------------------check_if_int()-----------------------------------
**	Check if str represents a digit then stores it in a double type variable.
**	If this variable is storable in an int, return this int.
**	If not, exit program.
*/

static int	check_if_int(t_data *data, char *str)
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

/*
**	---------------------------give_index()-------------------------------
**	Iterate in a stack and check if there is a smaller or equal value in
**	the same stack size time if == then call ft_error, if < keep changing
**	index in plate
*/

static void	give_index(t_data *data)
{
	int		i;
	int		j;
	t_plate	*keep;
	t_plate	*search;

	i = 1;
	keep = data->stack_a->top;
	while (i++ <= data->stack_a->size)
	{
		j = 1;
		while (keep->index != -1 && j++)
			keep = keep->down;
		j = 1;
		search = keep->down;
		while (j++ < data->stack_a->size)
		{
			if (keep->value == search->value)
				ft_error("You have a double in your params.", data);
			else if (search->index == -1 && keep->value > search->value)
				keep = search;
			search = search->down;
		}
		keep->index = i - 1;
	}
}

/*
**	----------------------------parse()--------------------------------
**	Parse adds "plates" in stack_a as long as they are integers.
**	Then verify if stack is valid and give each plate its sorted index.
*/

void	parse(int ac, char **av, t_data *data)
{
	int	cursor;

	if (!data->stack_a || !data->stack_b)
		ft_error("Stacks weren't initialized right", data);
	cursor = ac - 1;
	while (cursor >= 1)
	{
		if (!ft_newplate(data->stack_a, check_if_int(data, av[cursor])))
			ft_error("One of the plates failed initializing", data);
		cursor--;
	}
	if (data->stack_a->size > 1)
		give_index(data);
	data->len = data->stack_a->size;
}
