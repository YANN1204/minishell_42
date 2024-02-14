# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 09:09:09 by yrio              #+#    #+#              #
#    Updated: 2024/02/14 08:52:20 by yrio             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror -g3
ARCHIVE = libft/libft.a
BUILTINS = cd.c env.c unset.c
MAIN = main.c
TOOLS = utils_minishell.c lst_utils.c
SRC = $(addprefix srcs/builtins/, $(BUILTINS)) \
		$(addprefix srcs/main/, $(MAIN)) \
		$(addprefix srcs/tools/, $(TOOLS))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) -o $(NAME) $(OBJ) $(ARCHIVE) -lm	

%.o: %.c
	make bonus -C libft
	cc $(FLAGS) -g -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus