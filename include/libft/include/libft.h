/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:32:57 by tpons             #+#    #+#             */
/*   Updated: 2021/12/13 15:22:47 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

/*
**	--------------------t_plate--------------------
**	Plates are a double linked  list  representing
**	each element of a stack represented by "stack".
**	It stores 3 more values for sorting purpose.
*/

typedef struct s_plate
{
	struct s_stack	*stack;
	int				value;
	int				index;
	int				move;
	struct s_plate	*up;
	struct s_plate	*down;
}					t_plate;

/*
**	-----------t_stack---------------
**	Stack is a structure representing
**	a stack filled with plates.
**	It saves the bot and top plate
**	of the stack, as long as its size.
*/

typedef struct s_stack
{
	int				size;
	struct s_plate	*bot;
	struct s_plate	*top;
}					t_stack;

/*
** String Related functions
*/

int		ft_strisdigit(char *str);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);

/*
** Number related functions
*/

double	ft_atod(const char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putnbr_fd(int n, int fd);

/*
** Stack related functions
*/

t_stack	*ft_init_stack(void);
int		ft_stack_size(t_stack *stack);

void	ft_pushplate(t_stack *stack, t_plate *new_plate);
t_plate	*ft_newplate(t_stack *stack, int value);

t_plate	*ft_popplate(t_stack *stack);
t_stack	*ft_delplate(t_stack *stack, t_plate *plate);

#endif
