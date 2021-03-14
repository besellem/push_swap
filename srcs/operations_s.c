/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:13:09 by besellem          #+#    #+#             */
/*   Updated: 2021/03/14 21:59:36 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_op_sa(t_push_swap *data)
{
	void *tmp;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	tmp = data->stack_a->content;
	data->stack_a->content = data->stack_a->next->content;
	data->stack_a->next->content = tmp;
}

void	ft_op_sb(t_push_swap *data)
{
	void *tmp;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	tmp = data->stack_b->content;
	data->stack_b->content = data->stack_b->next->content;
	data->stack_b->next->content = tmp;
}

void	ft_op_ss(t_push_swap *data)
{
	ft_op_sa(data);
	ft_op_sb(data);
}
