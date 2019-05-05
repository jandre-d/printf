# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jandre-d <jandre-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/18 17:19:55 by jandre-d       #+#    #+#                 #
#    Updated: 2019/05/05 18:23:10 by jandre-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRC				= pf_append pf_prepend ft_printf pf_read_instruction pf_padding
SRC_CONVERTIONS	= pf_c pf_di pf_f pf_ouxx pf_p pf_percent pf_s pf_r pf_b pf_j
SRC_UTIL		= pf_10_power_n pf_intlen pf_itoa_base pf_ldtoa pf_memcpy \
			pf_memmove pf_uintlen pf_uitoa_base pf_wchar pf_wstr \
			pf_memset pf_wchar_byte_count

ALL_O_FILES 	= $(SRC_CONVERTIONS:=.o) $(SRC:=.o) $(SRC_UTIL:=.o)
ALL_C_FILES 	= \
	$(addprefix src/pf_conversions/, $(SRC_CONVERTIONS:=.c)) \
	$(addprefix src/pf_util/, $(SRC_UTIL:=.c))	\
	$(addprefix src/, $(SRC:=.c))

LIBFT_DIR = libft/
INC_DIR = includes/

all: $(NAME)

$(NAME):
	cd $(LIBFT_DIR) && make
	cp $(LIBFT_DIR)/libft.a $(NAME)
	gcc -Wall -Werror -Wextra -c $(ALL_C_FILES) -I $(INC_DIR) 
	ar -r $(NAME) $(ALL_O_FILES)
	ranlib $(NAME)

clean:
	cd libft && make clean
	rm -f $(ALL_O_FILES)

fclean: clean
	cd libft && make fclean
	rm -f $(NAME)

re: fclean all
