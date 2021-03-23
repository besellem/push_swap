/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 22:05:24 by besellem          #+#    #+#             */
/*   Updated: 2021/03/23 13:30:33 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		ft_stack_is_sorted(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	while (tmp->next)
	{
		if ((int)tmp->content > (int)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		ft_is_sorted(t_push_swap *data)
{
	t_list *stack_a;

	if (data->stack_b)
		return (0);
	stack_a = data->stack_a;
	while (stack_a->next)
	{
		if ((int)stack_a->content > (int)stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	ft_quit_error(t_push_swap *data)
{
	ft_putendl_fd("Error", 2);
	ft_lstclear(&data->stack_a, NULL);
	ft_lstclear(&data->stack_b, NULL);
	exit(EXIT_FAILURE);
}

void	ft_quit_sorted(t_push_swap *data)
{
	ft_lstclear(&data->stack_a, NULL);
	ft_lstclear(&data->stack_b, NULL);
	exit(EXIT_SUCCESS);
}

int		ft_exec_cmd(t_push_swap *data, char *line, char *prog_name)
{
	const t_operations	ops[] = {
		{"sa", ft_op_sa}, {"sb", ft_op_sb}, {"ss", ft_op_ss}, {"pa", ft_op_pa},
		{"pb", ft_op_pb}, {"ra", ft_op_ra}, {"rb", ft_op_rb}, {"rr", ft_op_rr},
		{"rra", ft_op_rra}, {"rrb", ft_op_rrb}, {"rrr", ft_op_rrr}, {NULL, NULL}
	};
	int					i;

	i = 0;
	while (ops[i].operation_name)
	{
		if (ft_strcmp(ops[i].operation_name, line) == 0)
		{
			ops[i].f(data);
			if (ft_strcmp(prog_name, PROG_PUSH_SWAP) == 0)
				ft_putendl(ops[i].operation_name);
			if (data->opt_f)
				ft_opt_f(data);
			else if (data->opt_v)
				ft_opt_v(data);
			return (1);
		}
		++i;
	}
	return (0);
}
