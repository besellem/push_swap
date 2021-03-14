/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:32:54 by besellem          #+#    #+#             */
/*   Updated: 2021/03/14 23:47:00 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_is_sorted(t_push_swap *data)
{
	t_list *stack_a;

	if (data->stack_b)
		return (0);
	stack_a = data->stack_a;
	while (stack_a->next)
	{
		if ((int)stack_a->content > (int)stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

static void	ft_parser(t_push_swap *data)
{
	char	*line;
	int		check;

	if (data->opt_v)
		ft_opt_v(data);
	while ((check = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		if (ft_exec_cmd(data, line) == 0)
		{
			free(line);
			ft_quit(data);
		}
		free(line);
		if (data->opt_v)
			ft_opt_v(data);
		if (check == 0)
			break ;
	}
}

int			main(int ac, char **av)
{
	t_push_swap data;

	if (ac <= 1)
		return (0);
	ft_bzero(&data, sizeof(t_push_swap));
	ft_parse_args(ac, av, &data);
	ft_cpy_args(ac, av, &data);
	ft_parser(&data);
	if (ft_is_sorted(&data))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_lstclear(&data.stack_a, ft_do_nothing);
	ft_lstclear(&data.stack_b, ft_do_nothing);
	return (0);
}
