/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 10:52:06 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/03 17:59:42 by guiricha         ###   ########.fr       */
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

t_s	*rra(t_s *a)
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

t_s	*rrb(t_s *b)
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

t_s	*destroy(t_s **todestroy)
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

void		modify_stack2(t_s **a, t_s **b, t_action **acts, t_main *init)
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

t_action	*modify_stack(t_s **a, t_s **b, t_action **acts, t_main *init)
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
	print_lists(*a, *b, init, *acts);
	return (*acts);
}
