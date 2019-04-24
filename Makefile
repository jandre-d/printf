# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jandre-d <jandre-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/18 17:19:55 by jandre-d       #+#    #+#                 #
#    Updated: 2019/04/22 19:21:03 by jandre-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRC				= append ft_printf read_instruction
SRC_CONVERTIONS	= c c_upper d d_upper f i o o_upper p percent s s_upper u u_upper x x_upper
SRC_UTIL		= pf_10_power_n pf_intlen pf_itoa_base pf_ldtoa pf_memcpy \
			pf_memmove pf_uintlen pf_uitoa_base

ALL_O_FILES 	= $(SRC_CONVERTIONS:=.o) $(SRC:=.o) $(SRC_UTIL:=.o)
ALL_C_FILES 	= \
	$(addprefix src/pf_convertions/, $(SRC_CONVERTIONS:=.c)) \
	$(addprefix src/pf_util/, $(SRC_UTIL:=.c))	\
	$(addprefix src/, $(SRC:=.c))

INC_DIR = includes/

all: $(NAME)

re: fclean all

$(NAME):
	cd libft && make
	cp libft/libft.a $(NAME)
	gcc -c $(ALL_C_FILES) -I $(INC_DIR) -g
	ar -r $(NAME) $(ALL_O_FILES)
	ranlib $(NAME)

clean:
	cd libft && make clean
	rm -f $(ALL_O_FILES)

fclean: clean
	cd libft && make fclean
	rm -f $(NAME)

a:
	rm -f a.out
	gcc testmain.c libftprintf.a -g -I $(INC_DIR) -I libft/ 
	./a.out

x: 
	cd libft && make fclean
	rm -f $(NAME)
	cd libft && make
	cp libft/libft.a $(NAME)
	gcc -c $(ALL_C_FILES) -I $(INC_DIR)
	ar -r $(NAME) $(ALL_O_FILES)
	ranlib $(NAME)
	cd libft && make clean
	rm -f $(ALL_O_FILES)