
all:
	gcc ft_printf.c read_instruction.c append.c libft/libft.a libpf/libpf.a -g
	./a.out