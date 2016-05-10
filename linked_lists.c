/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 10:52:06 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/06 16:25:47 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_s	*create_list(int first)
{
	t_s *new;

	if (!(new = (t_s *)malloc(sizeof(t_s))))
		return (NULL);
	new->n = new;
	new->p = new;
	new->start = 1;
	new->end = 1;
	new->looped = 0;
	new->val = first;
	return (new);
}

t_s	*add_to_start(int value, t_s *begin)
{
	t_s	*new;

	if (begin)
	{
		if (!(new = (t_s *)malloc(sizeof(t_s))))
			return (NULL);
		new->val = value;
		new->n = begin;
		new->p = begin->p;
		new->start = 1;
		new->end = 0;
		new->looped = 0;
		if (begin->end)
			begin->n = new;
		else
			begin->p->n = new;
		begin->start = 0;
		begin->p = new;
	}
	else
		return (create_list(value));
	return (new);
}

t_s	*sa(t_s *a)
{
	int	tmp;

	if (a && a->n)
	{
		tmp = a->val;
		a->val = a->n->val;
		a->n->val = tmp;
	}
	return (a);
}

t_s	*sb(t_s *b)
{
	int	tmp;

	if (b && b->n)
	{
		tmp = b->val;
		b->val = b->n->val;
		b->n->val = tmp;
	}
	return (b);
}

t_s	*pb(t_s *a, t_s **b)
{
	if (a && *b == NULL)
	{
		*b = create_list(a->val);
		a = destroy(&a);
	}
	else if (a && b)
	{
		*b = add_to_start(a->val, *b);
		a = destroy(&a);
	}
	return (a);
}
