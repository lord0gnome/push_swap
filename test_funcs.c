/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 11:32:52 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/27 19:40:12 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_greater_than_median(t_s *start, int median)
{
	t_s *back;
	t_s *frwd;
	int index;

	index = 0;
	back = start;
	frwd = start;
	while (back->val < median && frwd->val < median)
	{
		if (back->val > median)
			return (-index);
		else if (frwd->val > median)
			return (index);
		back = back->p;
		frwd = frwd->n;
		index++;
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
	current = list->val;
	next = list;
	while(list)
	{
		totallen = tlbck;
		current = list->val;
		while (totallen)
		{
			if (list && list->val == current && totallen != tlbck)
			{
				ret--;
				break ;
			}
			list = list->n;
			totallen--;
		}
		ft_putchar('\n');
		if (list->end)
			break ;
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

int	get_median_in_scope(t_s *start, t_s *end)
{
	int	median;
	t_s	*temp;
	t_s *begin;
	int	biggerthan;
	int	smallerthan;
	int	bestdiff;
	int	currdiff;

	temp = start->n;
	begin = start;
	bestdiff = 93459345;
	while (start != end)
	{
		biggerthan = 0;
		smallerthan = 0;
		while (temp != begin)
		{
			ft_wait(10);
			if (start->val > temp->val)
				biggerthan++;
			if (start->val < temp->val)
				smallerthan++;
			ft_printf("<<comparing [%d] and [%d]  __  ", start->val, temp->val);
			ft_printf("smallerthan[%d] biggerthan[%d]\n", smallerthan, biggerthan);
			temp = temp->p;
		}
		temp = start->n;
		while (temp != end->n)
		{
			ft_wait(10);
			if (start->val > temp->val)
				biggerthan++;
			if (start->val < temp->val)
				smallerthan++;
			ft_printf(">>comparing [%d] and [%d]  __  ", start->val, temp->val);
			ft_printf("smallerthan[%d] biggerthan[%d]\n", smallerthan, biggerthan);
			temp = temp->n;
		}
		currdiff = ft_abs(smallerthan - biggerthan);
		if (bestdiff == 93459345)
		{
			median = start->val;
			bestdiff = currdiff;
		}
		median = currdiff < bestdiff ? start->val : median;
		start = start->n;
		temp = start->n;

	}
	return (median);
}
