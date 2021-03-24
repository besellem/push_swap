/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:31:08 by besellem          #+#    #+#             */
/*   Updated: 2021/03/24 10:43:31 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_swap(t_push_swap *data)
{
	if (ft_is_sorted(data))
		return ;
	if (data->in_stack_a <= 3)
		sort3nbrs(data);
	else if (data->in_stack_a <= 5)
		sort5nbrs(data);
	else if (data->in_stack_a <= 180)
		sort_algo(data, 4);
	else
		sort_algo(data, 10);
}

int			main(int ac, char **av)
{
	t_push_swap	data;

	if (ac < 2)
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
