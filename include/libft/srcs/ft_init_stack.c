/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_init_stack.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tpons <tpons@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/12/09 16:50:02 by tpons			 #+#	#+#			 */
/*   Updated: 2021/12/09 21:12:29 by tpons			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../include/libft.h"

t_stack	*ft_init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	stack->bot = NULL;
	return (stack);
}
