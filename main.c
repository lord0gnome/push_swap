/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:37:26 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/16 19:19:30 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int		main(int argc, char **argv)
{
	t_s		*a;
	t_s 	*b;
	int		sml;
	long long test;
	int n;
	int y;

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

	system("clear");
	y = test_doubles(a);
	sml = get_smallest(a);
	a = pb(a, &b);
	a = ra(a);
/*	while (42)
	{
		while (a && a->val != sml)
		{
			system("clear");
			print_lists(a, b);
			ft_wait(55000000);
			a = ra(a);
		}
		if (!a)
			break;
			a = pb(a, &b);
			system("clear");
			print_lists(a, b);
			ft_wait(55000000);
	}*/
	n = 0;
	//n = (is_pseudo_ordered(a));
	//SORT IN HERE
	//ft_printf("ordered but not aligned?%d", n);
/*	if (n < 0)
		while (n++ != 0)
		{
			system("clear");
			print_lists(a, b);
			ft_wait(55000000);
			a = rra(a);
		}
	else
		while (n-- != 0)
		{
			system("clear");
			print_lists(a, b);
			ft_wait(55000000);
			a = ra(a);
		}*/
	system("clear");
	print_lists(a, b);
	ft_printf("value of doubles test(%d)\n", y);
	//STOP HERE










	//if ((is_sorted_final(&a, b.currentsize)) == 1)
	ft_printf("\n\nSUCCESS!!!!!!\n");
	return (0);
}
