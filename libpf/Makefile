# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jandre-d <jandre-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/09 10:02:55 by jandre-d       #+#    #+#                 #
#    Updated: 2019/04/13 21:40:53 by jandre-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libpf.a
FILES = pf_intlen pf_itoa_base pf_ldtoa pf_10_power_n pf_uintlen pf_uitoa_base
 
$(NAME):
	gcc -c -Wall -Wextra -Werror $(FILES:=.c) -I../libft -g
	ar rc $(NAME) $(FILES:=.o)
	ranlib $(NAME)

clean:
	rm -f $(FILES:=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

so:
	gcc -shared -o libpf.so -I. -Wall -Wextra -Werror -fPIC $(CFILES)
