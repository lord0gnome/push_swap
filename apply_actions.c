/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 16:12:52 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/06 16:37:50 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_actions_ext(t_ac **list, t_main *init)
{
	if ((*list)->action == 5)
		init->action = 5;
	else if ((*list)->action == 6)
		init->action = 6;
	else if ((*list)->action == 7)
		init->action = 7;
	else if ((*list)->action == 8)
		init->action = 8;
}

void	apply_actions(t_s **a, t_s **b, t_ac **list, t_main *init)
{
	t_ac *new;

	new = NULL;
	while ((*list) && (*list)->prev)
		(*list) = (*list)->prev;
	while (*list)
	{
		if ((*list)->action == 1)
			init->action = 1;
		else if ((*list)->action == 2)
			init->action = 2;
		else if ((*list)->action == 3)
			init->action = 3;
		else if ((*list)->action == 4)
			init->action = 4;
		print_lists(*a, *b, init, new);
		modify_stack(a, b, &new, init);
		*list = (*list)->next;
	}
	print_lists(*a, *b, init, new);
}
