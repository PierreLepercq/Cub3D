# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 19:28:59 by llepesqu          #+#    #+#              #
#    Updated: 2025/12/20 07:00:26 by llepesqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror -I.
SRC_FILES = ft_calloc.c ft_case.c ft_isany.c ft_itoa.c ft_memany.c ft_putchar_fd.c ft_split.c ft_str1.c ft_str2.c ft_striteri.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_atoi.c
SRC = $(addprefix srcs/, $(SRC_FILES))
BONUS_FILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c#a remplir#
BONUS = $(addprefix srcs/bonus/, $(BONUS_FILES))
OBJ = $(SRC:srcs/%.c=obj/%.o)
BONUS_OBJ = $(BONUS:srcs/bonus/%.c=obj/%.o)
HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

obj/%.o: srcs/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: srcs/bonus/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@


bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

clean:
	rm -f obj/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re