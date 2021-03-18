# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check_range.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <besellem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 19:05:14 by besellem          #+#    #+#              #
#    Updated: 2021/03/18 15:27:37 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from generate import ft_gen_numbers
import os
import sys
import subprocess

if __name__ == "__main__":

	if len(sys.argv) == 3:
		
		if not os.path.isfile("./push_swap"):
			print("\033[1;31mError:\033[0m push_swap does not exist (create executable first)")
			exit(1)

		operations_lst = []
		stats = {
			"iterations_nb": 50,
			"min_op":		 -1,
			"max_op":		 0
		}
		for i in range(1, stats["iterations_nb"] + 1):
			
			# Generate a list of numbers based on the arguments
			numbers_generated_lst = ft_gen_numbers(int(sys.argv[1]), int(sys.argv[2]))
			numbers_generated_str = ' '.join(map(str, numbers_generated_lst))
			
			# Get push_swap's number of operations for the current list of numbers
			push_swap_exec = subprocess.Popen(
				[f'./push_swap {numbers_generated_str} | wc -l | tr -d " "'],
				shell=True,
				stdout=subprocess.PIPE,
				stderr=subprocess.STDOUT
			)
			push_swap_stdout, push_swap_stderr = push_swap_exec.communicate()
			push_swap_operations_nb = int(push_swap_stdout.decode())

			os.system(f"./push_swap {numbers_generated_str} | ./checker {numbers_generated_str}")

			# Append the list with the last result
			operations_lst.append(push_swap_operations_nb)

			# Print current state
			print(f'\033[1;36m# {i:2}\033[0m => {push_swap_operations_nb}')
			
			# Replace stats if necessary
			if stats["max_op"] < max(operations_lst):
				stats["max_op"] = max(operations_lst)
			if stats["min_op"] == -1 or stats["min_op"] > min(operations_lst):
				stats["min_op"] = min(operations_lst)

		# Print stats
		print("\n######################################")
		print(f'push_swap has been executed \033[1;32m{stats["iterations_nb"]}\033[0m times:\n')
		print(f'The minimum was:       \033[1;32m{stats["min_op"]}\033[0m')
		print(f'The maximum was:       \033[1;32m{stats["max_op"]}\033[0m')
		print(f'Diff btwn min and max: \033[1;32m{stats["max_op"] - stats["min_op"]}\033[0m')
		print(f'Average:               \033[1;32m{sum(operations_lst) / len(operations_lst)}\033[0m operations')
	else:
		print("\033[1;31mError:\033[0m args")
