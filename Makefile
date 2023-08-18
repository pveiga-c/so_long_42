# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 15:16:12 by pveiga-c          #+#    #+#              #
#    Updated: 2023/08/18 16:16:02 by pveiga-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PROJECT 	= So Long

NAME			= so_long

SRCS			= $(wildcard srcs/*.c)

OBJS			= $(SRCS:.c=.o)

CC 				= cc 

CFLAGS 			= -Wall -Wextra -Werror  -Imlx_linux -g # -fsanitize=address

MLX_L			= -L mlx_linux -lmlx -lXext -lX11

LIBFT_PATH 		= ./libft

LIBFT_LIB 		= $(LIBFT_PATH)/libft.a

RM 				= rm -f


all:		$(LIBFT_LIB) $(NAME)

$(NAME):	
			@make -C mlx_linux
			@make -C $(LIBFT_PATH)
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(MLX_L) $(LIBFT_LIB)
			clear
			@echo "$(BLUE)Compilation $(NAME_PROJECT) $(GREEN)  [OK]$(RESET)"
			@echo "$(BLUE)Successfully built $(GREEN)   [OK]$(RESET)"
	
clean:		
	$(RM) $(OBJS)
	@make clean -C $(LIBFT_PATH)
	@make clean -C mlx_linux
	clear
	@echo "$(GREEN) $(NAME_PROJECT) $(RED)Objects Removed! $(RESET)"

fclean: 	clean
	$(RM) $(NAME)
	clear
	@echo "$(CYAN) [$(NAME_PROJECT)] $(RED)Objects Removed! $(RESET)"
	@echo "$(CYAN) [$(NAME_PROJECT)] $(RED)"Removed!" $(RESET)"

re: 		fclean all
			
.PHONY: all clean fclean re

CLR_RMV		= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN 		= \033[1;36m
RESET		= \033[0m