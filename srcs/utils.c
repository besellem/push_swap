/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 22:05:24 by besellem          #+#    #+#             */
/*   Updated: 2021/03/14 23:46:38 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_do_nothing(void *ptr)
{
	(void)ptr;
}

int		ft_exec_cmd(t_push_swap *data, char *line)
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
			return (1);
		}
		++i;
	}
	return (0);
}

void	ft_quit(t_push_swap *data)
{
	ft_putendl_fd("Error", 2);
	ft_lstclear(&data->stack_a, ft_do_nothing);
	ft_lstclear(&data->stack_b, ft_do_nothing);
	exit(EXIT_FAILURE);
}
