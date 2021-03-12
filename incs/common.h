/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:35:27 by besellem          #+#    #+#             */
/*   Updated: 2021/03/12 17:22:34 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <libft.h>

/*
** -- DATA STRUCTURES --
*/
typedef	struct	s_operations
{
	char	*func_name;
	void	(*f)();
}				t_operations;

typedef	struct	s_data
{
	size_t	stacks_size;
	int		*a_stack;
	int		*b_stack;
}				t_data;

/*
** -- PROTOTYPES --
** operations
*/
void	ft_op_sa(t_data *data);
void	ft_op_sb(t_data *data);
void	ft_op_ss(t_data *data);
void	ft_op_pa(t_data *data);
void	ft_op_pb(t_data *data);
void	ft_op_ra(t_data *data);
void	ft_op_rb(t_data *data);
void	ft_op_rr(t_data *data);
void	ft_op_rra(t_data *data);
void	ft_op_rrb(t_data *data);
void	ft_op_rrr(t_data *data);

#endif
