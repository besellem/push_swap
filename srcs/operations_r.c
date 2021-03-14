/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:07:32 by besellem          #+#    #+#             */
/*   Updated: 2021/03/14 22:52:49 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_op_ra(t_push_swap *data)
{
	t_list *tmp;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	tmp = data->stack_a;
	data->stack_a = data->stack_a->next;
	tmp->next = NULL;
	ft_lstadd_back(&data->stack_a, tmp);
}

void	ft_op_rb(t_push_swap *data)
{
	t_list *tmp;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	tmp = data->stack_b;
	data->stack_b = data->stack_b->next;
	tmp->next = NULL;
	ft_lstadd_back(&data->stack_b, tmp);
}

void	ft_op_rr(t_push_swap *data)
{
	ft_op_ra(data);
	ft_op_rb(data);
}
