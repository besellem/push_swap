/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:57:35 by besellem          #+#    #+#             */
/*   Updated: 2021/03/24 11:01:03 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set3nbrs(t_push_swap *data, int tab[3])
{
	tab[0] = (int)data->stack_a->content;
	tab[1] = (int)data->stack_a->next->content;
	tab[2] = (int)data->stack_a->next->next->content;
}

static void	sort3nbrs_utils(t_push_swap *data, int tab[3])
{
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

void		sort3nbrs(t_push_swap *data)
{
	int	tab[3];

	if (data->in_stack_a == 2)
	{
		ft_exec_cmd(data, "sa", PROG_NAME);
		return ;
	}
	set3nbrs(data, tab);
	sort3nbrs_utils(data, tab);
}
