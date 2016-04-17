/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 15:58:41 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/17 16:47:48 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# define RESET "\033[0m"


typedef struct	s_s
{
	int			val;
	struct s_s	*p;
	struct s_s	*n;
	char		start;
	char		end;
	char		looped;
}				t_s;


t_s	*add_to_start(int value, t_s *begin);
int	get_smallest(t_s *start, int *dir);
int	is_pseudo_ordered(t_s *list);
int	l(t_s *s); //length of stack
int	test_doubles(t_s *list);
t_s	*create_list(int first);
t_s	*sa(t_s *a);
t_s	*sb(t_s *b);
t_s	*ra(t_s *a);
t_s	*rb(t_s *b);
t_s	*rra(t_s *a);
t_s	*pb(t_s *a, t_s **b);
t_s	*pa(t_s **a, t_s *b);
t_s *destroy(t_s **todestroy);
void	print_lists(t_s *a, t_s *b, double time);

#endif
