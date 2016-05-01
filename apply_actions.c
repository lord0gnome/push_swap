/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 16:12:52 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/01 16:47:11 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_actions(t_s *a, t_s *b, t_action **list)
{
	while ((*list) && (*list)->prev)
		(*list) = (*list)->prev;
	while (*list)
	{
		if ((*list)->action == 1)
			a = pb(a, &b);
		if ((*list)->action == 2)
			b = pa(&a, b);
		if ((*list)->action == 3)
			a = ra(a);
		if ((*list)->action == 4)
			a = rra(a);
		if ((*list)->action == 5)
			b = rb(b);
		if ((*list)->action == 6)
			b = rrb(b);
		if ((*list)->action == 7)
			a = sa(a);
		if ((*list)->action == 8)
			b = sb(b);
		*list = destroy_a(*list);
	}
}
