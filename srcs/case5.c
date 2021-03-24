/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:02:40 by besellem          #+#    #+#             */
/*   Updated: 2021/03/24 10:56:24 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort3nbrs_edges(t_push_swap *data)
{
	if (data->in_stack_a == 2 &&
		(int)data->stack_a->content > (int)data->stack_a->next->content)
	{
		ft_exec_cmd(data, "sa", PROG_NAME);
		return (1);
	}
	return (0);
}

static void	set3nbrs(t_push_swap *data, int tab[])
{
	tab[0] = (int)data->stack_a->content;
	tab[1] = (int)data->stack_a->next->content;
	tab[2] = (int)data->stack_a->next->next->content;
}

static void	sort3nbrs_others(t_push_swap *data)
{
	int	tab[3];

	set3nbrs(data, tab);
	if (tab[0] > tab[1] && tab[1] > tab[2])
	{
		ft_exec_cmd(data, "ra", PROG_NAME);
		ft_exec_cmd(data, "sa", PROG_NAME);
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2])
	{
		if (tab[0] < tab[2])
			ft_exec_cmd(data, "sa", PROG_NAME);
		else
			ft_exec_cmd(data, "ra", PROG_NAME);
	}
	else if (tab[0] < tab[1] && tab[1] > tab[2])
	{
		if (tab[0] > tab[2])
			ft_exec_cmd(data, "rra", PROG_NAME);
		else
		{
			ft_exec_cmd(data, "sa", PROG_NAME);
			ft_exec_cmd(data, "ra", PROG_NAME);
		}
	}
}

void		sort5nbrs(t_push_swap *data)
{
	while (data->in_stack_a > 3)
	{
		if ((int)data->stack_a->content == ft_lstmin(data->stack_a))
			ft_exec_cmd(data, "pb", PROG_NAME);
		else
		{
			if (ft_lstmin_idx(data->stack_a, NULL) < data->in_stack_a / 2)
				ft_exec_cmd(data, "ra", PROG_NAME);
			else
				ft_exec_cmd(data, "rra", PROG_NAME);
		}
	}
	if (sort3nbrs_edges(data) == 0)
		sort3nbrs_others(data);
	if (ft_lstsize(data->stack_b) == 2 &&
		(int)data->stack_b->content < (int)data->stack_b->next->content)
		ft_exec_cmd(data, "sb", PROG_NAME);
	ft_exec_cmd(data, "pa", PROG_NAME);
	ft_exec_cmd(data, "pa", PROG_NAME);
}
