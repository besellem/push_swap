/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:31:08 by besellem          #+#    #+#             */
/*   Updated: 2021/03/18 23:07:47 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Algo #2
** Idea:
** backtracking algorithm, checking all the possibilities recursively and
** keeping the fastest.
**
** To implement
*/
// int		ft_backtrack(t_push_swap *data)
// {
// 	if (ft_is_sorted(data))
// 		return (1);
// 	return (1);
// }

/*
** swap all stack_b back in stack_a (using 'pa' operation)
*/

void	swap_stack_back(t_push_swap *data)
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

/*
** Algo #1
*/

void	algo_1(t_push_swap *data)
{
	const int	min_idx = ft_lstmin_idx(data->stack_a, NULL);
	int			i;

	if (min_idx < data->currently_in_stack_a / 2)
	{
		i = 0;
		while (i++ < min_idx && ft_exec_cmd(data, "ra", PROG_NAME))
			if (ft_is_sorted(data))
				return ;
	}
	else
	{
		i = data->currently_in_stack_a - min_idx;
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

void	sort_algo_1(t_push_swap *data)
{
	if (data->opt_v)
		ft_opt_v(data);
	while (!ft_is_sorted(data))
	{
		if (data->currently_in_stack_a == 2 &&
			(int)data->stack_a->content > (int)data->stack_a->next->content)
			ft_exec_cmd(data, "sa", PROG_NAME);
		if (data->stack_a && data->currently_in_stack_a > 2)
		{
			algo_1(data);
		}
		else
		{
			swap_stack_back(data);
		}
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

	tab = (int *)malloc(sizeof(int) * data->currently_in_stack_a);
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
	data->tab_size = data->currently_in_stack_a;
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
	while (++i < data->currently_in_stack_a - 1)
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
	{
		ft_exec_cmd(data, "ra", PROG_NAME);
	}
}

void	sort_sup_median(t_push_swap *data, int *tab)
{
	int	ocs;

	ocs = data->currently_in_stack_a;
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
	{
		ft_exec_cmd(data, "ra", PROG_NAME);
	}
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
** Quicksort
*/
int		partition(int *tab, int low, int high)
{
	int	pivot = tab[high];
	int	i;
	int	j;
 
	// Index of smaller element and indicates the right position of pivot found so far
	i = low - 1;
	j = low;
	while (j < high)
	{
		// If current element is smaller than the pivot
		if (tab[j] < pivot)
		{
			// increment index of smaller element
			++i;
			// swap(&tab[i], &tab[j]);
		}
		++j;
	}
	// swap(&tab[i + 1], &tab[high]);
	return (i + 1);
}

void	quickSort(int *tab, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		// pivot is partitioning index, tab[p] is now at right place
		pivot = partition(tab, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(tab, low, pivot - 1);
		quickSort(tab, pivot + 1, high);
	}
}

void	sort_algo_3(t_push_swap *data)
{
	int	*tab = ft_sort_lst_in_tab(data);

	if (data->opt_v)
		ft_opt_v(data);
	
	// printf(B_YELLOW"%s:%d:"CLR_COLOR" PASSING HERE\n", __FILE__, __LINE__);
	free((int *)tab);
}

void	sort5nbrs(t_push_swap *data)
{
	sort_algo_1(data);
}

void	ft_push_swap(t_push_swap *data)
{
	if (data->currently_in_stack_a <= 3)
		sort3nbrs(data);
	else if (data->currently_in_stack_a <= 5)
		sort5nbrs(data);
	else if (data->currently_in_stack_a <= 100)
		sort_algo_2(data);
	else
	{
		sort_algo_2(data);
		// sort_algo_3(data);
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
