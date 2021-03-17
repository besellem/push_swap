/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:31:08 by besellem          #+#    #+#             */
/*   Updated: 2021/03/17 16:10:38 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Algo #2
** Idea:
** backtracking algorithm, checking all the possibilities recursively and
** keeping the fastest.
**
** To implement
*/
// int		ft_backtrack(t_push_swap *data)
// {
// 	if (ft_is_sorted(data))
// 		return (1);
// 	return (1);
// }

/*
** swap all stack_b back in stack_a (using 'pa' operation)
*/

void	swap_stack_back(t_push_swap *data)
{
	t_list *tmp;

	tmp = data->stack_b;
	while (tmp)
	{
		ft_exec_cmd(data, "pa", PROG_NAME);
		if (ft_is_sorted(data))
			break ;
		tmp = tmp->next;
	}
}

/*
** Algo #1
*/

void	algo_1(t_push_swap *data)
{
	const int	min_idx = ft_lstmin_idx(data->stack_a, NULL);
	int			i;

	if (min_idx < data->currently_in_stack_a / 2)
	{
		i = 0;
		while (i++ < min_idx && ft_exec_cmd(data, "ra", PROG_NAME))
			if (ft_is_sorted(data))
				return ;
	}
	else
	{
		i = data->currently_in_stack_a - min_idx;
		while (i-- > 0 && ft_exec_cmd(data, "rra", PROG_NAME))
			if (ft_is_sorted(data))
				return ;
	}
	if (ft_stack_is_sorted(data->stack_a) && data->stack_b &&
		(int)data->stack_a->content > (int)data->stack_b->content)
		swap_stack_back(data);
	else
		ft_exec_cmd(data, "pb", PROG_NAME);
}

void	sort_lst(t_push_swap *data)
{
	if (data->opt_v)
		ft_opt_v(data);
	while (!ft_is_sorted(data))
	{
		if (data->currently_in_stack_a == 2 &&
			(int)data->stack_a->content > (int)data->stack_a->next->content)
			ft_exec_cmd(data, "sa", PROG_NAME);
		if (data->stack_a && data->currently_in_stack_a > 2)
		{
			algo_1(data);
		}
		else
		{
			swap_stack_back(data);
		}
	}
}

int		main(int ac, char **av)
{
	t_push_swap data;

	if (ac <= 1)
		return (0);
	ft_bzero(&data, sizeof(t_push_swap));
	ft_parse_args(ac, av, &data);
	ft_cpy_args(ac, av, &data);
	sort_lst(&data);
	ft_quit_sorted(&data);
	return (0);
}
