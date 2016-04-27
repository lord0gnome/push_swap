/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:37:26 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/27 14:50:38 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int		main(int argc, char **argv)
{
	t_s		*a;
	t_s 	*b;
	int		sml;
	int		dir;
	long long test;
	int n;
	int y;
	int nops;
	double time;
	char *string;


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
	time = 1;
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
					print_lists(a, b, time, string);
					a = rra(a);
					nops++;
				}
			else
				while (n-- != 0)
				{
					print_lists(a, b, time, string);
					a = ra(a);
					nops++;
				}	
			print_lists(a, b, time, string);
			//a = ra(a);

			break ;
		}
		sml = get_smallest(a, &dir);
		if (dir < 0)
		{
			while (a && a->val != sml)
			{
				print_lists(a, b, time, string);
				a = rra(a);
				nops++;
			}
		}
		else if (dir > 0)
		{
			while (a && a->val != sml)
			{
				print_lists(a, b, time, string);
				a = ra(a);
				nops++;
			}
		}
		print_lists(a, b, time, string);
		if (a->val == sml && !is_ordered(a))
		{
			a = pb(a, &b);
			nops++;
			print_lists(a, b, time, string);
		}
		if (!a || is_ordered(a))
			break;
	}
	while (b)
	{
		b = pa(&a, b);
		nops++;
		print_lists(a, b, time, string);
	}

	print_lists(a, b, time, string);
	ft_printf("\n\nnumber of operations : %d\n\n", nops);
	/*	n = (is_pseudo_ordered(a));
		ft_printf("ordered but not aligned?%d", n);
		if (n < 0)
		while (n++ != 0)
		{
		ft_putstr("\033[H\033[2J");
		print_lists(a, b);
		ft_wait(555);
		a = rra(a);
		}
		else
		while (n-- != 0)
		{
		ft_putstr("\033[H\033[2J");
		print_lists(a, b);
		ft_wait(555);
		a = ra(a);
		}*/
	//STOP HERE

	//if ((is_sorted_final(&a, b.currentsize)) == 1)
	return (0);
}
