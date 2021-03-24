/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:32:54 by besellem          #+#    #+#             */
/*   Updated: 2021/03/24 09:18:08 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_parser(t_push_swap *data)
{
	char	*line;
	int		check;

	while ((check = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		if (ft_exec_cmd(data, line, PROG_NAME) == 0)
		{
			free(line);
			ft_quit_error(data);
		}
		free(line);
		if (check == 0)
			break ;
	}
}

int			main(int ac, char **av)
{
	t_push_swap data;

	if (ac < 2)
		return (0);
	ft_bzero(&data, sizeof(t_push_swap));
	ft_parse_args(ac, av, &data);
	ft_cpy_args(ac, av, &data);
	if (data.opt_v)
		ft_opt_v(&data);
	ft_parser(&data);
	if (ft_is_sorted(&data))
		ft_putendl(B_GREEN"OK"CLR_COLOR);
	else
		ft_putendl(B_RED"KO"CLR_COLOR);
	ft_lstclear(&data.stack_a, NULL);
	ft_lstclear(&data.stack_b, NULL);
	return (0);
}
