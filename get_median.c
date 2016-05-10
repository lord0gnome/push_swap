/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:16:26 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/06 13:32:00 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_median(int *tab, unsigned int tab_len)
{
	int				median;

	if (!tab_len)
		return (tab[0]);
	median = tab[tab_len / 2];
	return (median);
}
