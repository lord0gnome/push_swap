/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 11:32:52 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/10 14:25:32 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	closest_swappable_pair(t_s *a)
{
	t_s *back;
	t_s *frwd;
	int	counter;

	if (a->val > a->n->val)
		return (1);
	back = a->p;
	frwd = a->n;
	counter = 0;
	while (back && frwd)
	{
		if (back == a || frwd == a)
			break ;
		counter++;
		if (back->val < back->p->val)
			return ((-counter) - 1);
		if (frwd->val > frwd->n->val)
			return (counter + 1);
		back = back->p;
		frwd = frwd->n;
	}
	return (counter);
}

int	get_smallest(t_s *start, int *dir)
{
	t_s	*tmp;
	int	smallest;
	int	tmpval;

	*dir = 0;
	tmp = start;
	if (tmp)
		tmpval = tmp->val;
	smallest = tmp->val;
	tmp = tmp->n;
	while (tmp && !tmp->start)
	{
		if (tmp->val < smallest)
			smallest = tmp->val;
		tmp = tmp->n;
	}
	tmp = start;
	while (tmp && tmp->val != smallest)
	{
		tmp = tmp->n;
		*dir += 1;
	}
	*dir = l(start) - *dir > *dir ? *dir : -(ft_abs(l(start) - *dir));
	return (smallest);
}

int	get_biggest(t_s *start, int *dir)
{
	t_s	*tmp;
	int	biggest;
	int	tmpval;

	*dir = 0;
	tmp = start;
	if (tmp)
		tmpval = tmp->val;
	biggest = tmp->val;
	tmp = tmp->n;
	while (tmp && !tmp->start)
	{
		if (tmp->val > biggest)
			biggest = tmp->val;
		tmp = tmp->n;
	}
	tmp = start;
	while (tmp && tmp->val != biggest)
	{
		tmp = tmp->n;
		*dir += 1;
	}
	*dir = l(start) - *dir > *dir ? *dir : -(ft_abs(l(start) - *dir));
	return (biggest);
}

int	get_smaller_or_median(t_s *start, int median, int *stop)
{
	t_s *back;
	t_s *frwd;
	int index;

	index = 0;
	back = start;
	frwd = start;
	while (back && start && back->val > median && frwd->val > median)
	{
		back = back->p;
		frwd = frwd->n;
		index++;
		if (back->val <= median)
			return (-index);
		else if (frwd->val <= median)
			return (index);
		if (back == start || frwd == start)
		{
			*stop = 1;
			return (0);
		}
	}
	return (index);
}

int	test_doubles(t_s *list)
{
	int current;
	int	totallen;
	int	tlbck;
	int	ret;
	t_s	*next;

	ret = 1;
	totallen = l(list);
	tlbck = totallen;
	next = list;
	while (list && !list->n->start)
	{
		totallen = tlbck;
		current = list->val;
		while (totallen)
		{
			if (list && list->val == current && totallen != tlbck)
				ret--;
			list = list->n;
			totallen--;
		}
		next = next->n;
		list = next;
	}
	return (ret);
}
