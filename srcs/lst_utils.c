/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:17:25 by besellem          #+#    #+#             */
/*   Updated: 2021/03/23 13:27:50 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	ft_lstmin(t_list *lst)
{
	t_list	*tmp;
	int		min;

	min = INT32_MAX;
	tmp = lst;
	while (tmp)
	{
		if (min > (int)tmp->content)
			min = (int)tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_lstmax(t_list *lst)
{
	t_list	*tmp;
	int		max;

	max = INT32_MIN;
	tmp = lst;
	while (tmp)
	{
		if (max < (int)tmp->content)
			max = (int)tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_lstmin_idx(t_list *lst, int *nb)
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
			if (nb)
				*nb = min;
			idx = i;
		}
		++i;
		tmp = tmp->next;
	}
	return (idx);
}

int	ft_lstmax_idx(t_list *lst, int *nb)
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
			if (nb)
				*nb = max;
			idx = i;
		}
		++i;
		tmp = tmp->next;
	}
	return (idx);
}
