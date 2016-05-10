/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:37:26 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/10 15:09:58 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static t_main	*init_init(void)
{
	t_main	*init;

	if ((init = (t_main *)malloc(sizeof(t_main))) == NULL)
		return (NULL);
	init->int_test = 0;
	init->time = 0;
	init->n_ops = 0;
	init->n = 1;
	init->dir = 0;
	init->sml = 0;
	init->color = 0;
	init->draw = 0;
	init->arg = 0;
	init->nopsbub = 0;
	init->nopsins = 0;
	init->abck = NULL;
	init->abck2 = NULL;
	init->nacts = 0;
	return (init);
}

static int		str_test(char *str)
{
	int	atleast;

	atleast = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		str++;
		atleast++;
	}
	if (!(*str) && atleast > 0)
		return (1);
	else
		return (0);
}

static int		do_args(t_main *init, char **argv)
{
	if (argv[1][0] == '-' && !ft_isdigit(argv[1][1]))
	{
		while (argv[1][init->n])
		{
			if (argv[1][init->n] == 'h')
				ft_putstr("-c colr\n-vtNBR visual + time*NBR\n-a actions\n");
			else if (argv[1][init->n] == 'c')
				init->color = 1;
			else if (argv[1][init->n] == 'v')
				init->draw = 1;
			else if (argv[1][init->n] == 't')
			{
				init->time = ft_atoi(argv[1] + (init->n + 1));
				init->n += ft_nbrlen(init->time);
			}
			else if (argv[1][init->n] == 'a')
				init->nacts = 1;
			else
				return (-1);
			init->n++;
		}
		init->arg = 1;
	}
	return (1);
}

static int		do_init(int argc, char **argv, t_s **a, t_main **init)
{
	if ((*init = init_init()) == NULL)
		return (-1);
	if (argc > 1)
		if (do_args(*init, argv) == -1)
			return (-1);
	while (argc - (*init)->arg > 1)
	{
		(*init)->int_test = ft_atoll(argv[argc - 1]);
		if (str_test(argv[argc - 1]) == 0)
			(*init)->sml = -1;
		if ((*init)->int_test > 2147483647 || (*init)->int_test < -2147483648)
			(*init)->sml = -1;
		*a = add_to_start(ft_atoi(argv[argc - 1]), *a);
		if (*a == NULL)
			return (0);
		(*init)->abck = add_to_start((*a)->val, (*init)->abck);
		(*init)->abck2 = add_to_start((*a)->val, (*init)->abck2);
		argc--;
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_s			*a;
	t_s			*b;
	t_ac		*acts;
	t_main		*init;

	acts = NULL;
	b = NULL;
	a = NULL;
	if (do_init(argc, argv, &a, &init) == -1)
		return (write(2, "Error\n", 6));
	init->n = test_doubles(a);
	if ((!init) || init->sml == -1 || init->n != 1)
		return (write(2, "Error\n", 6));
	if (!a || is_ordered(a))
		return (1);
	acts = do_algo(&a, &b, init, &acts);
	a = init->abck2;
	acts = destroy_useless(acts);
	if (init->draw == 0)
		print_actions(&acts, init);
	else
		apply_actions(&a, &b, &acts, init);
	if (init->nacts == 1)
		ft_printf("\nNumber of operations:%d", init->n_ops);
	return (0);
}
