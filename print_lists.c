/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 17:01:35 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/16 19:11:29 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lists(t_s *a, t_s *b)
{
	ft_putstr("stack A\n");	// only printing until next comment
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
	} // end of printing cycle
}
