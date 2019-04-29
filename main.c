/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 15:21:30 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/29 17:13:17 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "limits.h"
#include "stdlib.h"
#include "string.h"

#define assert_printf ft_printf

int mainxx()
{

	while (1)
	{
		;
	}
	return (0);
}

int main()
{

	int i;
	int l;
	char c;
	char *str;
	char pointer_valueLargerThanMinWidth_zeroFlag = 44;
	while (1)
	{
		assert_printf("This is a simple test.");
		assert_printf("This is a simple test.\nSecond sentence.\n");
		assert_printf("");
		assert_printf("\n");
		assert_printf("%s", "abc");
		assert_printf("111%s333", "222");
		assert_printf("%s333", "222");
		assert_printf("111%s", "222");
		assert_printf("{%s}", 0);
		assert_printf("{%s}", "");
		assert_printf("111%s333%s555", "222", "444");
		assert_printf("111%s333%s555%saaa%sccc", "222", "444", "666", "bbb");
		assert_printf("%s%s%s%s%s", "1", "2", "3", "4", "5");
		assert_printf("%d", 42);
		assert_printf("%d", -42);
		assert_printf("before %d after", 42);
		assert_printf("%d%d%d%d%d", 1, -2, 3, -4, 5);
		assert_printf("a%db%dc%dd", 1, -2, 3);
		assert_printf("%d", INT_MAX);
		assert_printf("%d", INT_MIN);
		assert_printf("%p", &i);
		assert_printf("%p", &l);
		assert_printf("%p", &str);
		assert_printf("%p", &strlen);
		assert_printf("%p", 0);
		assert_printf("%%");
		assert_printf("aa%%bb");
		assert_printf("%%%%%%%%%%");
		assert_printf(".%%.%%.%%.%%.%%.%%.%%.%%.");
		assert_printf("%");
		assert_printf("% Zoooo");
		assert_printf("{%}");
		assert_printf("{% %}");
		assert_printf("s: %s, p: %p, d:%d", "a string", &main, 42);
		assert_printf("%s%p%d%d%p%s%p%p%s","a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
		assert_printf("%ls", L"米");
		assert_printf("%ls", L"我是一只猫。");
		assert_printf("%ls%ls%ls%ls%ls%ls%ls%ls%ls%ls%ls%ls%ls%ls%ls%ls%ls%ls%ls%ls%ls%ls%ls%ls%ls",L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
		assert_printf("a%lsb%sc%ls", L"我", "42", L"猫");
		assert_printf("{%ls}", NULL);
		assert_printf("%d", 0L);
		assert_printf("%d", 1L);
		assert_printf("%d", -1L);
		assert_printf("%d", 42L);
		assert_printf("%d", LONG_MAX);
		assert_printf("%d", LONG_MIN);
		assert_printf("Coucou les %d!", 42);
		assert_printf("%i", 42);
		assert_printf("%i", -42);
		assert_printf("before %i after", 42);
		assert_printf("%i%i%i%i%i", 1, -2, 3, -4, 5);
		assert_printf("a%ib%ic%id", 1, -2, 3);
		assert_printf("%o", 42);
		assert_printf("before %o after", 42);
		assert_printf("%o%o%o%o%o", 1, 100, 999, 42, 999988888);
		assert_printf("a%ob%oc%od", 0, 55555, 100000);
		assert_printf("%o", 42);
		assert_printf("%o", LONG_MAX);
		assert_printf("%u", 42);
		assert_printf("before %u after", 42);
		assert_printf("%u%u%u%u%u", 1, 100, 999, 42, 999988888);
		assert_printf("a%ub%uc%ud", 0, 55555, 100000);
		assert_printf("%u", UINT_MAX);
		assert_printf("%u", 42);
		assert_printf("%u", ULONG_MAX / 2);
		assert_printf("%u", ULONG_MAX);
		assert_printf("%x", 42);
		assert_printf("before %x after", 42);
		assert_printf("%x%x%x%x%x", 1, 100, 999, 42, 999988888);
		assert_printf("a%xb%xc%xd", 0, 55555, 100000);
		assert_printf("%x, %x", 0, UINT_MAX);
		assert_printf("%X", 42);
		assert_printf("before %X after", 42);
		assert_printf("%X%X%X%X%X", 1, 100, 999, 42, 999988888);
		assert_printf("a%Xb%Xc%Xd", 0, 55555, 100000);
		assert_printf("%X, %X", 0, UINT_MAX);
		assert_printf("%c", 'c');
		assert_printf("%c%c", '4', '2');
		assert_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
		assert_printf("%c", 0);

		assert_printf("%lc", 'c');
		assert_printf("%lc%lc", '4', '2');
		assert_printf("%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc \
%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc\
%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc",
' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
		assert_printf("%lc", L'猫');
		assert_printf("%lc", L'δ');
		assert_printf("%lc", L'요');
		assert_printf("%lc", L'莨');
		assert_printf("%lc", L'ي');
		assert_printf("%lc", 0);

		assert_printf("%s %lc %d %p %x %% %ls", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
		assert_printf("%s%d%p%%%ls%d%i%o%o%u%u%x%X%c%lc","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
		assert_printf("%ld%ld", 0, 42);
		assert_printf("%ld", (long)INT_MAX + 1);
		assert_printf("%ld", (long)INT_MIN - 1);
		assert_printf("%ld", LONG_MAX);
		assert_printf("%ld", LONG_MIN);
		assert_printf("%li%li", 0, 42);
		assert_printf("%li", (long)INT_MAX + 1);
		assert_printf("%li", (long)INT_MIN - 1);
		assert_printf("%li", LONG_MAX);
		assert_printf("%li", LONG_MIN);
		assert_printf("%lu, %lu", 0, ULONG_MAX);
		assert_printf("%lo, %lo", 0, ULONG_MAX);
		assert_printf("%lx, %lx", 0, ULONG_MAX);
		assert_printf("%lX, %lX", 0, ULONG_MAX);
		assert_printf("%lc, %lc", L'暖', L'ح');
		assert_printf("%ls, %ls", L"暖炉", L"لحم خنزير");
		assert_printf("%lo, %lo", 0, USHRT_MAX);
		assert_printf("%lu, %lu", 0, USHRT_MAX);
		assert_printf("%ld, %ld", 0, USHRT_MAX);
		assert_printf("%lld%lld", 0, 42);
		assert_printf("%lld", LLONG_MAX);
		assert_printf("%lld", LLONG_MIN);
		assert_printf("%lli%lli", 0, 42);
		assert_printf("%lli", LLONG_MAX);
		assert_printf("%lli", LLONG_MIN);
		assert_printf("%llu, %llu", 0, ULLONG_MAX);
		assert_printf("%llo, %llo", 0, ULLONG_MAX);
		assert_printf("%llx, %llx", 0, ULLONG_MAX);
		assert_printf("%llX, %llX", 0, ULLONG_MAX);
		assert_printf("%llo, %llo", 0, USHRT_MAX);
		assert_printf("%llu, %llu", 0, USHRT_MAX);
		assert_printf("%lld, %lld", 0, USHRT_MAX);
		assert_printf("%hd%hd", (short int)0, (short int)42);
		assert_printf("%hd", SHRT_MAX);
		assert_printf("%hd", SHRT_MIN);
		assert_printf("%hi%hi", 0, 42);
		assert_printf("%hi", SHRT_MAX);
		assert_printf("%hi", SHRT_MIN);
		assert_printf("%hu, %hu", 0, USHRT_MAX);
		assert_printf("%ho, %ho", 0, USHRT_MAX);
		assert_printf("%hx, %hx", 0, USHRT_MAX);
		assert_printf("%hX, %hX", 0, USHRT_MAX);
		assert_printf("%ho, %ho", 0, USHRT_MAX);
		assert_printf("%hu, %hu", 0, USHRT_MAX);
		assert_printf("%hd, %hd", 0, USHRT_MAX);
		assert_printf("%hhd%hhd", 1, 42);
		assert_printf("%hhd", CHAR_MAX);
		assert_printf("%hhd", CHAR_MAX + 42);
		assert_printf("%hhd", CHAR_MIN);
		assert_printf("%hhd", CHAR_MIN - 42);
		assert_printf("%hhi%hhi", 0, 42);
		assert_printf("%hhd", CHAR_MAX);
		assert_printf("%hhd", CHAR_MAX + 42);
		assert_printf("%hhi", CHAR_MIN);
		assert_printf("%hhi", CHAR_MIN - 42);
		assert_printf("%hhu, %hhu", 0, UCHAR_MAX);
		assert_printf("%hho, %hho", 0, UCHAR_MAX);
		assert_printf("%hhx, %hhx", 0, UCHAR_MAX);
		assert_printf("%hhX, %hhX", 0, UCHAR_MAX);
		assert_printf("%hhu, %hhu", 0, UCHAR_MAX + 42);
		assert_printf("%hho, %hho", 0, UCHAR_MAX + 42);
		assert_printf("%hhx, %hhx", 0, UCHAR_MAX + 42);
		assert_printf("%hhX, %hhX", 0, UCHAR_MAX + 42);
		assert_printf("%hho, %hho", 0, USHRT_MAX);
		assert_printf("%hhu, %hhu", 0, USHRT_MAX);
		assert_printf("%hhd, %hhd", 0, USHRT_MAX);
		assert_printf("%hhlc, %hhlc", 0, L'米');
		assert_printf("%hhls, %hhls", 0, L"米米");
		assert_printf("%d%d", 0, 42);
		assert_printf("%d", LLONG_MAX);
		assert_printf("%d", LLONG_MIN);
		assert_printf("%i%i", 0, 42);
		assert_printf("%i", LLONG_MAX);
		assert_printf("%i", LLONG_MIN);
		assert_printf("%u, %u", 0, ULLONG_MAX);
		assert_printf("%o, %o", 0, ULLONG_MAX);
		assert_printf("%x, %x", 0, ULLONG_MAX);
		assert_printf("%X, %X", 0, ULLONG_MAX);
		assert_printf("%O, %O", 0, USHRT_MAX);
		assert_printf("%U, %U", 0, USHRT_MAX);
		assert_printf("%D, %D", 0, USHRT_MAX);
		assert_printf("%zd%zd", 0, 42);
		assert_printf("%zd", LLONG_MAX);
		assert_printf("%zi%zi", 0, 42);
		assert_printf("%zi", LLONG_MAX);
		assert_printf("%zu, %zu", 0, ULLONG_MAX);
		assert_printf("%zo, %zo", 0, ULLONG_MAX);
		assert_printf("%zx, %zx", 0, ULLONG_MAX);
		assert_printf("%zX, %zX", 0, ULLONG_MAX);
		assert_printf("%zO, %zO", 0, USHRT_MAX);
		assert_printf("%zU, %zU", 0, USHRT_MAX);
		assert_printf("%zD, %zD", 0, USHRT_MAX);
		assert_printf("%lp", 42);
		assert_printf("{%10d}", 42);
		assert_printf("{%4d}", 10000);
		assert_printf("{%30d}", 10000);
		assert_printf("{%10d}", -42);
		assert_printf("{%3c}", 0);
		assert_printf("{%5p}", 0);
		assert_printf("{%-15p}", 0);
		assert_printf("{%-13p}", &strlen);
		assert_printf("{%-12p}", &strlen);
		assert_printf("{hoi}");
		assert_printf("{%30ls}", L"我是一只猫。");
		assert_printf("{%-30ls}", L"我是一只猫。");
		assert_printf("{%-10d}", 42);
		assert_printf("{%-4d}", 10000);
		assert_printf("{%-30d}", 10000);
		assert_printf("{%010d}", 42);
		assert_printf("{%010d}", -42);
		assert_printf("{%04d}", 10000);
		assert_printf("{%030d}", 10000);
		assert_printf("{%030x}", 0xFFFF);
		assert_printf("{%030X}", 0xFFFF);
		assert_printf("{%03c}", 0);
		assert_printf("{%05s}", "abc");
		assert_printf("{%030ls}", L"我是一只猫。");
		assert_printf("{%05p}", 0);
		assert_printf("{%05p}", &pointer_valueLargerThanMinWidth_zeroFlag);
		assert_printf("{%-15d}", 123);
		assert_printf("%#o", 42);
		assert_printf("%#o", 0);
		assert_printf("%#o", INT_MAX);
		assert_printf("%#o", 1);
		assert_printf("%#x", 42);
		assert_printf("%#x", 0);
		assert_printf("%#x", INT_MAX);
		assert_printf("%#X", 42);
		assert_printf("%#X", 0);
		assert_printf("%#X", INT_MAX);
		assert_printf("%#c", 0);
		assert_printf("%+d", 42);
		assert_printf("%+d", -42);
		assert_printf("%+i", 42);
		assert_printf("%+i", -42);
		assert_printf("%+c", 0);
		assert_printf("%+lc", 0);
		assert_printf("%+o", 0);
		assert_printf("%+o", 42);
		assert_printf("%+o", 0);
		assert_printf("%+o", 42);
		assert_printf("[%+s]", 0);
		assert_printf("[%+s]", "(null)");
		assert_printf("%+o", 1);
		assert_printf("% d", 9999);
		assert_printf("% d", -9999);
		assert_printf("% i", 9999);
		assert_printf("% i", -9999);
		assert_printf("% u", 9999);
		assert_printf("{% c}", 0);
		assert_printf("{% c}", 'a');
		assert_printf("{% s}", NULL);
		assert_printf("{% s}", "(null)");
		assert_printf("{% s}", "");
		assert_printf("{% lc}", 0);
		assert_printf("{% lc}", L'a');
		assert_printf("{% ls}", NULL);
		assert_printf("{% ls}", L"(null)");
		assert_printf("{% ls}", L"");
		assert_printf("{% +d}", 42);
		assert_printf("{%+ d}", 42);
		assert_printf("{%+03d}", 0);
		assert_printf("{% 03d}", 0);
		assert_printf("{%0-3d}", 0);
		assert_printf("{%+03d}", 12);
		assert_printf("{%+03d}", 123456);
		assert_printf("{%03.2d}", 0);
		assert_printf("%#.o", 0);
		assert_printf("%.4d", 42);
		assert_printf("%.4d", 424242);
		assert_printf("%.4d", -424242);
		assert_printf("%15.4d", 42);
		assert_printf("%15.4d", 424242);
		assert_printf("%8.4d", 424242424);
		assert_printf("%15.4d", -42);
		assert_printf("%15.4d", -424242);
		assert_printf("%8.4d", -424242424);
		assert_printf("%4.15d", 42);
		assert_printf("%4.15d", 424242);
		assert_printf("%4.8d", 424242424);
		assert_printf("%4.15d", -42);
		assert_printf("%4.15d", -424242);
		assert_printf("%4.8d", -424242424);
		assert_printf("%.d, %.0d", 0, 0);
		assert_printf("%.10d", -42);
		assert_printf("%.4i", 42);
		assert_printf("%15.4i", 42);
		assert_printf("%4.15i", 42);
		assert_printf("%.i, %.0i", 0, 0);
		assert_printf("%.4u", 42);
		assert_printf("%.4u", 424242);
		assert_printf("%15.4u", 42);
		assert_printf("%15.4u", 424242);
		assert_printf("%8.4u", 424242424);
		assert_printf("%4.15u", 42);
		assert_printf("%4.15u", 424242);
		assert_printf("%4.8u", 424242424);
		assert_printf("%.u, %.0u", 0, 0);
		assert_printf("%.4o", 42);
		assert_printf("%.4o", 424242);
		assert_printf("%15.4o", 42);
		assert_printf("%15.4o", 424242);
		assert_printf("%8.4o", 424242424);
		assert_printf("%4.15o", 42);
		assert_printf("%4.15o", 424242);
		assert_printf("%4.8o", 424242424);
		assert_printf("%.o, %.0o", 0, 0);
		assert_printf("%.4o", 42);
		assert_printf("%15.4o", 42);
		assert_printf("%4.15o", 42);
		assert_printf("%.o, %.0o", 0, 0);
		assert_printf("%.4x", 42);
		assert_printf("%.4x", 424242);
		assert_printf("%15.4x", 42);
		assert_printf("%15.4x", 424242);
		assert_printf("%8.4x", 424242424);
		assert_printf("%4.15x", 42);
		assert_printf("%4.15x", 42424242);
		assert_printf("%4.8x", 424242424);
		assert_printf("%.x, %.0x", 0, 0);
		assert_printf("%.4X", 42);
		assert_printf("%.4X", 424242);
		assert_printf("%15.4X", 42);
		assert_printf("%15.4X", 424242);
		assert_printf("%8.4X", 424242424);
		assert_printf("%4.15X", 42);
		assert_printf("%4.15X", 424242);
		assert_printf("%4.8X", 424242424);
		assert_printf("%.X, %.0X", 0, 0);
		assert_printf("%.4s", "42");
		assert_printf("%.4s", "42 is the answer");
		assert_printf("%15.4s", "42");
		assert_printf("%15.4s", "I am 42");
		assert_printf("%15.4s", "42 is the answer");
		assert_printf("%4.15s", "42");
		assert_printf("%4.15s", "I am 42");
		assert_printf("%4.15s", "42 is the answer");
		assert_printf("%4.s", "42");
		assert_printf("%.4ls", L"我是一只猫。");
		assert_printf("%15.4ls", L"我是一只猫。");
		assert_printf("%4.1ls", L"我是一只猫。");
		assert_printf("%4.ls", L"我是一只猫。");
		assert_printf("%4.1ls", L"Jambon");
		assert_printf("%.c", 0);
		assert_printf("%.5c", 0);
		assert_printf("%.5c", 42);
		assert_printf("%.c", 0);
		assert_printf("%.5c", 0);
		assert_printf("%.5c", 42);
		assert_printf("%.0p, %.p", 0, 0);
		assert_printf("%.5p", 0);
		assert_printf("%9.2p", 1234);
		assert_printf("%9.2p", 1234567);
		assert_printf("%2.9p", 1234);
		assert_printf("%2.9p", 1234567);
		assert_printf("%.3%");
		assert_printf("%#.o, %#.0o", 0, 0);
		assert_printf("%#.x, %#.0x", 0, 0);
		assert_printf("%.p, %.0p", 0, 0);
		assert_printf("{%05.c}", 0);
		assert_printf("{%05.s}", 0);
		assert_printf("{%05.%}", 0);
		assert_printf("{%05.d}", 0);
		assert_printf("{%#.5x}", 1);
		assert_printf("%#.3o", 1);
		assert_printf("{%05.ls}", L"42 c est cool");
		assert_printf("%hhd - %hhd", SHRT_MAX - 42,  SHRT_MAX - 4200);
		assert_printf("%zi", LLONG_MIN);
		assert_printf("%zd", LLONG_MIN);
		assert_printf("% p|%+p", 42, 42);
		assert_printf("%u", -42);
		assert_printf("%u", UINT_MAX + 1);
		assert_printf("%u", ULONG_MAX + 1);
		assert_printf("%c", 200);
		assert_printf("% u|%+u", 42, 42);
		assert_printf("%hhu / %hhu", SHRT_MAX - 42,  SHRT_MAX - 4200);
		assert_printf("%o, %ho, %hho", -42, -42, -42);
		assert_printf("%o", LONG_MAX);
		assert_printf("%o", LONG_MIN);
		assert_printf("% o|%+o", 42, 42);
		assert_printf("%#.o", 42);
		assert_printf("% x|%+x", 42, 42);
		assert_printf("% X|%+X", 42, 42);
		assert_printf("%*d", 5, 42);
		assert_printf("{%*d}", -5, 42);
		assert_printf("{%*d}", 0, 42);
		assert_printf("{%*c}", 0, 0);
		assert_printf("{%*c}", -15, 0);
		assert_printf("{%.*d}", 5, 42);
		assert_printf("{%.*d}", -5, 42);
		assert_printf("{%.*d}", 0, 42);
		assert_printf("{%.*s}", 5, "42");
		assert_printf("{%.*s}", -5, "42");
		assert_printf("{%.*s}", 0, "42");
		assert_printf("{%*s}", 5, 0);
		assert_printf("{%3*p}", 10, 0);
		assert_printf("%*.*d", 0, 3, 0);
		assert_printf("{%3*d}", 0, 0);
		assert_printf("{%*3d}", 0, 0);
		assert_printf("{%*3d}", 5, 0);
		assert_printf("{%05.*d}", -15, 42);
		assert_printf("{%f}{%f}", 1.42, 1.42);
		assert_printf("{%f}{%f}", -1.42, -1.42);
		assert_printf("{%f}{%f}", 1444565444646.6465424242242, 1444565444646.6465424242242);
		assert_printf("{%f}{%f}", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654);
		break;
	}
	while (1)
	{
		 ;
	}	
}
