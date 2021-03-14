/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:32:54 by besellem          #+#    #+#             */
/*   Updated: 2021/03/14 23:27:34 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_lst_check_duplicates(t_list *lst)
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

static void	ft_cpy_args(int ac, char **av, t_push_swap *data)
{
	t_list	*tmp;
	long	arg;
	int		i;

	i = data->start_arg;
	while (i < ac)
	{
		if (ft_strnlen(av[i], 12) == 12 || (!ft_strisdigit(av[i]) &&
			!((*av[i] == '-' || *av[i] == '+') && ft_strisdigit(av[i] + 1))))
			ft_quit(data, __FILE__, __LINE__);
		arg = ft_atol(av[i]);
		if (arg < INT32_MIN || arg > INT32_MAX)
			ft_quit(data, __FILE__, __LINE__);
		tmp = ft_lstnew((void *)(intptr_t)arg);
		if (!tmp)
			ft_quit(data, __FILE__, __LINE__);
		ft_lstadd_back(&data->stack_a, tmp);
		++i;
	}
	if (ft_lst_check_duplicates(data->stack_a) == 0)
		ft_quit(data, __FILE__, __LINE__);
}

static int	ft_checker(t_push_swap *data)
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

static void	ft_parser(t_push_swap *data)
{
	char	*line;
	int		check;

	if (data->opt_v)
		ft_print_stacks(data);
	while ((check = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		if (ft_exec_cmd(data, line) == 0)
		{
			free(line);
			ft_quit(data, __FILE__, __LINE__);
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
	if (ft_checker(&data))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_lstclear(&data.stack_a, ft_do_nothing);
	ft_lstclear(&data.stack_b, ft_do_nothing);
	return (0);
}
