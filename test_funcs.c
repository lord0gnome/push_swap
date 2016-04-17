/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 11:32:52 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/17 14:27:39 by guiricha         ###   ########.fr       */
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
