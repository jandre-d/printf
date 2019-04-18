# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jandre-d <jandre-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/18 16:10:41 by jandre-d       #+#    #+#                 #
#    Updated: 2019/04/18 16:24:16 by jandre-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
FILES = ft_printf read_instruction c d f i o p s u x x_upper
 
$(NAME):
	gcc -c $(FILES:=.c) -Ilibft -Ilibpf -g
	ar rc $(NAME) $(FILES:=.o)
	ranlib $(NAME)

clean:
	rm -f $(FILES:=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

so:
	gcc -shared -o ft_printf.so -I. -Wall -Wextra -Werror -fPIC $(CFILES)
