/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 15:58:41 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/30 20:04:26 by guiricha         ###   ########.fr       */
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

typedef struct		s_action
{
	char			action; // 1 == pb, 2 == pa, 3 == ra, 4 == rra, 5 == rb, 6 == rrb 7 == sa, 8 == sb
	struct s_action	*next;
	struct s_action	*prev;
}					t_action;


t_action	*new_a_list(char action);
t_action	*add_a_to_list(t_action *last, char action);
t_action	*destroy_a(t_action *todest);
void		print_actions(t_action *list);
t_s	*add_to_start(int value, t_s *begin);
int	get_smallest(t_s *start, int *dir);
int	get_biggest(t_s *start, int *dir);
int	is_pseudo_ordered(t_s *list);
int	is_ordered(t_s *list);
int	l(t_s *s); //length of stack
int	test_doubles(t_s *list);
t_s	*create_list(int first);
t_s	*sa(t_s *a);
t_s	*sb(t_s *b);
t_s	*ra(t_s *a);
t_s	*rb(t_s *b);
t_s	*rrb(t_s *b);
t_s	*rra(t_s *a);
t_s	*pb(t_s *a, t_s **b);
t_s	*pa(t_s **a, t_s *b);
t_s *destroy(t_s **todestroy);
void	print_lists(t_s *a, t_s *b, double time, t_action *acts);
int		get_median(int *tab, unsigned int tab_len);
int		get_smaller_or_median(t_s *start, int median, int *stop);
t_action	*destroy_useless(t_action *list, int *nops);
void	apply_actions(t_s *a, t_s *b, t_action **list, double time);
t_s	*quick_sort_main(t_s *a, t_s **b, int *tab, int tab_len);

#endif
