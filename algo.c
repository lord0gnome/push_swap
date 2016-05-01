/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 16:12:18 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/01 18:26:04 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_first_part(t_s **a, t_s **b, t_main *init, t_action **acts)
{
	if ((init->n = (is_pseudo_ordered(*a))) != 0 && !*b)
	{
		if (init->n < 0)
			while (init->n++ != 0)
			{
				print_lists(*a, *b, init, *acts);
				*acts = add_a_to_list(*acts, 4);
				*a = rra(*a);
				init->n_ops++;
			}
		else
			while (init->n-- != 0)
			{
				print_lists(*a, *b, init, *acts);
				*acts = add_a_to_list(*acts, 3);
				*a = ra(*a);
				init->n_ops++;
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
			*a = rra(*a);
			init->n_ops++;
		}
	}
	else if (init->dir > 0)
	{
		while (*a && (*a)->val != init->sml)
		{
			print_lists(*a, *b, init, *acts);
			*acts = add_a_to_list(*acts, 3);
			*a = ra(*a);
			init->n_ops++;
		}
	}
	print_lists(*a, *b, init, *acts);
}

void	do_algo(t_s **a, t_s **b, t_main *init, t_action **acts)
{
	while (42)
	{
		do_first_part(a, b, init, acts);
		do_second_part(a, b, init, acts);
		if ((*a)->val == init->sml && !is_ordered(*a))
		{
			*acts = add_a_to_list(*acts, 1);
			*a = pb(*a, b);
			init->n_ops++;
			print_lists(*a, *b, init, *acts);
		}
		if (!*a || is_ordered(*a))
			break ;
	}
	while (*b)
	{
		*acts = add_a_to_list(*acts, 2);
		*b = pa(a, *b);
		init->n_ops++;
		print_lists(*a, *b, init, *acts);
	}
}
