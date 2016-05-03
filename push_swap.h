/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 15:58:41 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/03 18:24:22 by guiricha         ###   ########.fr       */
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

typedef struct	s_main
{
	char		action;
	int			int_test;
	double		time;
	int			n_ops;
	int			n;
	int			dir;
	int			sml;
	int			color;
	int			draw;
	int			arg;
	int			nopsbub;
	int			nopsins;
	struct s_s	*abck;
}				t_main;

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
	char			action;
	struct s_action	*next;
	struct s_action	*prev;
}					t_action;


t_action	*new_a_list(char action);
t_action	*add_a_to_list(t_action *start, char action);
t_action	*destroy_a(t_action *todest);
void		print_actions(t_action **list, t_main *init);
t_s	*add_to_start(int value, t_s *begin);
int	get_smallest(t_s *start, int *dir);
int	get_biggest(t_s *start, int *dir);
int	is_pseudo_ordered(t_s *list);
int	is_ordered(t_s *list);
int	l(t_s *s); //length of stack
int	l_action(t_action *s);
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
void	print_lists(t_s *a, t_s *b, t_main *init, t_action *acts);
int		get_median(int *tab, unsigned int tab_len);
int		get_smaller_or_median(t_s *start, int median, int *stop);
t_action	*destroy_useless(t_action *list, int *nops);
void	apply_actions(t_s *a, t_s *b, t_action **list);
t_action	*do_algo(t_s **a, t_s **b, t_main *init, t_action **acts);
int		closest_swappable_pair(t_s *a);
t_action	*modify_stack(t_s **a, t_s **b, t_action **acts, t_main *init);
void		modify_stack2(t_s **a, t_s **b, t_action **acts, t_main *init);

#endif
