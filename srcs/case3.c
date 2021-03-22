/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:57:35 by besellem          #+#    #+#             */
/*   Updated: 2021/03/22 19:31:05 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort3nbrs_edges(t_push_swap *data)
{
	if (ft_is_sorted(data))
		return (1);
	if (data->in_stack_a == 2)
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

void		sort3nbrs(t_push_swap *data)
{
	int	tab[3];

	if (sort3nbrs_edges(data))
		return ;
	set3nbrs(data, tab);
	if (tab[0] > tab[1] && tab[1] > tab[2])	// [3 2 1]
	{
		ft_exec_cmd(data, "ra", PROG_NAME);
		ft_exec_cmd(data, "sa", PROG_NAME);
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2])
	{
		if (tab[0] < tab[2])				// [2 1 3]
			ft_exec_cmd(data, "sa", PROG_NAME);
		else								// [3 1 2]
			ft_exec_cmd(data, "ra", PROG_NAME);
	}
	else if (tab[0] < tab[1] && tab[1] > tab[2])
	{
		if (tab[0] > tab[2])				// [2 3 1]
			ft_exec_cmd(data, "rra", PROG_NAME);
		else								// [1 3 2]
		{
			ft_exec_cmd(data, "sa", PROG_NAME);
			ft_exec_cmd(data, "ra", PROG_NAME);
		}
	}
}