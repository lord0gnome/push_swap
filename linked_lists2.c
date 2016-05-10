/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 16:22:57 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/06 16:44:33 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_s			*rra(t_s *a)
{
	if (a && a->end && a->start)
	{
		return (a);
	}
	if (a)
	{
		if (a->p)
		{
			a->start = 0;
			a->p->start = 1;
			a->p->end = 0;
			a->p->p->end = 1;
			return (a->p);
		}
		return (a);
	}
	else
		return (a);
}

t_s			*rrb(t_s *b)
{
	if (b && b->end && b->start)
	{
		return (b);
	}
	if (b)
	{
		if (b->p)
		{
			b->start = 0;
			b->p->start = 1;
			b->p->end = 0;
			b->p->p->end = 1;
			return (b->p);
		}
		return (b);
	}
	else
		return (b);
}

t_s			*destroy(t_s **todestroy)
{
	t_s	*tmp;

	tmp = (*todestroy)->n;
	if ((*todestroy) && (*todestroy)->start && (*todestroy)->end)
	{
		free(*todestroy);
		*todestroy = NULL;
		return (*todestroy);
	}
	else if ((*todestroy) && (*todestroy)->start)
	{
		(*todestroy)->n->start = 1;
		(*todestroy)->n->p = (*todestroy)->p;
		(*todestroy)->p->n = (*todestroy)->n;
		free(*todestroy);
		return (tmp);
	}
	return (*todestroy);
}

void		modify_stack2(t_s **a, t_s **b, t_ac **acts, t_main *init)
{
	if (init->action == 5)
	{
		*b = rb(*b);
		*acts = add_a_to_list(*acts, init->action);
	}
	else if (init->action == 6)
	{
		*b = rrb(*b);
		*acts = add_a_to_list(*acts, init->action);
	}
	else if (init->action == 7)
	{
		*a = sa(*a);
		*acts = add_a_to_list(*acts, init->action);
	}
	else if (init->action == 8)
	{
		*b = sb(*b);
		*acts = add_a_to_list(*acts, init->action);
	}
}

t_ac		*modify_stack(t_s **a, t_s **b, t_ac **acts, t_main *init)
{
	print_lists(*a, *b, init, *acts);
	if (init->action == 1)
	{
		*a = pb(*a, b);
		*acts = add_a_to_list(*acts, init->action);
	}
	else if (init->action == 2)
	{
		*b = pa(a, *b);
		*acts = add_a_to_list(*acts, init->action);
	}
	else if (init->action == 3)
	{
		*a = ra(*a);
		*acts = add_a_to_list(*acts, init->action);
	}
	else if (init->action == 4)
	{
		*a = rra(*a);
		*acts = add_a_to_list(*acts, init->action);
	}
	modify_stack2(a, b, acts, init);
	return (*acts);
}
