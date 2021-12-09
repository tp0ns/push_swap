/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:45:22 by tpons             #+#    #+#             */
/*   Updated: 2021/12/09 11:55:16 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_exit(void)
{
	write (2, "Error\n", 7);
	exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	(void)av;
	(void)ac;
	return (0);
}
