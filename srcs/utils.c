/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 22:05:24 by besellem          #+#    #+#             */
/*   Updated: 2021/03/14 23:28:05 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_quit(t_push_swap *data, char *file, int line)
{
	ft_dprintf(2, B_GREEN"%s:%d:"B_RED" Error"CLR_COLOR"\n", file, line);
	ft_putendl_fd("Error", 2);
	ft_lstclear(&data->stack_a, ft_do_nothing);
	ft_lstclear(&data->stack_b, ft_do_nothing);
	exit(EXIT_FAILURE);
}

void	ft_print_stacks(t_push_swap *data)
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

void	ft_parse_args(int ac, char **av, t_push_swap *data)
{
	data->start_arg = 1;
	while (data->start_arg < ac)
	{
		if (ft_strcmp(av[data->start_arg], "-c") == 0)
			data->opt_c = 1;
		else if (ft_strcmp(av[data->start_arg], "-v") == 0)
			data->opt_v = 1;
		else
			break ;
		data->start_arg++;
	}
	if (data->start_arg == ac)
		exit(EXIT_SUCCESS);
}

void	ft_do_nothing(void *ptr)
{
	(void)ptr;
}
