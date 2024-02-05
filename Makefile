# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 09:09:09 by yrio              #+#    #+#              #
#    Updated: 2024/02/05 16:08:35 by yrio             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror -g3
ARCHIVE = libft/libft.a
SRC = main.c builtins_function.c utils_minishell.c

OBJ = $(SRC:.c=.o)
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ) $(ARCHIVE) -lm
#$(FLAGS)	

$(OBJ): $(SRC)
	make bonus -C libft
	cc -g -c $(SRC)
#$(FLAGS)

clean:
	make clean -C libft
	rm -f prog *.o

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus