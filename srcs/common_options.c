/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 23:40:24 by besellem          #+#    #+#             */
/*   Updated: 2021/03/24 09:41:39 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#define OPT_V_HDR1 "---------------------------"
#define OPT_V_HDR2 "   Stack A   |   Stack B   "

/*
** Visualizer
*/

void		ft_opt_v(t_push_swap *data)
{
	t_list	*stack_a;
	t_list	*stack_b;

	usleep(70000);
	ft_putendl(CLR_SCREEN "" OPT_V_HDR1 "\n" OPT_V_HDR2 "\n" OPT_V_HDR1);
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
}

/*
** Visualizer (colored)
** Does not work with neg numbers and 0
*/

static void	opt_f_util(t_push_swap *data, t_list *stack_a, t_list *stack_b)
{
	int	tmp;

	tmp = 0;
	if (stack_a)
	{
		tmp = ((double)(int)stack_a->content / ft_lstmax(data->stack_a)) * 50.;
		ft_printf(F_CYAN"%*.0d"CLR_COLOR"%*.0d ", tmp, 0, 50 - tmp, 0);
	}
	else
		ft_printf("%*.0d ", 50, 0);
	if (stack_b)
	{
		tmp = ((double)(int)stack_b->content / ft_lstmax(data->stack_b)) * 50.;
		ft_printf(F_YELLOW"%*.0d"CLR_COLOR"%*.0d\n", tmp, 0, 50 - tmp, 0);
	}
	else
		ft_printf("%*.0d\n", 50, 0);
}

void		ft_opt_f(t_push_swap *data)
{
	t_list	*stack_a;
	t_list	*stack_b;

	usleep(12000);
	ft_putstr(CLR_SCREEN);
	stack_a = data->stack_a;
	stack_b = data->stack_b;
	while (stack_a || stack_b)
	{
		opt_f_util(data, stack_a, stack_b);
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
	}
}
