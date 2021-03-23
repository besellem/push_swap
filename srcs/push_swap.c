/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:31:08 by besellem          #+#    #+#             */
/*   Updated: 2021/03/23 15:23:59 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Algo #1
*/

static void	swap_stack_back(t_push_swap *data)
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

static void	algo_1(t_push_swap *data)
{
	const int	min_idx = ft_lstmin_idx(data->stack_a, NULL);
	int			i;

	if (min_idx < data->in_stack_a / 2)
	{
		i = 0;
		while (i++ < min_idx && ft_exec_cmd(data, "ra", PROG_NAME))
			if (ft_is_sorted(data))
				return ;
	}
	else
	{
		i = data->in_stack_a - min_idx;
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

void		sort_algo_1(t_push_swap *data)
{
	if (data->opt_v)
		ft_opt_v(data);
	while (!ft_is_sorted(data))
	{
		if (data->in_stack_a == 2 &&
			(int)data->stack_a->content > (int)data->stack_a->next->content)
			ft_exec_cmd(data, "sa", PROG_NAME);
		if (data->stack_a && data->in_stack_a > 2)
			algo_1(data);
		else
			swap_stack_back(data);
	}
}

/*
** ALGO #2
** Quicksort like
*/

// SORT LST IN TAB
int	get_median(const int *tab, size_t size)
{
	return (tab[size / 2]);
}

int	get_max_tab(const int *tab, size_t size)
{
	size_t	i;
	int		max;

	max = INT32_MIN;
	i = 0;
	while (i < size)
	{
		if (max < tab[i])
			max = tab[i];
		++i;
	}
	return (max);
}

int	get_min_tab(const int *tab, size_t size)
{
	size_t	i;
	int		min;

	min = INT32_MAX;
	i = 0;
	while (i < size)
	{
		if (min > tab[i])
			min = tab[i];
		++i;
	}
	return (min);
}

int		*cp_lst_in_tab(t_push_swap *data)
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

int		*ft_sort_lst_in_tab(t_push_swap *data)
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
// END SORT LST IN TAB

void	sort_stack_b(t_push_swap *data)
{
	int min;
	int max;

	while (data->stack_b)
	{
		min = ft_lstmin(data->stack_b);
		max = ft_lstmax(data->stack_b);
		if ((int)data->stack_b->content == min)
		{
			ft_exec_cmd(data, "pa", PROG_NAME);
			ft_exec_cmd(data, "ra", PROG_NAME);
		}
		else if ((int)data->stack_b->content == max)
		{
			ft_exec_cmd(data, "pa", PROG_NAME);
		}
		else
		{
			if ((int)ft_lstlast(data->stack_b)->content == max || 
				(int)ft_lstlast(data->stack_b)->content == min)
				ft_exec_cmd(data, "rrb", PROG_NAME);
			else
				ft_exec_cmd(data, "rb", PROG_NAME);
		}
	}
}

void	sort_inf_median(t_push_swap *data, int *tab)
{
	int	ocs;

	ocs = 0;
	while (ocs < get_median(tab, data->tab_size) - 1)
	{
		if ((int)data->stack_a->content < get_median(tab, data->tab_size))
		{
			ft_exec_cmd(data, "pb", PROG_NAME);
			++ocs;
		}
		else
			ft_exec_cmd(data, "ra", PROG_NAME);
	}
	sort_stack_b(data);
	while (data->stack_a &&
		(int)data->stack_a->content < get_median(tab, data->tab_size))
		ft_exec_cmd(data, "ra", PROG_NAME);
}

void	sort_sup_median(t_push_swap *data, int *tab)
{
	int	ocs;

	ocs = data->in_stack_a;
	while (ocs > get_median(tab, data->tab_size))
	{
		if ((int)data->stack_a->content > get_median(tab, data->tab_size))
		{
			ft_exec_cmd(data, "pb", PROG_NAME);
			--ocs;
		}
		else
			ft_exec_cmd(data, "ra", PROG_NAME);
	}
	sort_stack_b(data);
	while (data->stack_a &&
		(int)data->stack_a->content > get_median(tab, data->tab_size))
		ft_exec_cmd(data, "ra", PROG_NAME);
}

void	sort_algo_2(t_push_swap *data)
{
	int	*tab = ft_sort_lst_in_tab(data);

	if (data->opt_v)
		ft_opt_v(data);
	sort_inf_median(data, tab);
	sort_sup_median(data, tab);
	free((int *)tab);
}

/*
** ALGO #3
** Quicksort like
*/

int		ft_lst_is_in_range(t_list *lst, int start, int end)
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

void	unsort_stack_b(t_push_swap *data)
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

void	sort_algo_3(t_push_swap *data, double div)
{
	const int	*tab = ft_sort_lst_in_tab(data);
	double		start;
	double		end;
	int			count;

	start = 1;
	end = data->tab_size / div;
	while (start < data->tab_size)// - (data->tab_size % 2 == 0))
	{
		count = 0;
		while (ft_lst_is_in_range(data->stack_a, tab[(int)start - 1], tab[(int)end - 1]))
		{
			if ((int)data->stack_a->content >= tab[(int)start - 1]
				&& (int)data->stack_a->content <= tab[(int)end - 1])
				ft_exec_cmd(data, "pb", PROG_NAME);
			else
			{
				ft_exec_cmd(data, "ra", PROG_NAME);
				++count;
			}
		}
		if (0)
		{
			count = count + end;
			while (count-- > 0)
			{
				ft_exec_cmd(data, "ra", PROG_NAME);
				printf("Here\n");
				exit(1);
			}
		}
		else
		{
			while (count-- > 0)
				ft_exec_cmd(data, "rra", PROG_NAME);
		}
		unsort_stack_b(data);
		start += data->tab_size / div;
		end += data->tab_size / div;
	}
	free((int *)tab);
}

void	ft_push_swap(t_push_swap *data)
{
	if (data->in_stack_a <= 3)
		sort3nbrs(data);
	else if (data->in_stack_a <= 5)
		sort5nbrs(data);
	else if (data->in_stack_a <= 180)
	{
		sort_algo_1(data);
		// sort_algo_3(data, 2.);
	}
	else
	{
		// sort_algo_2(data);
		sort_algo_3(data, 10.);
	}
}

int		main(int ac, char **av)
{
	t_push_swap	data;

	if (ac <= 1)
		return (0);
	ft_bzero(&data, sizeof(t_push_swap));
	ft_parse_args(ac, av, &data);
	ft_cpy_args(ac, av, &data);
	if (data.opt_v)
		ft_opt_v(&data);
	ft_push_swap(&data);
	ft_quit_sorted(&data);
	return (0);
}
