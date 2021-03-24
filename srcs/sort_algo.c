/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:38:58 by besellem          #+#    #+#             */
/*   Updated: 2021/03/24 10:52:26 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_lst_is_in_range(t_list *lst, int start, int end)
{
	t_list	*tmp;
	int		ocs;

	if (end < start)
		return (0);
	ocs = 0;
	tmp = lst;
	while (tmp)
	{
		if ((int)tmp->content >= start && (int)tmp->content <= end)
			++ocs;
		tmp = tmp->next;
	}
	return (ocs);
}

static void	unsort_stack_b(t_push_swap *data)
{
	int	min;

	while (data->stack_b)
	{
		min = ft_lstmin(data->stack_b);
		if ((int)data->stack_b->content == min)
		{
			ft_exec_cmd(data, "pa", PROG_NAME);
			ft_exec_cmd(data, "ra", PROG_NAME);
		}
		else
		{
			if ((int)ft_lstlast(data->stack_b)->content == min ||
				ft_lstmin_idx(data->stack_b, NULL) >= data->in_stack_b / 2)
				ft_exec_cmd(data, "rrb", PROG_NAME);
			else
				ft_exec_cmd(data, "rb", PROG_NAME);
		}
	}
}

static int	push_to_stack_b(t_push_swap *data, const int *tab,
							int start, int end)
{
	int	count;

	count = 0;
	while (ft_lst_is_in_range(data->stack_a, tab[start - 1], tab[end - 1]))
	{
		if ((int)data->stack_a->content >= tab[start - 1]
			&& (int)data->stack_a->content <= tab[end - 1])
			ft_exec_cmd(data, "pb", PROG_NAME);
		else
		{
			ft_exec_cmd(data, "ra", PROG_NAME);
			++count;
		}
	}
	return (count);
}

static void	place_stack_a(t_push_swap *data, int start, int count)
{
	int	tmp;

	tmp = ft_lstmin_idx(data->stack_a, NULL) + (data->in_stack_a - \
		(count + ft_lstmin_idx(data->stack_a, NULL)));
	if (start != 1 && tmp < count)
	{
		count = tmp;
		while (count-- > 0)
			ft_exec_cmd(data, "ra", PROG_NAME);
	}
	else if (start != 1)
	{
		while (count-- > 0)
			ft_exec_cmd(data, "rra", PROG_NAME);
	}
}

void		sort_algo(t_push_swap *data, int div)
{
	const int	*tab = ft_sort_lst_in_tab(data);
	double		start;
	double		end;
	int			count;

	start = 1;
	end = data->tab_size / (double)div;
	while (start <= data->tab_size)
	{
		count = push_to_stack_b(data, tab, (int)start, (int)end);
		place_stack_a(data, start, count);
		unsort_stack_b(data);
		start += data->tab_size / (double)div;
		end += data->tab_size / (double)div;
	}
	if (!ft_is_sorted(data) && ft_lstmax_idx(data->stack_a, NULL) == 0)
		ft_exec_cmd(data, "ra", PROG_NAME);
	free((int *)tab);
}
