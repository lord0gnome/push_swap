/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 10:54:54 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/14 12:34:26 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sa(t_stack *a)
{
	int tmp;
	int	cs;

	cs = a->currentsize - 1;
	if (cs >= 0)
	{
		tmp = a->stack[cs];
		a->stack[cs] = a->stack[cs - 1];
		a->stack[cs - 1] = tmp;
		return (1);
	}
	return (0);
}

int		sb(t_stack *b)
{
	int tmp;
	int	cs;

	cs = b->currentsize - 1;
	if (cs >= 0)
	{
		tmp = b->stack[cs];
		b->stack[cs] = b->stack[cs - 1];
		b->stack[cs - 1] = tmp;
		return (1);
	}
	return (0);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

int		pa(t_stack *a, t_stack *b)
{
	if (b->currentsize - 1 >= 0)
		a->stack[a->currentsize++] = b->stack[--b->currentsize];
	return (1);
}

int		pb(t_stack *a, t_stack *b)
{
	if (a->currentsize - 1 >= 0)
		b->stack[b->currentsize++] = a->stack[--a->currentsize];
	return (1);
}

int		ra(t_stack *a)
{
	int	tmp;
	int	csb;

	if (a->currentsize >= 2)
	{
		csb = a->currentsize;
		tmp = a->stack[a->currentsize - 1];
		while (csb-- > 1)
			a->stack[csb] = a->stack[csb - 1];
		a->stack[0] = tmp;
		return (1);
	}
	return (0);
}

int		rb(t_stack *b)
{
	int	tmp;
	int	csb;

	if (b->currentsize >= 2)
	{
		csb = b->currentsize;
		tmp = b->stack[b->currentsize - 1];
		while (csb-- > 1)
			b->stack[csb] = b->stack[csb - 1];
		b->stack[0] = tmp;
		return (1);
	}
	return (0);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

int		rra(t_stack *a)
{
	int	tmp;
	int	index;

	if (a->currentsize >= 2)
	{
		index = -1;
		tmp = a->stack[0];
		while (++index < a->currentsize)
			a->stack[index] = a->stack[index + 1];
		a->stack[index - 1] = tmp;
		return (1);
	}
	return (0);
}

int		rrb(t_stack *b)
{
	int	tmp;
	int	index;

	if (b->currentsize >= 2)
	{
		index = -1;
		tmp = b->stack[0];
		while (++index < b->currentsize)
			b->stack[index] = b->stack[index + 1];
		b->stack[index - 1] = tmp;
		return (1);
	}
	return (0);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
