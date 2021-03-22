/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 23:40:24 by besellem          #+#    #+#             */
/*   Updated: 2021/03/22 23:16:52 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#define OPT_V_HEADER1 "---------------------------"
#define OPT_V_HEADER2 "   Stack A   |   Stack B   "

void	ft_opt_v(t_push_swap *data)
{
	t_list *stack_a;
	t_list *stack_b;

	// usleep(160000);
	ft_putendl("\033[2J\033[H");
	ft_putendl(OPT_V_HEADER1 "\n" OPT_V_HEADER2 "\n" OPT_V_HEADER1);
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
