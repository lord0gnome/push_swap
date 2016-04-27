/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:48:47 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/27 16:31:35 by guiricha         ###   ########.fr       */
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
	if (todest && todest->next && todest->prev)
	{
		todest->next->prev = todest->prev;
		todest->prev->next = todest->next;
		free(todest);
		todest = NULL;
	}
	else if (todest && todest->next)
	{
		todest->next->prev = NULL;
		free(todest);
		todest = NULL;
	}
	else if (todest && todest->prev)
	{
		todest->prev->next = NULL;
		free(todest);
		todest = NULL;
	}
	return (todest);
}

void	print_actions(t_action *start)
{	
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
