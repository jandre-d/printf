# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jandre-d <jandre-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/18 17:19:55 by jandre-d       #+#    #+#                 #
#    Updated: 2019/04/18 18:11:05 by jandre-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRC_CONVERTIONS	= c d f i o p percent s u x_upper x
SRC				= append ft_printf read_instruction

ALL_O_FILES 	= $(SRC_CONVERTIONS:=.o) $(SRC:=.o)
ALL_C_FILES 	= $(addprefix src/pf_convertions/, $(SRC_CONVERTIONS:=.c)) \
	$(addprefix src/, $(SRC:=.c))

all: $(NAME)

re: clean all

$(NAME):
	cd libft && make
	gcc -c $(ALL_C_FILES) -Ift/
	ar rc $(NAME) $(ALL_O_FILES)
	ranlib $(NAME)

clean:
	cd libft && make clean
	rm -f $(ALL_O_FILES)

fclean: clean
	cd libft && make fclean
	rm -f $(NAME)

