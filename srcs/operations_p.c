/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:14:48 by besellem          #+#    #+#             */
/*   Updated: 2021/03/22 19:31:29 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_op_pa(t_push_swap *data)
{
	t_list *tmp;

	if (!data->stack_b)
		return ;
	tmp = data->stack_b->next;
	data->stack_b->next = NULL;
	ft_lstadd_front(&data->stack_a, data->stack_b);
	data->stack_b = tmp;
	data->in_stack_a++;
	data->in_stack_b--;
}

void	ft_op_pb(t_push_swap *data)
{
	t_list *tmp;

	if (!data->stack_a)
		return ;
	tmp = data->stack_a->next;
	data->stack_a->next = NULL;
	ft_lstadd_front(&data->stack_b, data->stack_a);
	data->stack_a = tmp;
	data->in_stack_a--;
	data->in_stack_b++;
}
