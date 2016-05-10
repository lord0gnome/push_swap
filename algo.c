/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 16:12:18 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/10 14:21:39 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_closest_s_pair(t_s **a, t_s **b, t_main *init, t_ac **acts)
{
	init->sml = closest_swappable_pair(*a);
	if (!init->sml)
		return ;
	if (init->sml > 1)
		while (init->sml-- > 1)
		{
			init->action = 3;
			do_quad_func(a, b, init, acts);
			if (!*a || is_pseudo_ordered(*a))
				break ;
		}
	else if (init->sml < 0)
		while (init->sml++ < 0)
		{
			init->action = 4;
			do_quad_func(a, b, init, acts);
			if (!*a || is_pseudo_ordered(*a))
				break ;
		}
	if ((*a)->val > (*a)->n->val)
	{
		init->action = 7;
		init->nopsbub++;
		*acts = modify_stack(a, b, acts, init);
	}
}

void		do_short_test(t_s **a, t_s **b, t_main *init, t_ac **shorttest)
{
	if (l(*a) == 3 && !is_ordered(*a))
	{
		if ((*a)->n->val > (*a)->val && (*a)->val < (*a)->n->n->val)
		{
			print_lists(*a, *b, init, *shorttest);
			init->action = 4;
			*shorttest = modify_stack(a, b, shorttest, init);
			print_lists(*a, *b, init, *shorttest);
			init->action = 7;
			*shorttest = modify_stack(a, b, shorttest, init);
			print_lists(*a, *b, init, *shorttest);
		}
	}
}

t_ac		*gla(t_ac **new, t_ac **acts, t_ac **st, t_main *init)
{
	int	l[4];

	l[0] = l_action(*new);
	l[1] = l_action(*acts);
	l[2] = l_action(*st);
	l[3] = l[0] > l[1] ? l[0] : l[1];
	if (l[2] > l[3])
		l[3] = l[2];
	if (l[0] == 0)
		l[0] += l[3] + 1;
	if (l[1] == 0)
		l[1] += l[3] + 1;
	if (l[2] == 0)
		l[2] += l[3] + 1;
	if (l[0] < l[1] && l[0] < l[2])
		*acts = *new;
	if (l[1] < l[0] && l[1] < l[2])
		*acts = *acts;
	if (l[2] < l[1] && l[2] < l[0])
		*acts = *st;
	init->n_ops = l_action(*acts);
	return (*acts);
}

void		cut_algo(t_s **a, t_s **b, t_main *init, t_ac **acts)
{
	while (42)
	{
		first_part_i(a, b, init, acts);
		do_second_part(a, b, init, acts);
		init->action = 1;
		if ((*a)->val == init->sml && !is_ordered(*a))
		{
			*acts = add_a_to_list(*acts, 1);
			*a = pb(*a, b);
			init->nopsins++;
			print_lists(*a, *b, init, *acts);
		}
		print_lists(*a, *b, init, *acts);
		if (!*a || is_ordered(*a))
			break ;
	}
	init->action = 2;
	while (*b)
	{
		*acts = modify_stack(a, b, acts, init);
		init->nopsins++;
	}
}

t_ac		*do_algo(t_s **a, t_s **b, t_main *init, t_ac **acts)
{
	t_ac *new;
	t_ac *shorttest;

	shorttest = NULL;
	if (is_ordered(*a))
		return (NULL);
	do_short_test(a, b, init, &shorttest);
	cut_algo(a, b, init, acts);
	(*a) = init->abck;
	new = NULL;
	while (42)
	{
		do_closest_s_pair(a, b, init, &new);
		first_part_b(a, b, init, &new);
		if (!*a || is_ordered(*a) || init->nopsbub > init->nopsins)
			break ;
	}
	*acts = gla(&new, acts, &shorttest, init);
	return (*acts);
}
