# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jandre-d <jandre-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/18 17:19:55 by jandre-d       #+#    #+#                 #
#    Updated: 2019/04/18 21:43:34 by jandre-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRC_CONVERTIONS	= c d f i o p percent s u x_upper x
SRC_UTIL		= pf_10_power_n pf_intlen pf_itoa_base pf_ldtoa pf_memcpy pf_memmove pf_uintlen pf_uitoa_base.c
SRC				= append ft_printf read_instruction

ALL_O_FILES 	= $(SRC_CONVERTIONS:=.o) $(SRC:=.o) $(SRC_UTIL:=.o)
ALL_C_FILES 	= $(addprefix src/pf_convertions/, $(SRC_CONVERTIONS:=.c)) \
	$(addprefix src/, $(SRC:=.c))

all: $(NAME)

re: clean all


#	ar rc $(NAME) $(ALL_O_FILES)

$(NAME):
	cd libft && make
	cp libft/libft.a $(NAME)
	gcc -c $(ALL_C_FILES)
	ar -r $(NAME) $(ALL_O_FILES)
	ranlib $(NAME)

clean:
	cd libft && make clean
	rm -f $(ALL_O_FILES)

fclean: clean
	cd libft && make fclean
	rm -f $(NAME)
