/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:39:20 by besellem          #+#    #+#             */
/*   Updated: 2021/03/24 10:43:30 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*cp_lst_in_tab(t_push_swap *data)
{
	t_list	*tmp;
	int		*tab;
	int		i;

	tab = (int *)malloc(sizeof(int) * data->in_stack_a);
	if (!tab)
		return (NULL);
	i = 0;
	tmp = data->stack_a;
	while (tmp)
	{
		tab[i] = (int)tmp->content;
		tmp = tmp->next;
		++i;
	}
	data->tab_size = data->in_stack_a;
	return (tab);
}

int			*ft_sort_lst_in_tab(t_push_swap *data)
{
	int	*tab;
	int	tmp;
	int	i;

	tab = cp_lst_in_tab(data);
	if (!tab)
		ft_quit_error(data);
	i = -1;
	while (++i < data->in_stack_a - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
	}
	return (tab);
}
