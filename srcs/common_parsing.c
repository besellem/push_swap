/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 23:36:18 by besellem          #+#    #+#             */
/*   Updated: 2021/03/14 23:47:15 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void		ft_parse_args(int ac, char **av, t_push_swap *data)
{
	data->start_arg = 1;
	while (data->start_arg < ac)
	{
		if (ft_strcmp(av[data->start_arg], "-c") == 0)
			data->opt_c = 1;
		else if (ft_strcmp(av[data->start_arg], "-v") == 0)
			data->opt_v = 1;
		else
			break ;
		data->start_arg++;
	}
	if (data->start_arg == ac)
		exit(EXIT_SUCCESS);
}

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

void		ft_cpy_args(int ac, char **av, t_push_swap *data)
{
	t_list	*tmp;
	long	arg;
	int		i;

	i = data->start_arg;
	while (i < ac)
	{
		if (ft_strnlen(av[i], 12) == 12 || (!ft_strisdigit(av[i]) &&
			!((*av[i] == '-' || *av[i] == '+') && ft_strisdigit(av[i] + 1))))
			ft_quit(data);
		arg = ft_atol(av[i]);
		if (arg < INT32_MIN || arg > INT32_MAX)
			ft_quit(data);
		tmp = ft_lstnew((void *)(intptr_t)arg);
		if (!tmp)
			ft_quit(data);
		ft_lstadd_back(&data->stack_a, tmp);
		++i;
	}
	if (ft_lst_check_duplicates(data->stack_a) == 0)
		ft_quit(data);
}
