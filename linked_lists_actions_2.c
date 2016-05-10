/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_actions_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 16:22:06 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/10 15:05:15 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_act_cnt(t_ac *start)
{
	if (start->action == 3)
		ft_putstr("ra");
	else if (start->action == 4)
		ft_putstr("rra");
	else if (start->action == 5)
		ft_putstr("rb");
	else if (start->action == 6)
		ft_putstr("rrb");
	else if (start->action == 7)
		ft_putstr("sa");
	else if (start->action == 8)
		ft_putstr("sb");
	else if (start->action == 9)
		ft_putstr("rr");
	else if (start->action == 10)
		ft_putstr("rrr");
	else if (start->action == 11)
		ft_putstr("ss");
}

void		print_actions(t_ac **list, t_main *init)
{
	t_ac *start;

	while ((*list) && (*list)->prev)
		(*list) = (*list)->prev;
	start = *list;
	ft_putstr(RESET);
	while (start)
	{
		if (start && !start->next && init->color)
			ft_putstr(KRED);
		else if (start && !start->prev && init->color)
			ft_putstr(KGRN);
		else if (init->color)
			ft_putstr(KCYN);
		if (start->action == 1)
			ft_putstr("pb");
		else if (start->action == 2)
			ft_putstr("pa");
		print_act_cnt(start);
		if (start->next)
			ft_putstr(" ");
		ft_putstr(RESET);
		start = start->next;
	}
	ft_putchar('\n');
}

t_ac		*destroy_useless(t_ac *list)
{
	while (list && list->next)
	{
		if (list->next && ((list->action == 1 && list->next->action == 2) ||
					(list->action == 2 && list->next->action == 1) ||
					(list->action == 3 && list->next->action == 4) ||
					(list->action == 4 && list->next->action == 3) ||
					((list->action == 5 && list->next->action == 6) ||
					(list->action == 6 && list->next->action == 5))))
		{
			list = destroy_a(list);
			if (list)
				list = destroy_a(list);
		}
		if (list && list->next)
			list = list->next;
	}
	return (list);
}
