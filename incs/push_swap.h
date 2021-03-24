/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:33:47 by besellem          #+#    #+#             */
/*   Updated: 2021/03/24 10:43:57 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

# ifndef PROG_NAME
#  define PROG_NAME "push_swap"
# endif

int		*ft_sort_lst_in_tab(t_push_swap *data);

void	sort3nbrs(t_push_swap *data);
void	sort5nbrs(t_push_swap *data);
void	sort_algo(t_push_swap *data, int div);

#endif
