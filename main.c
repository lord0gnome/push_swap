/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:37:26 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/12 15:57:06 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf/ft_printf.h"
#include "libft/libft.h"

int		main(int argc, char **argv)
{
	int	*tab;
	int	i;

	i = 0;
	if (argc > 1)
		tab = (int *)malloc(sizeof(int) * argc);
	else
		return (0);
	while (argc > 1)
	{
		tab[i] = ft_atoi(argv[argc - 1]);
		i++;
		argc--;
	}
	tab[i] = -42;
	while (i--)
	ft_putnbr(tab[i]);

	return (0);
}
