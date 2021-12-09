/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:32:57 by tpons             #+#    #+#             */
/*   Updated: 2021/12/09 17:58:55 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

/*
**
**
**
*/

typedef	struct s_plate
{
	struct s_stack	stack;
	int				value;
	int				index;
	int				hold;
	struct s_plate	*prev;
	struct s_plate	*next;
}					t_plate;

/*
**
**
**
*/

typedef struct s_stack
{
	int				size;
	struct s_plate	*first;
	struct s_plate	*last;
}					t_stack;

size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_stack	*ft_init_stack(int length, char **av);
int		ft_stack_size(t_stack *stack);

t_plate	*ft_newplate(t_stack *stack);
t_plate	*ft_delplate(t_stack *stack);

#endif
