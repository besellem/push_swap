/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:32:54 by besellem          #+#    #+#             */
/*   Updated: 2021/03/14 20:36:39 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_exec_cmd(t_push_swap *data, char *line)
{
	const t_operations ops[] = {
		{"sa", ft_op_sa}, {"sb", ft_op_sb}, {"ss", ft_op_ss}, {"pa", ft_op_pa},
		{"pb", ft_op_pb}, {"ra", ft_op_ra}, {"rb", ft_op_rb}, {"rr", ft_op_rr},
		{"rra", ft_op_rra}, {"rrb", ft_op_rrb}, {"rrr", ft_op_rrr}, {NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].operation_name)
	{
		if (ft_strcmp(ops[i].operation_name, line) == 0)
		{
			ops[i].f(data);
			ft_printf("All Good\n");
			return (1);
		}
		++i;
	}
	ft_printf("%s:%d: Error\n", __FILE__, __LINE__);
	return (0);
}

void	ft_lstprint(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	while (tmp)
	{
		printf("%d\n", (int)tmp->content);
		tmp = tmp->next;
	}
}

int		ft_lst_check_duplicates(t_list *lst)
{
	t_list *lst1;
	t_list *lst2;

	lst1 = lst;
	while (lst1)
	{
		lst2 = lst1->next;
		while (lst2)
		{
			if ((int)lst1->content == (int)lst2->content)
				return (0);
			lst2 = lst2->next;
		}
		lst1 = lst1->next;
	}
	return (1);
}

void	ft_do_nothing(__attribute__((unused))void *ptr)
{
	(void)ptr;
}

void	ft_quit(t_push_swap *data, char *file, int line)
{
	ft_dprintf(2, B_GREEN"%s:%d:"B_RED" Error"CLR_COLOR"\n", file, line);
	ft_putendl_fd("Error", 2);
	ft_lstclear(&data->stack_a, ft_do_nothing);
	ft_lstclear(&data->stack_b, ft_do_nothing);
	exit(EXIT_FAILURE);
}

void	ft_cpy_args(int ac, char **av, t_push_swap *data)
{
	long long	arg;
	int			i;

	i = data->start_arg;
	while (i < ac)
	{
		if (!ft_strisdigit(av[i])) // Not working with numbers < 0
			ft_quit(data, __FILE__, __LINE__);
		arg = ft_atoll(av[i]);
		if (arg < INT32_MIN || arg > INT32_MAX)
			ft_quit(data, __FILE__, __LINE__);
		ft_lstadd_back(&data->stack_a, ft_lstnew((void *)(intptr_t)arg));
		++i;
	}
	if (ft_lst_check_duplicates(data->stack_a) == 0)
		ft_quit(data, __FILE__, __LINE__);
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
}

void	ft_print_stacks(t_push_swap *data)
{
	t_list *stack_a;
	t_list *stack_b;

	ft_putstr(OPT_V_HEADER);
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

void	ft_parser(t_push_swap *data)
{
	char	*line;
	int		check;

	if (data->opt_v)
		ft_print_stacks(data);
	while ((check = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		if (ft_exec_cmd(data, line) == 0)
		{
			ft_putendl_fd("Error", 2);
			ft_lstclear(&data->stack_a, ft_do_nothing);
			ft_lstclear(&data->stack_b, ft_do_nothing);
			free(line);
			return ;
		}
		free(line);
		if (data->opt_v)
			ft_print_stacks(data);
		if (check == 0)
			break ;
	}
}

int			main(int ac, char **av)
{
	t_push_swap data;

	if (ac <= 1)
		return (0);
	ft_bzero(&data, sizeof(t_push_swap));
	ft_parse_args(ac, av, &data);
	ft_cpy_args(ac, av, &data);
	ft_parser(&data);
	return (0);
}
