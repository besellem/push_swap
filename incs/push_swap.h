/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:33:47 by besellem          #+#    #+#             */
/*   Updated: 2021/03/23 15:03:25 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

# ifndef PROG_NAME
#  define PROG_NAME "push_swap"
# endif

void	sort3nbrs(t_push_swap *data);
void	sort5nbrs(t_push_swap *data);

#endif
