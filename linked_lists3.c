/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 16:25:20 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/06 16:25:44 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_s	*pa(t_s **a, t_s *b)
{
	if (b && *a == NULL)
	{
		*a = create_list(b->val);
		b = destroy(&b);
	}
	else if (*a && b)
	{
		*a = add_to_start(b->val, *a);
		b = destroy(&b);
	}
	return (b);
}

t_s	*ra(t_s *a)
{
	if (a && a->end && a->start)
	{
		return (a);
	}
	if (a)
	{
		if (a->n)
		{
			a->start = 0;
			a->n->start = 1;
			a->p->end = 0;
			a->end = 1;
			return (a->n);
		}
		return (a);
	}
	else
		return (a);
}

t_s	*rb(t_s *b)
{
	if (b && b->end && b->start)
	{
		return (b);
	}
	if (b)
	{
		if (b->n)
		{
			b->start = 0;
			b->n->start = 1;
			b->p->end = 0;
			b->end = 1;
			return (b->n);
		}
		return (b);
	}
	else
		return (b);
}
