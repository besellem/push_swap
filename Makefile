# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <besellem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/12 16:32:37 by besellem          #+#    #+#              #
#    Updated: 2021/03/18 15:57:57 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP		=	push_swap
CHECKER			=	checker


## Sources
SRCS_FOLDER		:=	srcs

COMMON_SRCS		=	$(SRCS_FOLDER)/case3.c \
					$(SRCS_FOLDER)/common_parsing.c \
					$(SRCS_FOLDER)/common_options.c \
					$(SRCS_FOLDER)/lst_utils.c \
					$(SRCS_FOLDER)/operations_s.c \
					$(SRCS_FOLDER)/operations_p.c \
					$(SRCS_FOLDER)/operations_r.c \
					$(SRCS_FOLDER)/operations_rr.c \
					$(SRCS_FOLDER)/utils.c

PUSH_SWAP_SRCS	=	$(SRCS_FOLDER)/push_swap.c

CHECKER_SRCS	=	$(SRCS_FOLDER)/checker.c


## Objects
COMMON_OBJS		=	$(COMMON_SRCS:.c=.o)
PUSH_SWAP_OBJS	=	$(PUSH_SWAP_SRCS:.c=.o)
CHECKER_OBJS	=	$(CHECKER_SRCS:.c=.o)

## Include
INCS			=	-I incs -Ilibft/incs
LIBFT			=	-Llibft -lft

## Commands
CC				=	clang
CFLAGS			=	-Wall -Wextra -Werror# -g3 -fsanitize=address
RM				=	rm -f


.c.o:
				$(MUTE) $(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCS)


$(PUSH_SWAP):	$(COMMON_OBJS) $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)
				$(MUTE) $(MAKE) -C libft

				# Push Swap program
				$(CC) $(CFLAGS) $(COMMON_OBJS) $(PUSH_SWAP_OBJS) $(INCS) $(LIBFT) -o $(PUSH_SWAP)

				# Checker program
				$(CC) $(CFLAGS) $(COMMON_OBJS) $(CHECKER_OBJS) $(INCS) $(LIBFT) -o $(CHECKER)


all:			$(PUSH_SWAP)


clean:
				$(MUTE) $(MAKE) -C libft clean
				$(MUTE) $(RM) $(COMMON_OBJS)
				$(MUTE) $(RM) $(PUSH_SWAP_OBJS)
				$(MUTE) $(RM) $(CHECKER_OBJS)


fclean:			clean
				$(MUTE) $(MAKE) -C libft fclean
				$(MUTE) $(RM) $(PUSH_SWAP)
				$(MUTE) $(RM) $(CHECKER)


re:				fclean all


.PHONY:			$(NAME) all clean fclean re
