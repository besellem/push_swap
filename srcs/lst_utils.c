/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:17:25 by besellem          #+#    #+#             */
/*   Updated: 2021/03/16 10:28:28 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	ft_lstmin_idx(t_list *lst)
{
	t_list	*tmp;
	int		idx;
	int		min;
	int		i;

	min = INT32_MAX;
	i = 0;
	idx = 0;
	tmp = lst;
	while (tmp)
	{
		if ((int)tmp->content < min)
		{
			min = (int)tmp->content;
			idx = i;
		}
		++i;
		tmp = tmp->next;
	}
	return (idx);
}

int	ft_lstmax_idx(t_list *lst)
{
	t_list	*tmp;
	int		idx;
	int		max;
	int		i;

	max = INT32_MIN;
	i = 0;
	idx = 0;
	tmp = lst;
	while (tmp)
	{
		if ((int)tmp->content > max)
		{
			max = (int)tmp->content;
			idx = i;
		}
		++i;
		tmp = tmp->next;
	}
	return (idx);
}
