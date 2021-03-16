/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:35:27 by besellem          #+#    #+#             */
/*   Updated: 2021/03/16 21:29:24 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <libft.h>

/*
** -- DATA STRUCTURES --
*/
# define PROG_PUSH_SWAP "push_swap"
# define PROG_CHECKER "checker"

/*
** -- DATA STRUCTURES --
*/
typedef	struct	s_push_swap
{
	int		opt_c : 2;
	int		opt_v : 2;
	int		start_arg;
	int		currently_in_stack_a;
	int		currently_in_stack_b;
	t_list	*stack_a;
	t_list	*stack_b;
}				t_push_swap;

typedef	struct	s_operations
{
	char	*operation_name;
	void	(*f)(t_push_swap *);
}				t_operations;

/*
** -- PROTOTYPES --
** Common
*/
int				ft_stack_is_sorted(t_list *lst);
int				ft_is_sorted(t_push_swap *data);
int				ft_exec_cmd(t_push_swap *data, char *line, char *prog_name);
void			ft_quit_error(t_push_swap *data);
void			ft_quit_sorted(t_push_swap *data);

/*
** Utils
*/
int				ft_lstmin_idx(t_list *lst, int *nb);
int				ft_lstmax_idx(t_list *lst, int *nb);

/*
** Parsing
*/
void			ft_parse_args(int ac, char **av, t_push_swap *data);
void			ft_cpy_args(int ac, char **av, t_push_swap *data);

/*
** Options
*/
void			ft_opt_v(t_push_swap *data);

/*
** operations
*/
void			ft_op_sa(t_push_swap *data);
void			ft_op_sb(t_push_swap *data);
void			ft_op_ss(t_push_swap *data);
void			ft_op_pa(t_push_swap *data);
void			ft_op_pb(t_push_swap *data);
void			ft_op_ra(t_push_swap *data);
void			ft_op_rb(t_push_swap *data);
void			ft_op_rr(t_push_swap *data);
void			ft_op_rra(t_push_swap *data);
void			ft_op_rrb(t_push_swap *data);
void			ft_op_rrr(t_push_swap *data);

#endif
