# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    generate.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <besellem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 18:26:28 by besellem          #+#    #+#              #
#    Updated: 2021/03/16 19:30:11 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import random

def	ft_gen_numbers(min_nb, max_nb):
	if min_nb > max_nb:
		print("Error: args not in order")
		return None
	lst = []
	count = 0
	while count != (max_nb - min_nb + 1):
		tmp = random.randint(min_nb, max_nb)
		if tmp in lst:
			continue
		lst.append(tmp)
		count += 1
	return lst


if __name__ == "__main__":
	if len(sys.argv) == 3:
		print(*ft_gen_numbers(int(sys.argv[1]), int(sys.argv[2])))
	else:
		print("Error: args")
