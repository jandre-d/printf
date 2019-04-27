# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jandre-d <jandre-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/18 17:19:55 by jandre-d       #+#    #+#                 #
#    Updated: 2019/04/27 20:28:03 by jandre-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRC				= append prepend ft_printf read_instruction padding
SRC_CONVERTIONS	= c di f ouxX p percent s r b j
SRC_UTIL		= pf_10_power_n pf_intlen pf_itoa_base pf_ldtoa pf_memcpy \
			pf_memmove pf_uintlen pf_uitoa_base pf_wchar pf_wstr \
			pf_memset pf_wchar_byte_count

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
