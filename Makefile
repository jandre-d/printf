# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jandre-d <jandre-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/18 16:10:41 by jandre-d       #+#    #+#                 #
#    Updated: 2019/04/18 16:18:29 by jandre-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
FILES = ft_printf read_instruction
 
$(NAME):
	gcc -c $(FILES:=.c) -Ilibft -Ilibpf -g
	gcc -c conversions/*.c  -Ilibft -Ilibpf -g
	ar rc $(NAME) $(FILES:=.o)
	ranlib $(NAME)

clean:
	rm -f $(FILES:=.o)
	rm -f conversions/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

so:
	gcc -shared -o ft_printf.so -I. -Wall -Wextra -Werror -fPIC $(CFILES)
