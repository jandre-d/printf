# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: twoerdem <twoerdem@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/07 15:36:54 by twoerdem       #+#    #+#                 #
#    Updated: 2019/04/01 13:02:01 by twoerdem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = 	printf_test
SRC =	main.c\
		ft_printf.c
OBJ =	main.o\
		ft_printf.c
LIBFT = -L./libft -lft
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@gcc -c $(FLAGS) $(SRC)
	@gcc -o $(NAME) $(FLAGS) $(SRC) $(LIBFT)

clean:
	@make -C libft/ fclean
	@rm -f *.o

fclean: clean
	@rm -f ./$(NAME)

re: fclean all
