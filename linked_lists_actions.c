/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:48:47 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/30 18:41:04 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_action	*new_a_list(char action)
{
	t_action	*first;

	if (!(first = (t_action *)malloc(sizeof(t_action))))
		return (NULL);
	first->action = action;
	first->next = NULL;
	first->prev = NULL;
	return (first);
}

t_action	*add_a_to_list(t_action *last, char action)
{
	if (last)
	{
		t_action	*new;

		if (!(new = (t_action *)malloc(sizeof(t_action))))
			return (NULL);
		new->action = action;
		last->next = new;
		new->next = NULL;
		new->prev = last;
		return (new);
	}
	else
		return (new_a_list(action));
}

t_action *destroy_a(t_action *todest)
{
	t_action *temp;

	temp = NULL;
	if (todest && todest->next && todest->prev)
	{
		todest = todest->prev;
		todest->next->next->prev = todest;
		temp = todest->next->next;
		free(todest->next);
		todest->next = temp;
	}
	else if (todest && todest->next)
	{
		todest = todest->next;
		free(todest->prev);
		todest->prev = NULL;
	}
	else if (todest && todest->prev)
	{
		todest = todest->prev;
		free(todest->next);
		todest->next = NULL;
	}
	else if (todest)
	{
		free(todest);
		todest = NULL;
	}
	return (todest);
}

void	print_actions(t_action *list)
{	
	t_action *start;

	start = list;
	while (start && start->prev)
		start = start->prev;
	while (start)
	{
		if (start && !start->next)
			ft_putstr(KRED);
		else if (start && !start->prev)
			ft_putstr(KGRN);
		else
			ft_putstr(KCYN);
		if (start->action == 1)
			ft_putstr("PB");
		else if (start->action == 2)
			ft_putstr("PA");
		else if (start->action == 3)
			ft_putstr("RA");
		else if (start->action == 4)
			ft_putstr("RRA");
		else if (start->action == 5)
			ft_putstr("RB");
		else if (start->action == 6)
			ft_putstr("RRB");
		else if (start->action == 7)
			ft_putstr("SA");
		else if (start->action == 8)
			ft_putstr("SB");
		else if (start->action == 9)
			ft_putstr("RR");
		else if (start->action == 10)
			ft_putstr("RRR");
		else if (start->action == 11)
			ft_putstr("SS");
		if (start->next)
			ft_putstr(KMAG"_"RESET);
		if (!start->prev)
			ft_putstr(RESET);
		start = start->next;
	}
}

t_action	*destroy_useless(t_action *list, int *nops)
{
	while (list && list->prev)
		list = list->prev;
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
			*nops -= 2;
		}
		if (list && list->next)
			list = list->next;
	}
	return (list);
}
