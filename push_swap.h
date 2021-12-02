/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:45:47 by tpons             #+#    #+#             */
/*   Updated: 2021/11/29 16:55:15 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		*init_stack(int length, char **av);

int		ft_strlen(char *str);
int		ft_atoi(const char *str);
int		is_num(char *str);
void	ft_bzero(void *s, size_t n);