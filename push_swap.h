/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 15:58:41 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/16 13:09:21 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"

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
t_s	*get_smallest(t_s *start);
int	is_smaller(t_s *start, t_s *next);
t_s	*create_list(int first);
t_s	*sa(t_s *a);
t_s	*sb(t_s *b);
t_s	*ra(t_s *a);
t_s	*rra(t_s *a);
t_s	*pb(t_s *a, t_s **b);
t_s	*pa(t_s **a, t_s *b);
t_s *destroy(t_s *todestroy);

#endif
