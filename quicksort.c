/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 18:41:20 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/30 20:35:12 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_s	*quick_sort_main(t_s *a, t_s **b, int *tab, int tab_len)
{
	int	median;
	int	direction;
	int stop;

	if ((is_ordered(a) && !*b) || !a)
		return (a);
	stop = 0;
	median = get_median(tab + tab_len, tab_len / 2);
	ft_putnbr(median);
	ft_putchar(' ');
	ft_putnbr(tab_len);
	ft_wait(20);
	while (!stop)
	{
		direction = get_smaller_or_median(a, median, &stop);
		if (direction < 0)
			while (direction++)
			{
	print_lists(a, *b, 10, NULL);
				a = rra(a);
			}
		else if (direction > 0)
			while (direction--)
			{
	print_lists(a, *b, 10, NULL);
				a = ra(a);
			}
	print_lists(a, *b, 10, NULL);
		if (a)
			a = pb(a, b);
	}
	print_lists(a, *b, 10, NULL);
	ft_wait(42);
	ft_putstr("RECURSION  ");
	quick_sort_main(a, b, tab, tab_len -= (tab_len / 2));
	return (a);
}
