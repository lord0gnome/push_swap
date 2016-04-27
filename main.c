/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:37:26 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/27 19:40:14 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int		main(int argc, char **argv)
{
	t_s		*a;
	t_s 	*b;
	t_action	*acts;
	t_action	**start;
	long long test;
	int y;
	double time;
	int	nops;
	int n;
	int dir;
	int sml;

	acts = NULL;
	start = &acts;
	b = NULL;
	if (argc > 1 && ((test = ft_atoll(argv[argc - 1])) <= 2147483647 &&
				test >= -2147483648))
		a = create_list(ft_atoi(argv[argc-- - 1]));
	else
		return (-1);
	while (argc > 1)
	{
		test = ft_atoll(argv[argc - 1]);
		if (test > 2147483647 || test < -2147483648)
			return (0);
		a = add_to_start(ft_atoi(argv[argc - 1]), a);
		argc--;
	}
	nops = 0;
	time = 0.05;
	y = test_doubles(a);
	if (y != 1)
		return (0);
	while (42)
	{
		if ((n = (is_pseudo_ordered(a))) != 0 && !b)
		{
			if (n < 0)
				while (n++ != 0)
				{
			//		print_lists(a, b, time, acts);
					acts = add_a_to_list(acts, 4);
					a = rra(a);
					nops++;
				}
			else
				while (n-- != 0)
				{
			//		print_lists(a, b, time, acts);
					acts = add_a_to_list(acts, 3);
					a = ra(a);
					nops++;
				}	
		//	print_lists(a, b, time, acts);
			break ;
		}
		sml = get_smallest(a, &dir);
		if (dir < 0)
		{
			while (a && a->val != sml)
			{
			//	print_lists(a, b, time, acts);
				acts = add_a_to_list(acts, 4);
				a = rra(a);
				nops++;
			}
		}
		else if (dir > 0)
		{
			while (a && a->val != sml)
			{
		//		print_lists(a, b, time, acts);
				acts = add_a_to_list(acts, 3);
				a = ra(a);
				nops++;
			}
		}
		print_lists(a, b, time, acts);
		if (a->val == sml && !is_ordered(a))
		{
			acts = add_a_to_list(acts, 1);
			a = pb(a, &b);
			nops++;
	//		print_lists(a, b, time, acts);
		}
		if (!a || is_ordered(a))
			break;
	}
	while (b)
	{
		acts = add_a_to_list(acts, 2);
		b = pa(&a, b);
		nops++;
	//	print_lists(a, b, time, acts);
	}
	print_lists(a, b, time, acts);
	ft_printf("\n\nnumber of operations : %d\n\n", nops);
	ft_printf("\nmedian of list %d", get_median_in_scope(a, a->p));
	//if ((is_sorted_final(&a, b.currentsize)) == 1)
	return (0);
}
