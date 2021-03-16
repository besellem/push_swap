/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:31:08 by besellem          #+#    #+#             */
/*   Updated: 2021/03/16 16:01:32 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*
** #1 Algo
** 
*/

void	sort_get_lst_min(t_push_swap *data)
{
	int min_idx;
	int i;

	min_idx = ft_lstmin_idx(data->stack_a, NULL);
	if (min_idx < ft_lstsize(data->stack_a) / 2)
	{
		i = 0;
		while (i < min_idx)
		{
			ft_exec_cmd(data, "ra", PROG_NAME);
			++i;
		}
	// }
	// else
	// {
	// 	i = min_idx - 1;
	// 	while (i > 0)
	// 	{
	// 		ft_exec_cmd(data, "rra", PROG_NAME);
	// 		--i;
	// 	}
	// }
	ft_exec_cmd(data, "pb", PROG_NAME);
}

void	swap_stack_back(t_push_swap *data)
{
	t_list *tmp;

	tmp = data->stack_b;
	while (tmp)
	{
		ft_exec_cmd(data, "pa", PROG_NAME);
		tmp = tmp->next;
	}
}

void	sort_lst(t_push_swap *data)
{
	// t_list	*tmp;
	// int		min_idx;
	// int		i;

	while (!ft_is_sorted(data))
	{
		if (ft_lstsize(data->stack_a) == 2 &&
			(int)data->stack_a->content > (int)data->stack_a->next->content)
			ft_exec_cmd(data, "sa", PROG_NAME);
		if (data->stack_a && ft_lstsize(data->stack_a) > 2)
		{
			sort_get_lst_min(data);
		}
		else
		{
			swap_stack_back(data);
		}
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
	sort_lst(&data);
	ft_lstclear(&data.stack_a, NULL);
	ft_lstclear(&data.stack_b, NULL);
	return (0);
}
