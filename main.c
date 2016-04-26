/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:37:26 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/26 15:23:32 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int		main(int argc, char **argv)
{
	t_s		*a;
	t_s 	*b;
	long long test;
	int y;
	int nops;
	double time;
	char *string;
	int *tab;
	unsigned int loftab;
	
	loftab = 0;
	b = NULL;
	if (argc > 1 && ((test = ft_atoll(argv[argc - 1])) <= 2147483647 &&
				test >= -2147483648))
	{
		tab = (int *)malloc(sizeof(int) * argc - 1);
		loftab++;
		tab[argc - 2] = ft_atoi(argv[argc - 1]);
		a = create_list(ft_atoi(argv[argc-- - 1]));
	}
	else
		return (-1);
	while (argc > 1)
	{
		test = ft_atoll(argv[argc - 1]);
		if (test > 2147483647 || test < -2147483648)
			return (0);
		tab[argc - 2] = ft_atoi(argv[argc - 1]);
		loftab++;
		a = add_to_start(ft_atoi(argv[argc - 1]), a);
		argc--;
	}
	nops = 0;
	time = 1;
	nops = get_median(tab, (loftab/2));
	y = test_doubles(a);
	string = "\n";
	if (y != 1)
		return (0);
	while (42)
	{
	while (a->val >= median)
		a = pb(a, &b);
		get_bigger_than_n(a);
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
