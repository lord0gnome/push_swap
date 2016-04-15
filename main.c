/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:37:26 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/15 15:02:58 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_s		*a;
	t_s 	*b;
	long long test;

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
	a = pb(a, &b);
	a = pb(a, &b);
	a = pb(a, &b);
	a = pb(a, &b);
	a = pb(a, &b);
	a = pb(a, &b);
	a = pb(a, &b);
	a = pb(a, &b);
	a = pb(a, &b);
	a = ra(a);
	a = ra(a);
	a = ra(a);
	a = ra(a);
	a = ra(a);
	a = ra(a);
	a = sa(a);
	a = ra(a);
	a = ra(a);
	a = ra(a);
	a = sa(a);
	a = ra(a);
	a = ra(a);
	a = ra(a);
	ft_putstr("\n\nstack A\n");
	ft_putstr("BEFOREsort:\n");
	while ((a))
	{
		ft_putnbr(a->val);
		if (a->start)
			ft_putstr("_is_start");
		if (a->end)
		{
			ft_putstr("_is_end");
			break;
		}
		a = a->n;
		ft_putchar('\n');
	}
	ft_putstr("\n\nstack B\n");
	ft_putstr("BEFOREsort:\n");
	while ((b))
	{
		ft_putnbr(b->val);
		if (b->start)
			ft_putstr("_is_start");
		if (b->end)
		{
			ft_putstr("_is_end");
			break;
		}
		b = b->n;
		ft_putchar('\n');
	}
	//SORT IN HERE
	//STOP HERE
	//if ((is_sorted_final(&a, b.currentsize)) == 1)
	ft_printf("\n\nSUCCESS!!!!!!\n");
	return (0);
}
