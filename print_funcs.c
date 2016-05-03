/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 17:01:35 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/03 18:18:17 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_a(t_s *a)
{
	if (a)
		ft_printf("STACK_A\n_______\n");
	while ((a))
	{
		if (a->start)
		{
			ft_putstr(KGRN);
			ft_printf("%d_is_START", a->val);
			ft_putstr(RESET);
		}
		else if (!a->end)
		{
			ft_putstr(KGRN);
			ft_printf("%d", a->val);
		}
		if (a->end)
		{
			ft_putstr(KMAG);
			ft_printf("%d_is_END", a->val);
			ft_putstr(RESET);
			break ;
		}
		a = a->n;
		ft_putchar('\n');
	}
}

static void	print_b(t_s *b)
{
	if (b)
		ft_printf("STACK_B\n_______\n");
	while ((b))
	{
		if (b->start)
		{
			ft_putstr(KCYN);
			ft_printf("%d_is_START", b->val);
			ft_putstr(RESET);
		}
		else if (!b->end)
		{
			ft_putstr(KGRN);
			ft_printf("%d", b->val);
		}
		if (b->end)
		{
			ft_putstr(KMAG);
			ft_printf("%d_is_END", b->val);
			ft_putstr(RESET);
			break ;
		}
		b = b->n;
		ft_putchar('\n');
	}
}

void		print_lists(t_s *a, t_s *b, t_main *init, t_action *acts)
{
	if (init->draw == 0)
		return ;
	ft_putstr("\033[H\033[2J");
	print_a(a);
	if (a && b)
		ft_putstr("\n\n");
	print_b(b);
	ft_putstr("\n\n");
	ft_putstr(KCYN);
	ft_putchar('\n');
	print_actions(&acts, init);
	ft_putstr(RESET);
	ft_wait(init->time);
}
