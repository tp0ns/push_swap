/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:45:47 by tpons             #+#    #+#             */
/*   Updated: 2021/12/14 12:32:50 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX +2147483647
# define INT_MIN -2147483648
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/include/libft.h"

typedef struct s_data
{
	int		len;
	t_stack	*stack_a;
	t_stack	*stack_b;
}			t_data;

/*
**	----------------------List of push_swap instructions-----------------------
*/

void	swap(t_data *data, char c);
void	rotate(t_data *data, char c);
void	rev_rotate(t_data *data, char c);
void	push(t_data *data, char c);
/*
	---------------------------------------------------------------------------
*/

void	ft_error(char *str, t_data *data);

int		is_sorted(t_stack *stack);

void	parse(int ac, char **av, t_data *data);

int		search_from_top(t_stack	*stack, int index);
int		search_from_bot(t_stack *stack, int index);

void	sort(t_data *data);

#endif
