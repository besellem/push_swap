/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:32:54 by besellem          #+#    #+#             */
/*   Updated: 2021/03/12 17:27:53 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// void	(const t_operations ops[])
// {
	
// }

static void	check(t_data *data)
{
	const t_operations ops[] = {
		{"sa", ft_op_sa}, {"sb", ft_op_sb}, {"ss", ft_op_ss}, {"pa", ft_op_pa},
		{"pb", ft_op_pb}, {"ra", ft_op_ra}, {"rb", ft_op_rb}, {"rr", ft_op_rr},
		{"rra", ft_op_rra}, {"rrb", ft_op_rrb}, {"rrr", ft_op_rrr}
	};

	printf("name: [%s]\n", ops[0].func_name);
	ops[0].f();
	(void)data;
}

int			main(void)
{
	t_data data;

	(void)data;
	check(&data);
	return (0);
}
