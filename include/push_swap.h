/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:45:47 by tpons             #+#    #+#             */
/*   Updated: 2021/12/13 10:50:08 by tpons            ###   ########.fr       */
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
	t_stack	*stack_a;
	t_stack	*stack_b;
}			t_data;

void	ft_error(char *str, t_data *data);

void	parse(int ac, char **av, t_data *data);

#endif
