/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 16:26:53 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/06 16:47:10 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		first_part_b(t_s **a, t_s **b, t_main *init, t_ac **acts)
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

void		first_part_i(t_s **a, t_s **b, t_main *init, t_ac **acts)
{
	if ((init->n = (is_pseudo_ordered(*a))) != 0 && !*b)
	{
		if (init->n < 0)
			while (init->n++ != 0)
			{
				print_lists(*a, *b, init, *acts);
				*acts = add_a_to_list(*acts, 4);
				*a = rra(*a);
				init->nopsins++;
			}
		else
			while (init->n-- != 0)
			{
				print_lists(*a, *b, init, *acts);
				*acts = add_a_to_list(*acts, 3);
				*a = ra(*a);
				init->nopsins++;
			}
		print_lists(*a, *b, init, *acts);
	}
}

void		do_second_part(t_s **a, t_s **b, t_main *init, t_ac **acts)
{
	init->sml = get_smallest(*a, &(init->dir));
	if (init->dir < 0)
	{
		while (*a && (*a)->val != init->sml)
		{
			print_lists(*a, *b, init, *acts);
			*acts = add_a_to_list(*acts, 4);
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
			*a = ra(*a);
			init->nopsins++;
		}
	}
	print_lists(*a, *b, init, *acts);
}

void		do_quad_func(t_s **a, t_s **b, t_main *init, t_ac **acts)
{
	print_lists(*a, *b, init, *acts);
	*acts = modify_stack(a, b, acts, init);
	init->nopsbub++;
	print_lists(*a, *b, init, *acts);
}
