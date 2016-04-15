/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 10:52:06 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/15 15:03:44 by guiricha         ###   ########.fr       */
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
		if (begin->end)
			begin->n = new;
		else
			begin->p->n = new;
		begin->start = 0;
		begin->p = new;
	}
	else
		return (NULL);
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

t_s *pb(t_s *a, t_s **b)
{
	if (a && *b == NULL)
	{
		*b = create_list(a->val);
		a = destroy(a);
	}
	else if (a && b)
	{
		*b = add_to_start(a->val, *b);
		a = destroy(a);
	}
	return (a);
}

t_s *pa(t_s **a, t_s *b)
{
	if (b && *a == NULL)
	{
		*a = create_list(b->val);
		b = destroy(b);
	}
	else if (*a && b)
	{
		*a = add_to_start(b->val, *a);
		b = destroy(b);
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

t_s *destroy(t_s *todestroy)
{
	t_s *sbck;

	sbck = todestroy;
	if (todestroy)
	{
		if (!todestroy->end)
		{
			todestroy = todestroy->n;
			if (todestroy->p->start)
				todestroy->p = todestroy->p->p;
			free(sbck);
			todestroy->start = 1;
		}
		else
		{
			free(todestroy);
			todestroy = NULL;
		}
	}
	return (todestroy);
}
