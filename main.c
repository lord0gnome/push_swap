/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:37:26 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/14 14:42:11 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	a;
	t_stack b;
	int	i;
	int j;
	long long test;

	i = 0;
	if (argc > 1)
	{
		a.stack = (int *)malloc(sizeof(int) * argc - 1);
		b.stack = (int *)malloc(sizeof(int) * argc - 1);
	}
	else
		return (0);
	while (argc > 1)
	{
		test = ft_atoll(argv[argc - 1]);
		if (test > 2147483647 || test < -2147483648)
			return (0);
		a.stack[i] = ft_atoi(argv[argc - 1]);
		i++;
		argc--;
	}
	a.currentsize = i;
	ft_printf("\n%d\n", a.currentsize);
	b.currentsize = 0;
	i = 0;
	ft_putstr("stack A:	Stack B:\n");
	ft_putstr("BEFOREsort:	BEFOREsort:\n");
	i = a.currentsize;
	j = b.currentsize;
	while (i-- >= 0 || j > 0)
	{
		if (i >= 0)
			ft_putnbr(a.stack[i]);
		ft_putstr("			");
		if (j-- > 0)
			ft_putnbr(b.stack[j]);
		ft_putchar('\n');
	}
	//SORT IN HERE
/*	while ((!(is_sorted_final(&a, b.currentsize))))	
	{
		if (a->stack[a->currentsize - 1] < a->stack[0])
			ra(&a);
		if (a->stack[a->currentsize - 1] > a->stack[0])
			rra(&a);

	}

*/
	sa(&a);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	sa(&a);
	pa(&a, &b);
	pa(&a, &b);
	pa(&a, &b);
	//STOP HERE
	i = a.currentsize;
	j = b.currentsize;
	ft_putstr("stack A		Stack B\n");
	ft_putstr("AFTERsort:	AFTERsort:\n");
	while (i-- >= 0 || j > 0)
	{
		if (i >= 0)
			ft_putnbr(a.stack[i]);
		ft_putstr("			");
		if (j-- > 0)
			ft_putnbr(b.stack[j]);
		ft_putchar('\n');
	}

	if ((is_sorted_final(&a, b.currentsize)) == 1)
		ft_printf("\n\nSUCCESS!!!!!!\n");
	return (0);
}
