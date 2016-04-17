/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 17:01:35 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/17 16:53:31 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lists(t_s *a, t_s *b, double time)
{
	wchar_t	up;
	wchar_t	down;

	ft_putstr("\033[H\033[2J");
	up = L'⟱';
	down = L'⟰';
	while ((a))
	{
		if (a->start)
		{
			ft_printf(KCYN "%d", a->val);
			ft_putstr("_is_start");
			ft_putstr(RESET);
		}
		else if (!a->end)
			ft_printf(KGRN "%d", a->val);
			if (a->end)
			{
				ft_printf(KMAG "%d", a->val);
				ft_putstr("_is_end");
				ft_putstr(RESET);
				break ;
			}
		a = a->n;
		ft_putchar('\n');
	}
	ft_putstr("\n");
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
	ft_wait(time);
}
