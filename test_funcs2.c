/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 16:26:06 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/10 14:30:45 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_s	*tmp;

	tmp = list;
	if (tmp && tmp->n == tmp)
		return (1);
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

int	l_action(t_ac *s)
{
	int		count;

	count = 0;
	while (s && (s)->prev)
		(s) = (s)->prev;
	while ((s) != NULL)
	{
		(s) = (s)->next;
		count++;
	}
	return (count);
}
