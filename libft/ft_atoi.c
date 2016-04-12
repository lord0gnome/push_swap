/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:51:19 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/12 13:14:30 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		index;

	result = 0;
	index = 0;
	sign = (str[index] == '-') ? -1 : 1;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (str[index] != '\0' && str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + (str[index] - '0');
		index++;
	}
	return ((int)(result * sign));
}
