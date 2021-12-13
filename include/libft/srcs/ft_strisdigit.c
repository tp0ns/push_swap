/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:57:46 by tpons             #+#    #+#             */
/*   Updated: 2021/12/13 16:00:38 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strisdigit(char *str)
{
	if (!str)
		return (0);
	if (*str == '+')
		str++;
	else if (str && *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (str && *str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
