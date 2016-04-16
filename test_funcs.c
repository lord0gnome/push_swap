/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 11:32:52 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/16 11:52:07 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_s	*get_smallest(t_s *start)
{
	t_s	*tmp;
	t_s *smallest;
	int	tmpval;

	tmp = start;
	if (tmp && tmp->val)
		tmpval = tmp->val;
	smallest = tmp;
	tmp = tmp->n;
	while (tmp && !tmp->start)
	{
		if (tmp->val < smallest->val)
			smallest = tmp;
		tmp = tmp->n;
	}
	return (smallest);
}

int	is_smaller(t_s *start, t_s *next)
{
	return (start->val > next->val ? 0 : 1);
}
