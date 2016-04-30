/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:16:26 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/30 20:35:17 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_median(int *tab, unsigned int tab_len)
{
	int	median;
	unsigned int	index;

	index = 0;
	if (!tab_len)
		return (tab[0]);
	while (index < tab_len / 2)
		median = tab[index++];
	return (median);
}
