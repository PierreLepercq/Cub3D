# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/08 16:18:19 by plepercq          #+#    #+#              #
#    Updated: 2026/10/20 11:26:49 by plepercq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Set of ANSI/VT100 color codes
_END	= \x1b[0m
_BOLD	= \x1b[1m
_UNDER	= \x1b[4m
_REV	= \x1b[7m
_GREY	= \x1b[30m
_RED	= \x1b[31m
_GREEN	= \x1b[32m
_YELLOW	= \x1b[33m
_BLUE	= \x1b[34m
_PURPLE	= \x1b[35m
_CYAN	= \x1b[36m
_WHITE	= \x1b[37m

#	Program variables
NAME 		= cub3D
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror 

DIR_SRC		= src
DIR_OBJ		= obj
DIR_INC		= include

DIR_UTILS	= utils
UTILS		= ft_strlen ft_putstr_fd ft_bzero ft_memset ft_error

FILES		= 	main \
				$(addprefix $(DIR_UTILS)/, $(UTILS))

SRCS		= $(addprefix $(DIR_SRC)/, $(addsuffix .c, $(FILES)))
OBJS		= $(addprefix $(DIR_OBJ)/, $(addsuffix .o, $(FILES)))
INCS 		= -I $(DIR_INC) -I $(MLX_DIR)
LINKS		= $(MLX_FLAGS)

MLX_DIR     = minilibx-linux
MLX_URL     = https://github.com/42Paris/minilibx-linux
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lX11 -lXext

CMD_TEST	= ./$(NAME)
LOG_FILE	= logs

#	Rules
all: $(MLX_DIR) $(NAME)
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(LINKS)
	@echo -e "- ${_CYAN}link ${_WHITE}: ${_GREEN}OK${_END}\n"
	@echo -e "> ${_GREEN}Program name ${_WHITE}: ${_BOLD}$(NAME)${_END}\n"

clean:
	@$(RM) -vf $(OBJS)
	@echo -e "- ${_GREEN}Clean${_END}\n"

fclean:
	@$(RM) -vf $(NAME) $(LOG_FILE)
	@$(RM) -vf $(OBJS)
	@$(RM) -vdf $(addprefix $(DIR_OBJ)/, $(DIR_UTILS))
	@$(RM) -vdf $(DIR_OBJ)
	# @$(RM) -vrf $(MLX_DIR)
	@echo -e "- ${_GREEN}Full clean${_END}\n"

re: fclean all

good: re clean

test: fclean $(NAME)
	$(CC) $(CFLAGS) -g $(INCS) -o $(NAME) $(OBJS) $(LINKS)
	@echo -e "- ${_CYAN}link ${_WHITE}: ${_GREEN}OK${_END}\n"
	@echo -e "> ${_GREEN}Program name ${_WHITE}: ${_BOLD}$(NAME)${_END}\n"
	@echo -e "- ${_BOLD}${_PURPLE}Test ${_END}: $(CMD_TEST)"
	@$(RM) -f vgcore.*
	# @valgrind -q $(CMD_TEST) 2>&1 | tee $(LOG_FILE)
	$(CMD_TEST)

$(NAME): $(OBJS)
	@echo -e "- ${_CYAN}compilation and assembly ${_WHITE}: ${_GREEN}OK${_END}\n"

$(MLX_DIR):
	git clone $(MLX_URL) $(MLX_DIR)
	make -C $(MLX_DIR)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@mkdir -vp $(dir $@)
	$(CC) $(CFLAGS) $(INCS) -c $^ -o $@

.PHONY: all clean fclean re good
