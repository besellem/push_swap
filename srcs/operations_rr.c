/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:14:27 by besellem          #+#    #+#             */
/*   Updated: 2021/03/14 22:50:57 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_op_rra(t_push_swap *data)
{
	t_list *lst;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	lst = data->stack_a;
	while (lst->next->next)
		lst = lst->next;
	ft_lstadd_front(&data->stack_a, lst->next);
	lst->next = NULL;
}

void	ft_op_rrb(t_push_swap *data)
{
	t_list *lst;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	lst = data->stack_b;
	while (lst->next->next)
		lst = lst->next;
	ft_lstadd_front(&data->stack_b, lst->next);
	lst->next = NULL;
}

void	ft_op_rrr(t_push_swap *data)
{
	ft_op_rra(data);
	ft_op_rrb(data);
}
