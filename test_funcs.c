/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 11:32:52 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/03 17:43:46 by guiricha         ###   ########.fr       */
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
	while (!list->n->start)
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

int	is_pseudo_ordered(t_s *list)
{
	int	ret;
	int	tmpval;
	int	firstval;
	t_s	*tmp;

	ret = 0;
	tmp = list;
	tmpval = tmp->val;
	firstval = tmpval;
	while (tmp)
	{
		while ((tmp->val) <= tmp->n->val)
		{
			tmp = tmp->n;
			if (tmp->n->val == tmpval)
				return (l(list) - ret > ret ? ret : -(ft_abs(l(list) - ret)));
		}
		list = list->n;
		tmp = list;
		tmpval = tmp->val;
		ret++;
		if (tmpval == firstval)
			return (0);
	}
	return (ret);
}

int	is_ordered(t_s *list)
{
	int	tmpval;
	t_s	*tmp;

	tmp = list;
	tmpval = tmp->val;
	if (tmp && !tmp->end)
	{
		while ((tmp->val) <= tmp->n->val)
		{
			tmp = tmp->n;
		}
		if (tmp->end)
		{
			return (1);
		}
	}
	return (0);
}

int	l(t_s *s)
{
	int		count;
	void	*adr;

	adr = s;
	count = 0;
	if (s)
	{
		s = s->n;
		count++;
	}
	while (s != adr)
	{
		s = s->n;
		count++;
	}
	return (count);
}

int	l_action(t_action *s)
{
	int		count;

	count = 0;
	while (s && s->prev)
		s = s->prev;
	if (s)
	{
		s = s->next;
		count++;
	}
	while (s != NULL)
	{
		s = s->next;
		count++;
	}
	return (count);
}
