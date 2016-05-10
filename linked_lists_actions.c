/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:48:47 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/06 16:44:17 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ac		*new_a_list(char action)
{
	t_ac	*first;

	if (!(first = (t_ac *)malloc(sizeof(t_ac))))
		return (NULL);
	first->action = action;
	first->next = NULL;
	first->prev = NULL;
	return (first);
}

t_ac		*add_a_to_list(t_ac *start, char action)
{
	t_ac	*new;
	t_ac	*first;

	first = start;
	if (first)
	{
		while (first->next)
			first = first->next;
		if (!(new = (t_ac *)malloc(sizeof(t_ac))))
			return (NULL);
		new->action = action;
		first->next = new;
		new->next = NULL;
		new->prev = first;
		return (first);
	}
	else
		return (new_a_list(action));
}

static void	free_null_a(t_ac **todest)
{
	free(*todest);
	*todest = NULL;
}

t_ac		*destroy_a(t_ac *todest)
{
	t_ac *temp;

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
		free_null_a(&(todest->next));
	}
	else if (todest)
		free_null_a(&todest);
	return (todest);
}
