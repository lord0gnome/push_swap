/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 14:04:52 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/14 15:36:40 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_final(t_stack *a, int bsize)
{
	int	asize;
	int	atmp;

	asize = a->currentsize;
	if (bsize == 0)
	{
		atmp = a->stack[asize - 1];
		while (asize-- > 1)
		{
			if (atmp < a->stack[asize - 1])
				continue;
			else
				return (-1);
		}
		return (1);
	}
	return (0);
}

int		cmp(int top, int bottom)
{
	return (top < bottom ? 1 : 0);
}
