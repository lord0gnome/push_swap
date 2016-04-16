/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:37:26 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/16 13:09:08 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

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

	system("clear");
	//SORT IN HERE
/*	while (a)
	{
		ft_wait(9999999);
		while (a && a->n && is_smaller(a->n, a) && (!a->end || !a->start))
		{
			a->looped = 1;
			a = sa(a);
			ft_printf("swap %d and %d\n", a->val, a->n->val);
		}
		while (a && ((is_smaller(a, a->n)) || (a && a->end && a->start)))
		{
		ft_wait(9999999);
			a->looped = 1;
			ft_printf("push %d to b\n", a->val);
			a = pb(a, &b);
		}
		if (a && a->looped == 1)
			break ;
	}
	ft_putstr("\n\n\n\n\n");
	while (b)
	{
		ft_wait(9999999);
			ft_printf("push %d to a\n", b->val);
			b = pa(&a, b);
	}*/
	a = rra(a);
	//STOP HERE
	ft_wait(199999999);
	ft_putstr("stack A\n");
	ft_putstr("BEFOREsort:\n");
	while ((a))
	{
		ft_putnbr(a->val);
		ft_wait(9999999);
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
	//if ((is_sorted_final(&a, b.currentsize)) == 1)
	ft_printf("\n\nSUCCESS!!!!!!\n");
	return (0);
}
