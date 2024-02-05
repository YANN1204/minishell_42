# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 09:09:09 by yrio              #+#    #+#              #
#    Updated: 2024/02/05 07:59:24 by yrio             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror -g3
ARCHIVE = libft/libft.a
SRC = main.c

OBJ = $(SRC:.c=.o)
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) -o $(NAME) $(OBJ) $(ARCHIVE) -lm
	
$(OBJ): $(SRC)
	make bonus -C libft
	cc $(FLAGS) -g -c $(SRC)

clean:
	make clean -C libft
	rm -f prog *.o

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus