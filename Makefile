# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 15:16:12 by pveiga-c          #+#    #+#              #
#    Updated: 2023/09/07 16:04:03 by pveiga-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PROJECT 	   = So Long

NAME_PROJECT_BONUS = So Long Bonus

NAME			   = so_long

NAME_BONUS		   = so_long_bonus

SRCS			   = $(wildcard srcs/*.c)

SRCS_BONUS		   = $(wildcard bonus/srcs/*.c)

OBJS			   = $(SRCS:.c=.o)

OBJS_BONUS 		   = $(SRCS_BONUS:.c=.o)

CC 				   = cc 

CFLAGS 			   = -g -Wall -Wextra -Werror  -Imlx_linux  # -fsanitize=address

MLX_L			   = -L mlx_linux -lmlx -lXext -lX11

LIBFT_PATH 		   = libft

LIBFT_LIB	       = $(LIBFT_PATH)/libft.a

RM 				   = rm -f

.c.o:
			@$(CC) -c $< -o $@

all:		$(LIBFT_LIB) $(NAME)

$(NAME):	$(OBJS)
			@make -C mlx_linux
#			clear
			@make -C $(LIBFT_PATH)
			$(CC) $(CFLAGS) $(OBJS) $(MLX_L) $(LIBFT_LIB) -o $(NAME) 
#			clear
			@echo "$(BLUE)Compilation $(NAME_PROJECT) $(GREEN)  [OK]$(RESET)"
			@echo "$(BLUE)Successfully built $(GREEN)   [OK]$(RESET)"

bonus:	$(LIBFT_LIB) $(NAME_BONUS)

$(NAME_BONUS):	$(OBJS_BONUS)
			@make -C mlx_linux
#			clear
			@make -C $(LIBFT_PATH)
			$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLX_L) $(LIBFT_LIB) -o $(NAME_BONUS)	
#			clear
			@echo "$(BLUE)Compilation $(NAME_PROJECT_BONUS) $(GREEN)  [OK]$(RESET)"
			@echo "$(BLUE)Successfully built $(GREEN)   [OK]$(RESET)"
			
clean:		
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	@make clean -C $(LIBFT_PATH)
	@make clean -C mlx_linux
	clear
	@echo "$(GREEN) $(NAME_PROJECT) $(RED)Objects Removed! $(RESET)"

fclean: 	clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
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
