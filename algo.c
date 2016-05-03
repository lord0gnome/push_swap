/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 16:12:18 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/03 18:24:19 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_first_part_b(t_s **a, t_s **b, t_main *init, t_action **acts)
{
	if ((init->n = (is_pseudo_ordered(*a))) != 0 && !*b)
	{
		if (init->n < 0)
			while (init->n++ != 0)
			{
				print_lists(*a, *b, init, *acts);
				*acts = add_a_to_list(*acts, 4);
				print_lists(*a, *b, init, *acts);
				*a = rra(*a);
				init->nopsbub++;
			}
		else
			while (init->n-- != 0)
			{
				print_lists(*a, *b, init, *acts);
				*acts = add_a_to_list(*acts, 3);
				print_lists(*a, *b, init, *acts);
				*a = ra(*a);
				init->nopsbub++;
			}
		print_lists(*a, *b, init, *acts);
	}
}

void	do_first_part_i(t_s **a, t_s **b, t_main *init, t_action **acts)
{
	if ((init->n = (is_pseudo_ordered(*a))) != 0 && !*b)
	{
		if (init->n < 0)
			while (init->n++ != 0)
			{
				print_lists(*a, *b, init, *acts);
				*acts = add_a_to_list(*acts, 4);
				print_lists(*a, *b, init, *acts);
				*a = rra(*a);
				init->nopsins++;
			}
		else
			while (init->n-- != 0)
			{
				print_lists(*a, *b, init, *acts);
				*acts = add_a_to_list(*acts, 3);
				print_lists(*a, *b, init, *acts);
				*a = ra(*a);
				init->nopsins++;
			}
		print_lists(*a, *b, init, *acts);
	}
}


void	do_second_part(t_s **a, t_s **b, t_main *init, t_action **acts)
{
	init->sml = get_smallest(*a, &(init->dir));
	if (init->dir < 0)
	{
		while (*a && (*a)->val != init->sml)
		{
			print_lists(*a, *b, init, *acts);
			*acts = add_a_to_list(*acts, 4);
			print_lists(*a, *b, init, *acts);
			*a = rra(*a);
			init->nopsins++;
		}
	}
	else if (init->dir > 0)
	{
		while (*a && (*a)->val != init->sml)
		{
			print_lists(*a, *b, init, *acts);
			*acts = add_a_to_list(*acts, 3);
			print_lists(*a, *b, init, *acts);
			*a = ra(*a);
			init->nopsins++;
		}
	}
	print_lists(*a, *b, init, *acts);
}

void	do_closest_s_pair(t_s **a, t_s **b, t_main *init, t_action **acts)
{
	int val;

	val = closest_swappable_pair(*a);
	if (val)
	{
		if (val > 1)
			while (val-- > 1)
			{
				init->action = 3;
				print_lists(*a, *b, init, *acts);
				*acts = modify_stack(a, b, acts, init);
				init->nopsbub++;
				print_lists(*a, *b, init, *acts);
				if (!*a || is_pseudo_ordered(*a))
					break ;
			}
		else if (val < 0)
			while (val++ < 0)
			{
				init->action = 4;
				print_lists(*a, *b, init, *acts);
				init->nopsbub++;
				*acts = modify_stack(a, b, acts, init);
				print_lists(*a, *b, init, *acts);
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
}

t_action	*do_algo(t_s **a, t_s **b, t_main *init, t_action **acts)
{
	int	actslen[2];
	t_action *new;


	while (42)
	{
		do_first_part_i(a, b, init, acts);
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
	(*a) = init->abck;
	new = NULL;
	while (42)
	{
		do_closest_s_pair(a, b, init, &new);
		do_first_part_b(a, b, init, &new);
		if (!*a || is_ordered(*a) || init->nopsbub > init->nopsins)
			break ;
	}
	actslen[0] = l_action(new);
	actslen[1] = l_action(*acts);
	if (new == NULL)
		return (*acts);
	return (actslen[0] < actslen[1] ? new : *acts);
}
