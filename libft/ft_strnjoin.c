/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 16:27:36 by guiricha          #+#    #+#             */
/*   Updated: 2016/03/20 17:00:52 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char				*new;
	unsigned int		count;

	count = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
		return (new);
	while (n && *s1)
	{
		*new++ = *s1++;
		n--;
		count++;
	}
	while (n && *s2)
	{
		*new++ = *s2++;
		n--;
		count++;
	}
	*new = '\0';
	return (new - count);
}
