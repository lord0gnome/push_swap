/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:37:26 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/03 18:24:17 by guiricha         ###   ########.fr       */
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
	init->n = 0;
	init->dir = 0;
	init->sml = 0;
	init->color = 0;
	init->draw = 0;
	init->arg = 0;
	init->nopsbub = 0;
	init->nopsins = 0;
	init->abck = NULL;
	return (init);
}

static void		do_args(t_main *init, char **argv)
{
	if (argv[1][0] == '-')
	{
		while (argv[1][init->n])
		{
			if (argv[1][init->n] == 'h')
			{
				ft_putstr("available commands\n -c : Draw in color the list ");
				ft_putstr("of actions\n -tNBR : slow by NBR time\n ");
				ft_putstr("-v : Draw all sequenced actions\n");
			}
			if (argv[1][init->n] == 'c')
				init->color = 1;
			else if (argv[1][init->n] == 'v')
				init->draw = 1;
			else if (argv[1][init->n] == 't')
			{
				init->time = ft_atoi(argv[1] + (init->n + 1));
				init->n += ft_nbrlen(init->time);
			}
			init->n++;
		}
		init->arg = 1;
	}
}

static void		do_init(int argc, char **argv, t_s **a, t_main **init)
{
	*init = init_init();
	while (argc - (*init)->arg > 1)
	{
		do_args(*init, argv);
		if (argc == 2 && (*init)->arg)
			(*init)->arg = -1;
		(*init)->int_test = ft_atoll(argv[argc - 1]);
		if ((*init)->int_test > 2147483647 || (*init)->int_test < -2147483648)
			(*init)->arg = -1;
		*a = add_to_start(ft_atoi(argv[argc - 1]), *a);
		(*init)->abck = add_to_start(ft_atoi(argv[argc - 1]), (*init)->abck);
		argc--;
	}
}

int				main(int argc, char **argv)
{
	t_s			*a;
	t_s			*b;
	t_action	*acts;
	t_main		*init;

	acts = NULL;
	b = NULL;
	a = NULL;
	do_init(argc, argv, &a, &init);
	if (init->arg == -1)
		return (-1);
	init->n = 0;
	init->n_ops = test_doubles(a);
	if (init->n_ops != 1)
		return (0);
	init->n_ops = 0;
	acts = do_algo(&a, &b, init, &acts);
	print_lists(a, b, init, acts);
	if (init->draw == 0)
		print_actions(&acts, init);
	ft_putstr("\n");
	ft_putnbr(init->nopsins);
	return (0);
}
