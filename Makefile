
all:
	gcc conversions/*.c ft_printf.c read_instruction.c libft/libft.a libpf/libpf.a -g 
	./a.out