/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 23:40:24 by besellem          #+#    #+#             */
/*   Updated: 2021/03/14 23:47:23 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_opt_v(t_push_swap *data)
{
	t_list *stack_a;
	t_list *stack_b;

	ft_putendl("---------------------------\n   Stack A   |   Stack B");
	ft_putendl("---------------------------");
	stack_a = data->stack_a;
	stack_b = data->stack_b;
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("%12d | ", (int)stack_a->content);
			stack_a = stack_a->next;
		}
		else
			ft_printf("%12.0d | ", 0);
		if (stack_b)
		{
			ft_printf("%12d\n", (int)stack_b->content);
			stack_b = stack_b->next;
		}
		else
			ft_printf("%12.0d\n", 0);
	}
	ft_putchar('\n');
}
