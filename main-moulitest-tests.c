/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main-moulitest-tests.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/06 19:22:58 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/06 20:35:28 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#define assert_printf printf

int main()
{
// // simple_string()
// 		assert_printf("This is a simple test.");
// // simple_string_with_newline()
// 		assert_printf("This is a simple test.\nSecond sentence.\n");
// // empty_string()
// 		assert_printf("");
// // simple_newline()
// 		assert_printf("\n");
// // simple_convertion1()
// 		assert_printf("%s", "abc");
// // simple_convertion2()
//		assert_printf("111%s333", "222");
// // simple_convertion3()
// 		assert_printf("%s333", "222");
// // simple_convertion4()
// 		assert_printf("111%s", "222");
// // null_string()
// 		assert_printf("{%s}", 0);
// // empty_string()
//		assert_printf("{%s}", "");
// // test_2_strings()
// 		assert_printf("111%s333%s555", "222", "444");
// // test_more_strings()
// 		assert_printf("111%s333%s555%saaa%sccc", "222", "444", "666", "bbb");
// // test_only_string_conv()
// 		assert_printf("%s%s%s%s%s","1", "2", "3", "4", "5");
// // test_digit()
// 		assert_printf("%d", 42);
// // test_digit_negative()
// 		assert_printf("%d", -42);
// // test_digit_with_strings()
// 		assert_printf("before %d after", 42);
// // test_many_digits()
// 		assert_printf("%d%d%d%d%d", 1, -2, 3, -4, 5);
// // test_many_digits_width_strings()
// 		assert_printf("a%db%dc%dd", 1, -2, 3);
// // test_int_max()
// 		assert_printf("%d", INT_MAX);
// // test_int_min()
// 		assert_printf("%d", INT_MIN);
// // test_int_pointer()
//		int i;
//		assert_printf("%p", &i);
// // test_unsigned_long_pointer()
// 		unsigned long l;
// 		assert_printf("%p", &l);
// // test_str_pointer()
// 		char *str;
// 		assert_printf("%p", &str);
// // test_function_pointer()
// 		assert_printf("%p", &strlen);
// // test_zero()
//		assert_printf("%p", 0);
// // test_percent_alone()
// 		assert_printf("%%");
// // test_percent_simple()
// 		assert_printf("aa%%bb");
// // test_many_percent()
// 		assert_printf("%%%%%%%%%%");
// // test_more_percent()
//		assert_printf(".%%.%%.%%.%%.%%.%%.%%.%%.");
// // test_modulo_without_valid_specifier()
//		assert_printf("%");
// // percentSpaceZoo()
// 		assert_printf("% Zoooo");
// // percentAlone()
// 		assert_printf("{%}");
// // multiplePercent()
// 		assert_printf("{% %}");
// // test_simple_mix()
// 		assert_printf("s: %s, p: %p, d:%d", "a string", &main, 42);
// // test_super_mix()
//		assert_printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
// // test_simple()
//		assert_printf("%S", L"米");
// // test_multiple_wchars()
// 		assert_printf("%S", L"我是一只猫。");
// // test_greek_alphabet_wchars()
//		assert_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
//	L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
// // test_mix()
// 		assert_printf("a%Sb%sc%S", L"我", "42", L"猫");
// // nullWideString()
// 		assert_printf("{%S}", NULL);
// // test_simple()
		// assert_printf("%D", 0L);
		// assert_printf("%D", 1L);
		// assert_printf("%D", -1L);
		// assert_printf("%D", 42L);
// // test_long_max()
// 		assert_printf("%D", LONG_MAX);
// // test_long_min()
// 		assert_printf("%D", LONG_MIN);
// // test_with_strings()
// 		assert_printf("Coucou les %D!", 42);
// // test_digit()
// 		assert_printf("%i", 42);
// // test_digit_negative()
// 		assert_printf("%i", -42);
// // test_digit_with_strings()
// 		assert_printf("before %i after", 42);
// // test_many_digits()
// 		assert_printf("%i%i%i%i%i", 1, -2, 3, -4, 5);
// // test_many_digits_width_strings()
// 		assert_printf("a%ib%ic%id", 1, -2, 3);
// // test_simple()
// 		assert_printf("%o", 42);
// // test_octal_with_strings()
// 		assert_printf("before %o after", 42);
// // test_many_octals()
// 		assert_printf("%o%o%o%o%o", 1, 100, 999, 42, 999988888);
// // test_many_octals_with_strings()
// 		assert_printf("a%ob%oc%od", 0, 55555, 100000);
// // test_simple()
// 		assert_printf("%O", 42);
// // test_long_octal_with_strings()
// 		assert_printf("before %O after", 42);
// // test_many_long_octals()
// 		assert_printf("%O%O%O%O%O", 1, 100, 999, 42, 999988888);
// // test_many_long_octals_with_strings()
// 		assert_printf("a%Ob%Oc%Od", 0, 55555, 100000);
// // test_octal_long_max()
// 		assert_printf("%O", LONG_MAX);
// // test_simple()
// 		assert_printf("%u", 42);
// // test_uint_with_strings()
// 		assert_printf("before %u after", 42);
// // test_many_uints()
// 		assert_printf("%u%u%u%u%u", 1, 100, 999, 42, 999988888);
// // test_many_uints_with_strings()
// 		assert_printf("a%ub%uc%ud", 0, 55555, 100000);
// // test_uints_max()
// 		assert_printf("%u", UINT_MAX);
// // test_simple()
// 		assert_printf("%U", 42);
// // test_ulong_max_half()
// 		assert_printf("%U", ULONG_MAX / 2);
// // test_ulong_max()
// 		assert_printf("%U", ULONG_MAX);
// // test_simple()
// 		assert_printf("%x", 42);
// // test_hex_with_strings()
// 		assert_printf("before %x after", 42);
// // test_many_hexs()
// 		assert_printf("%x%x%x%x%x", 1, 100, 999, 42, 999988888);
// // test_many_hexs_with_strings()  
// 		assert_printf("a%xb%xc%xd", 0, 55555, 100000);
// // test_uint_max()
// 		assert_printf("%x, %x", 0, UINT_MAX);
// // test_simple()
// 		assert_printf("%X", 42);
// // test_hex_with_strings()
// 		assert_printf("before %X after", 42);
// // test_many_hexs()
// 		assert_printf("%X%X%X%X%X", 1, 100, 999, 42, 999988888);
// // test_many_hexs_with_strings()
// 		assert_printf("a%Xb%Xc%Xd", 0, 55555, 100000);
// // test_uint_max()
// 		assert_printf("%X, %X", 0, UINT_MAX);
// // test_simple_char()
// 		assert_printf("%c", 'c');
// // test_two_chars()
// 		assert_printf("%c%c", '4', '2');
// // test_ascii_printable_chars()
// 		assert_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
// 		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
// %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
// ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
// '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
// '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
// 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
// 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
// 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
// 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
// // test_zero()
// 		assert_printf("%c", 0);
// // test_simple_char()
// 		assert_printf("%C", 'c');
// // test_two_chars()
// 		assert_printf("%C%C", '4', '2');
// // test_ascii_printable_chars()
// 		assert_printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C \
// 		%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C\
// %C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C",
// ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
// '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
// '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
// 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
// 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
// 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
// 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
// // test_chinese()
// 		assert_printf("%C", L'猫');
// // test_greek()
// 		assert_printf("%C", L'δ');
// // test_korean()
// 		assert_printf("%C", L'요');
// // test_japanese()
// 		assert_printf("%C", L'莨');
// // test_arabic()
// 		assert_printf("%C", L'ي');
// // test_nullChar()
// 		assert_printf("%C", 0);
// // test_simple()
// 		assert_printf("%s %C %d %p %x %% %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
// // test_hard()
// 		char c;
// 		assert_printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
// // test_ld_simple()
// 		assert_printf("%ld%ld", 0, 42);
// // test_ld_int_max_plus()
// 		assert_printf("%ld", (long)INT_MAX + 1);
// // test_ld_int_min_minus()
// 		assert_printf("%ld", (long)INT_MIN - 1);
// // test_ld_long_max()
// 		assert_printf("%ld", LONG_MAX);
// // test_ld_long_min()
// 		assert_printf("%ld", LONG_MIN);
// // test_li_simple()
// 		assert_printf("%li%li", 0, 42);
// // test_li_int_max_plus()
// 		assert_printf("%li", (long)INT_MAX + 1);
// // test_li_int_min_minus()
// 		assert_printf("%li", (long)INT_MIN - 1);
// // test_li_long_max()
// 		assert_printf("%li", LONG_MAX);
// // test_li_long_min()
// 		assert_printf("%li", LONG_MIN);
// // test_lu_long_unsigned_max()
// 		assert_printf("%lu, %lu", 0, ULONG_MAX);
// // test_lo_long_unsigned_max()
// 		assert_printf("%lo, %lo", 0, ULONG_MAX);
// // test_lx_long_unsigned_max()
// 		assert_printf("%lx, %lx", 0, ULONG_MAX);
// // test_lX_long_unsigned_max()
// 		assert_printf("%lX, %lX", 0, ULONG_MAX);
// // test_lc_wchar()
// 		assert_printf("%lc, %lc", L'暖', L'ح');
// // test_ls_wchar()
// 		assert_printf("%ls, %ls", L"暖炉", L"لحم خنزير");
// // test_err_lo_up_max()
// 		assert_printf("%lO, %lO", 0, USHRT_MAX);
// // test_err_lu_up_max()
// 		assert_printf("%lU, %lU", 0, USHRT_MAX);
// // test_err_ld_up_max()
// 		assert_printf("%lD, %lD", 0, USHRT_MAX);
// // test_lld_simple()
// 		assert_printf("%lld%lld", 0, 42);
// // test_lld_llong_max()
// 		assert_printf("%lld", LLONG_MAX);
// // test_lld_llong_min()
// 		assert_printf("%lld", LLONG_MIN);
// // test_lli_simple()
// 		assert_printf("%lli%lli", 0, 42);
// // test_lli_llong_max()
// 		assert_printf("%lli", LLONG_MAX);
// // test_lli_llong_min()
// 		assert_printf("%lli", LLONG_MIN);
// // test_llu_unsign_long_long_max()
// 		assert_printf("%llu, %llu", 0, ULLONG_MAX);
// // test_llo_unsign_long_long_max()
// 		assert_printf("%llo, %llo", 0, ULLONG_MAX);
// // test_llx_unsign_long_long_max()
// 		assert_printf("%llx, %llx", 0, ULLONG_MAX);
// // test_llX_unsign_long_long_max()
// 		assert_printf("%llX, %llX", 0, ULLONG_MAX);
// // test_err_llo_up_max()
// 		assert_printf("%llO, %llO", 0, USHRT_MAX);
// // test_err_llu_up_max()
// 		assert_printf("%llU, %llU", 0, USHRT_MAX);
// // test_err_lld_up_max()
// 		assert_printf("%llD, %llD", 0, USHRT_MAX);
// // test_hd_simple()
// 		assert_printf("%hd%hd", (short int)0, (short int)42);
// // test_hd_max()
// 		assert_printf("%hd", SHRT_MAX);
// // test_hd_min()
// 		assert_printf("%hd", SHRT_MIN);
// // test_hi_simple()
// 		assert_printf("%hi%hi", 0, 42);
// // test_hi_max()
// 		assert_printf("%hi", SHRT_MAX);
// // test_hi_min()
// 		assert_printf("%hi", SHRT_MIN);
// // test_hu_max()
// 		assert_printf("%hu, %hu", 0, USHRT_MAX);
// // test_ho_max()
// 		assert_printf("%ho, %ho", 0, USHRT_MAX);
// // test_hx_max()
// 		assert_printf("%hx, %hx", 0, USHRT_MAX);
// // test_hX_max()
// 		assert_printf("%hX, %hX", 0, USHRT_MAX);
// // test_err_ho_up_max()
// 		assert_printf("%hO, %hO", 0, USHRT_MAX);
// // test_err_hu_up_max()
// 		assert_printf("%hU, %hU", 0, USHRT_MAX);
// // test_err_hd_up_max()
// 		assert_printf("%hD, %hD", 0, USHRT_MAX);
// // test_hhd_simple()
// 		assert_printf("%hhd%hhd", 1, 42);
// // test_hhd_max()
// 		assert_printf("%hhd", CHAR_MAX);
// // test_hhd_max_plus()
// 		assert_printf("%hhd", CHAR_MAX + 42);
// // test_hhd_min()
// 		assert_printf("%hhd", CHAR_MIN);
// // test_hhd_min_minus()
// 		assert_printf("%hhd", CHAR_MIN - 42);
// // test_hhi_simple()
// 		assert_printf("%hhi%hhi", 0, 42);
// // test_hhi_max()
// 		assert_printf("%hhd", CHAR_MAX);
// // test_hhi_max_plus()
// 		assert_printf("%hhd", CHAR_MAX + 42);
// // test_hhi_min()
// 		assert_printf("%hhi", CHAR_MIN);
// // test_hhi_min_minus()
// 		assert_printf("%hhi", CHAR_MIN - 42);
// // test_hhu_max()
// 		assert_printf("%hhu, %hhu", 0, UCHAR_MAX);
// // test_hho_max()
// 		assert_printf("%hho, %hho", 0, UCHAR_MAX);
// // test_hhx_max()
// 		assert_printf("%hhx, %hhx", 0, UCHAR_MAX);
// // test_hhX_max()
// 		assert_printf("%hhX, %hhX", 0, UCHAR_MAX);
// // test_hhu_max_plus()
// 		assert_printf("%hhu, %hhu", 0, UCHAR_MAX + 42);
// // test_hho_max_plus()
// 		assert_printf("%hho, %hho", 0, UCHAR_MAX + 42);
// // test_hhx_max_plus()
// 		assert_printf("%hhx, %hhx", 0, UCHAR_MAX + 42);
// // test_hhX_max_plus()
// 		assert_printf("%hhX, %hhX", 0, UCHAR_MAX + 42);
// // test_err_hho_up_max()
// 		assert_printf("%hhO, %hhO", 0, USHRT_MAX);
// // test_err_hhu_up_max()
// 		assert_printf("%hhU, %hhU", 0, USHRT_MAX);
// // test_err_hhd_up_max()
// 		assert_printf("%hhD, %hhD", 0, USHRT_MAX);
// // test_err_hhc_up_max()
// 		assert_printf("%hhC, %hhC", 0, L'米');
// // test_err_hhs_up_max()
// 		assert_printf("%hhS, %hhS", 0, L"米米");
// // test_jd_simple()
// 		assert_printf("%jd%jd", 0, 42);
// // test_jd_llong_max()
// 		assert_printf("%jd", LLONG_MAX);
// // test_jd_llong_min()
// 		assert_printf("%jd", LLONG_MIN);
// // test_ji_simple()
// 		assert_printf("%ji%ji", 0, 42);
// // test_ji_llong_max()
// 		assert_printf("%ji", LLONG_MAX);
// // test_ji_llong_min()
// 		assert_printf("%ji", LLONG_MIN);
// // test_ju_unsign_long_long_max()
// 		assert_printf("%ju, %ju", 0, ULLONG_MAX);
// // test_jo_unsign_long_long_max()
// 		assert_printf("%jo, %jo", 0, ULLONG_MAX);
// // test_jx_unsign_long_long_max()
// 		assert_printf("%jx, %jx", 0, ULLONG_MAX);
// // test_jX_unsign_long_long_max()
// 		assert_printf("%jX, %jX", 0, ULLONG_MAX);
// // test_err_jo_up_max()
// 		assert_printf("%jO, %jO", 0, USHRT_MAX);
// // test_err_ju_up_max()
// 		assert_printf("%jU, %jU", 0, USHRT_MAX);
// // test_err_jd_up_max()
// 		assert_printf("%jD, %jD", 0, USHRT_MAX);
// // test_zd_simple()
// 		assert_printf("%zd%zd", 0, 42);
// // test_zd_llong_max()
// 		assert_printf("%zd", LLONG_MAX);
// // test_zi_simple()
// 		assert_printf("%zi%zi", 0, 42);
// // test_zi_llong_max()
// 		assert_printf("%zi", LLONG_MAX);
// // test_zu_unsign_long_long_max()
// 		assert_printf("%zu, %zu", 0, ULLONG_MAX);
// // test_zo_unsign_long_long_max()
// 		assert_printf("%zo, %zo", 0, ULLONG_MAX);
// // test_zx_unsign_long_long_max()
// 		assert_printf("%zx, %zx", 0, ULLONG_MAX);
// // test_zX_unsign_long_long_max()
// 		assert_printf("%zX, %zX", 0, ULLONG_MAX);
// // test_err_zo_up_max()
// 		assert_printf("%zO, %zO", 0, USHRT_MAX);
// // test_err_zu_up_max()
// 		assert_printf("%zU, %zU", 0, USHRT_MAX);
// // test_err_zd_up_max()
// 		assert_printf("%zD, %zD", 0, USHRT_MAX);
// // ignore_length_modifiers_with_p_conv()
// 		assert_printf("%lp", 42);
// // simple()
// 		assert_printf("{%10d}", 42);
// // min_width_smaller_than_input()
// 		assert_printf("{%4d}", 10000);
// // min_width_larger_than_input()
// 		assert_printf("{%30d}", 10000);
// // min_width_negative_width()
// 		assert_printf("{%10d}", -42);
// // min_width_c()
// 		assert_printf("{%3c}", 0);
// // pZero_5MinWidth()
// 		assert_printf("{%5p}", 0);
// // pZero_minus15MinWidth()
// 		assert_printf("{%-15p}", 0);
// // pZero_minus13MinWidth()
// 		assert_printf("{%-13p}", &strlen);
// // pZero_minus12MinWidth()
// 		assert_printf("{%-12p}", &strlen);
// // invalidConvSpec_withMinWith()
// 		assert_printf("{%10R}");
// // wideString()
// 		assert_printf("{%30S}", L"我是一只猫。");
// // wideString_minusMinWidth()
// 		assert_printf("{%-30S}", L"我是一只猫。");
// // test_simple()
// 		assert_printf("{%-10d}", 42);
// // test_min_width_smaller_than_input()
// 		assert_printf("{%-4d}", 10000);
// // test_min_width_larger_than_input()
// 		assert_printf("{%-30d}", 10000);
// // test_simple()
// 		assert_printf("{%010d}", 42);
// // test_negative_value()
// 		assert_printf("{%010d}", -42);
// // test_min_width_smaller_than_input()
// 		assert_printf("{%04d}", 10000);
// // test_min_width_larger_than_input()
// 		assert_printf("{%030d}", 10000);
// // test_min_width_with_hexa()
// 		assert_printf("{%030x}", 0xFFFF);
// // test_min_width_with_hexa_caps()
// 		assert_printf("{%030X}", 0xFFFF);
// // char_posMinWidth_zeroFlag()
// 		assert_printf("{%03c}", 0);
// // str_posMinWidth_zeroFlag()
// 		assert_printf("{%05s}", "abc");
// // wide_str_posMinWidth_zeroFlag()
// 		assert_printf("{%030S}", L"我是一只猫。");
// // pointer_posMinWidth_zeroFlag()
// 		assert_printf("{%05p}", 0);
// // pointer_valueLargerThanMinWidth_zeroFlag()
// 		assert_printf("{%05p}", &main);
// // nonValidConv_negativeMinWidth()
// 		assert_printf("{%-15Z}", 123);
// // test_octal_simple()
// 		assert_printf("%#o", 42);
// // test_octal_zero()
// 		assert_printf("%#o", 0);
// // test_octal_max()
// 		assert_printf("%#o", INT_MAX);
// // test_octalUppercase_max()
// 		assert_printf("%#O", 1);
// // test_hex_simple()
// 		assert_printf("%#x", 42);
// // test_hex_zero()
// 		assert_printf("%#x", 0);
// // test_hex_max()
// 		assert_printf("%#x", INT_MAX);
// // test_hex_uppercase_simple()
// 		assert_printf("%#X", 42);
// // test_hex_uppercase_zero()
// 		assert_printf("%#X", 0);
// // test_hex_uppercase_max()
// 		assert_printf("%#X", INT_MAX);
// // test_hex_c_zero()
// 		assert_printf("%#c", 0);
// // test_plus_d_simple()
// 		assert_printf("%+d", 42);
// // test_plus_d_simple_minus()
// 		assert_printf("%+d", -42);
// // test_plus_i_simple()
// 		assert_printf("%+i", 42);
// // test_plus_i_simple_minus()
// 		assert_printf("%+i", -42);
// // test_plus_c_zero()
// 		assert_printf("%+c", 0);
// // test_plus_c_up_zero()
// 		assert_printf("%+C", 0);
// // test_plus_o_zero()
// 		assert_printf("%+o", 0);
// // test_plus_o_42()
// 		assert_printf("%+o", 42);
// // test_plus_o_up_zero()
// 		assert_printf("%+O", 0);
// // test_plus_o_up_42()
// 		assert_printf("%+O", 42);
// // sNullString_plusFlag()
// 		assert_printf("[%+s]", 0);
// // sFakeNullString_plusFlag()
// 		assert_printf("[%+s]", "(null)");
// // octalUppercase()
// 		assert_printf("%+O", 1);
// // test_space_d_simple()
// 		assert_printf("% d", 9999);
// // test_space_d_simple_minus()
// 		assert_printf("% d", -9999);
// // test_space_i_simple()
// 		assert_printf("% i", 9999);
// // test_space_i_simple_minus()
// 		assert_printf("% i", -9999);
// // test_space_u_simple()
// 		assert_printf("% u", 9999);
// // test_space_c_zero()
// 		assert_printf("{% c}", 0);
// // cValidChar_spaceFlag()
// 		assert_printf("{% c}", 'a');
// // sNullString_spaceFlag()
// 		assert_printf("{% s}", NULL);
// // sFakeNullString_spaceFlag()
// 		assert_printf("{% s}", "(null)");
// // sEmptyString_spaceFlag()
// 		assert_printf("{% s}", "");
// // test_space_C_zero()
// 		assert_printf("{% C}", 0);
// // CValidChar_spaceFlag()
// 		assert_printf("{% C}", L'a');
// // SNullString_spaceFlag()
// 		assert_printf("{% S}", NULL);
// // SFakeNullString_spaceFlag()
// 		assert_printf("{% S}", L"(null)");
// // SEmptyString_spaceFlag()
// 		assert_printf("{% S}", L"");
// // positiveDigit_flagsSpacePlus_spaceFirst()
// 		assert_printf("{% +d}", 42);
// // positiveDigit_flagsSpacePlus_plusFirst()
// 		assert_printf("{%+ d}", 42);
// // mix_plus_zero()
// 		assert_printf("{%+03d}", 0);
// // mix_space_zero()
// 		assert_printf("{% 03d}", 0);
// // zeroFlag_minusMinWidth()
// 		assert_printf("{%0-3d}", 0);
// // zeroFlag_plusFlag_minWidth()
// 		assert_printf("{%+03d}", 12);
// // zeroFlag_plusFlag_largeMinWidth()
// 		assert_printf("{%+03d}", 123456);
// // mix_zeroFlag_minWidth_precision()
// 		assert_printf("{%03.2d}", 0);
// // octalUppercase_precision_sharpFlag_zeroValue()
// 		assert_printf("%#.O", 0);
// // test_precision_d()
// 		assert_printf("%.4d", 42);
// // test_precision_d_len_higher_prec()
// 		assert_printf("%.4d", 424242);
// // test_precision_d_len_higher_prec_neg()
// 		assert_printf("%.4d", -424242);
// // test_precision_d_higher_min_width()
// 		assert_printf("%15.4d", 42);
// // test_precision_d_higher_min_width_len_between_width_prec()
// 		assert_printf("%15.4d", 424242);
// // test_precision_d_higher_min_width_len_higher_width()
// 		assert_printf("%8.4d", 424242424);
// // test_precision_d_higher_min_width_neg()
// 		assert_printf("%15.4d", -42);
// // test_precision_d_higher_min_width_len_between_width_prec_neg()
// 		assert_printf("%15.4d", -424242);
// // test_precision_d_higher_min_width_len_higher_width_neg()
// 		assert_printf("%8.4d", -424242424);
// // test_precision_d_higher_precision()
// 		assert_printf("%4.15d", 42);
// // test_precision_d_higher_precision_len_between_width_prec()
// 		assert_printf("%4.15d", 424242);
// // test_precision_d_higher_precision_len_higher_prec()
// 		assert_printf("%4.8d", 424242424);
// // test_precision_d_higher_precision_neg()
// 		assert_printf("%4.15d", -42);
// // test_precision_d_higher_precision_len_between_width_prec_neg()
// 		assert_printf("%4.15d", -424242);
// // test_precision_d_higher_precision_len_higher_prec_neg()
// 		assert_printf("%4.8d", -424242424);
// // test_precision_d_zero_value()
// 		assert_printf("%.d, %.0d", 0, 0);
// // test_precision_d_negative_value()
// 		assert_printf("%.10d", -42);
// // test_precision_i()
// 		assert_printf("%.4i", 42);
// // test_precision_i_higher_min_width()
// 		assert_printf("%15.4i", 42);
// // test_precision_i_higher_precision()
// 		assert_printf("%4.15i", 42);
// // test_precision_i_zero_value()
// 		assert_printf("%.i, %.0i", 0, 0);
// // test_precision_u()
// 		assert_printf("%.4u", 42);
// // test_precision_u_len_higher_prec()
// 		assert_printf("%.4u", 424242);
// // test_precision_u_higher_min_width()
// 		assert_printf("%15.4u", 42);
// // test_precision_u_higher_min_width_len_between_width_prec()
// 		assert_printf("%15.4u", 424242);
// // test_precision_u_higher_min_width_len_higher_width()
// 		assert_printf("%8.4u", 424242424);
// // test_precision_u_higher_precision()
// 		assert_printf("%4.15u", 42);
// // test_precision_u_higher_precision_len_between_width_prec()
// 		assert_printf("%4.15u", 424242);
// // test_precision_u_higher_precision_len_higher_prec()
// 		assert_printf("%4.8u", 424242424);
// // test_precision_u_zero_value()
// 		assert_printf("%.u, %.0u", 0, 0);
// // test_precision_o()
// 		assert_printf("%.4o", 42);
// // test_precision_o_len_higher_prec()
// 		assert_printf("%.4o", 424242);
// // test_precision_o_higher_min_width()
// 		assert_printf("%15.4o", 42);
// // test_precision_o_higher_min_width_len_between_width_prec()
// 		assert_printf("%15.4o", 424242);
// // test_precision_o_higher_min_width_len_higher_width()
// 		assert_printf("%8.4o", 424242424);
// // test_precision_o_higher_precision()
// 		assert_printf("%4.15o", 42);
// // test_precision_o_higher_precision_len_between_width_prec()
// 		assert_printf("%4.15o", 424242);
// // test_precision_o_higher_precision_len_higher_prec()
// 		assert_printf("%4.8o", 424242424);
// // test_precision_o_zero_value()
// 		assert_printf("%.o, %.0o", 0, 0);
// // test_precision_o_up()
// 		assert_printf("%.4O", 42);
// // test_precision_o_up_higher_min_width()
// 		assert_printf("%15.4O", 42);
// // test_precision_o_up_higher_precision()
// 		assert_printf("%4.15O", 42);
// // test_precision_o_up_zero_value()
// 		assert_printf("%.o, %.0O", 0, 0);
// // test_precision_x()
// 		assert_printf("%.4x", 42);
// // test_precision_x_len_higher_prec()
// 		assert_printf("%.4x", 424242);
// // test_precision_x_higher_min_width()
// 		assert_printf("%15.4x", 42);
// // test_precision_x_higher_min_width_len_between_width_prec()
// 		assert_printf("%15.4x", 424242);
// // test_precision_x_higher_min_width_len_higher_width()
// 		assert_printf("%8.4x", 424242424);
// // test_precision_x_higher_precision()
// 		assert_printf("%4.15x", 42);
// // test_precision_x_higher_precision_len_between_width_prec()
// 		assert_printf("%4.15x", 42424242);
// // test_precision_x_higher_precision_len_higher_prec()
// 		assert_printf("%4.8x", 424242424);
// // test_precision_x_zero_value()
// 		assert_printf("%.x, %.0x", 0, 0);
// // test_precision_x_up()
// 		assert_printf("%.4X", 42);
// // test_precision_x_up_len_higher_prec()
// 		assert_printf("%.4X", 424242);
// // test_precision_x_up_higher_min_width()
// 		assert_printf("%15.4X", 42);
// // test_precision_x_up_higher_min_width_len_between_width_prec()
// 		assert_printf("%15.4X", 424242);
// // test_precision_x_up_higher_min_width_len_higher_width()
// 		assert_printf("%8.4X", 424242424);
// // test_precision_x_up_higher_precision()
// 		assert_printf("%4.15X", 42);
// // test_precision_x_up_higher_precision_len_between_width_prec()
// 		assert_printf("%4.15X", 424242);
// // test_precision_x_up_higher_precision_len_higher_prec()
// 		assert_printf("%4.8X", 424242424);
// // test_precision_x_up_zero_value()
// 		assert_printf("%.X, %.0X", 0, 0);
// // test_precision_s()
// 		assert_printf("%.4s", "42");
// // test_precision_s_prec_smaller_than_s_len()
// 		assert_printf("%.4s", "42 is the answer");
// // test_precision_s_higher_min_width()
// 		assert_printf("%15.4s", "42");
// // test_precision_s_higher_min_width_len_between_width_prec()
// 		assert_printf("%15.4s", "I am 42");
// // test_precision_s_higher_min_width_len_higher_width()
// 		assert_printf("%15.4s", "42 is the answer");
// // test_precision_s_higher_precision()
// 		assert_printf("%4.15s", "42");
// // test_precision_s_higher_precision_len_between_width_prec()
// 		assert_printf("%4.15s", "I am 42");
// // test_precision_s_higher_precision_len_higher_width()
// 		assert_printf("%4.15s", "42 is the answer");
// // test_precision_s_implicit_precision()
// 		assert_printf("%4.s", "42");
// // test_precision_S()
// 		assert_printf("%.4S", L"我是一只猫。");
// // test_precision_S_higher_min_width()
// 		assert_printf("%15.4S", L"我是一只猫。");
// // test_precision_S_higher_precision()
// 		assert_printf("%4.15S", L"我是一只猫。");
// // test_precision_S_implicit_precision()
// 		assert_printf("%4.S", L"我是一只猫。");
// // test_precision_S_higher_precision_ascii()
// 		assert_printf("%4.1S", L"Jambon");
// // cNullChar()
// 		assert_printf("%.c", 0);
// // cNullChar_positivePrecision()
// 		assert_printf("%.5c", 0);
// // cPositiveValue_positivePrecision()
// 		assert_printf("%.5c", 42);
// // cUpperNullChar()
// 		assert_printf("%.C", 0);
// // cUpperNullChar_positivePrecision()
// 		assert_printf("%.5C", 0);
// // cUpperPositiveValue_positivePrecision()
// 		assert_printf("%.5C", 42);
// // pNullPointer_zeroPrecision()
// 		assert_printf("%.0p, %.p", 0, 0);
// // pNullPointer_3Precision()
// 		assert_printf("%.5p", 0);
// // Pointer_Precision_width_len_between_width_prec()
// 		assert_printf("%9.2p", 1234);
// // Pointer_Precision_width_len_higher_width()
// 		assert_printf("%9.2p", 1234567);
// // Pointer_Precision_width_min_len_between_width_prec()
// 		assert_printf("%2.9p", 1234);
// // Pointer_Precision_width_min_len_higher_prec()
// 		assert_printf("%2.9p", 1234567);
// // percent_point3precision()
// 		assert_printf("%.3%");
// // test_precision_o_sharp_zero()
// 		assert_printf("%#.o, %#.0o", 0, 0);
// // test_precision_x_sharp_zero()
// 		assert_printf("%#.x, %#.0x", 0, 0);
// // test_precision_p_zero()
// 		assert_printf("%.p, %.0p", 0, 0);
// // char_precision_minwdith_and_flagZero()
// 		assert_printf("{%05.c}", 0);
// // string_precision_minwdith_and_flagZero()
// 		assert_printf("{%05.s}", 0);
// // percent_precision_minwdith_and_flagZero()
// 		assert_printf("{%05.%}", 0);
// // nonValidConvSpec_precision_minwdith_and_flagZero()
// 		assert_printf("{%05.Z}", 0);
// // hex_precision_and_flagSharp()
// 		assert_printf("{%#.5x}", 1);
// // octal_precision_and_flagSharp()
// 		assert_printf("%#.3o", 1);
// // wideString_precisionMinWidth_flagZero()
// 		assert_printf("{%05.S}", L"42 c est cool");
// // test_hhd()
// 		assert_printf("%hhd - %hhd", SHRT_MAX - 42,  SHRT_MAX - 4200);
// // test_zi()
// 		assert_printf("%zi", LLONG_MIN);
// // test_zd()
// 		assert_printf("%zd", LLONG_MIN);
// // test_p_incompatible_flags()
// 		assert_printf("% p|%+p", 42, 42);
// // test_unsigned_neg()
// 		assert_printf("%u", -42);
// // test_unsigned_max_plus_one()
// 		assert_printf("%u", UINT_MAX + 1);
// // test_unsigned_long_max_plus_one()
// 		assert_printf("%U", ULONG_MAX + 1);
// // test_big_char()
// 		assert_printf("%c", 200);
// // test_u_incompatible_flags()
// 		assert_printf("% u|%+u", 42, 42);
// // test_hhu()
// 		assert_printf("%hhu / %hhu", SHRT_MAX - 42,  SHRT_MAX - 4200);
// // test_octal_neg()
// 		assert_printf("%o, %ho, %hho", -42, -42, -42);
// // test_octal_long_max()
// 		assert_printf("%o", LONG_MAX);
// // test_octal_up_long_min()
// 		assert_printf("%O", LONG_MIN);
// // test_octal_space_plus()
// 		assert_printf("% o|%+o", 42, 42);
// // test_octal_sharp_precision()
// 		assert_printf("%#.o", 42);
// // test_x_incompatible_flags()
// 		assert_printf("% x|%+x", 42, 42);
// // test_x_up_incompatible_flags()
// 		assert_printf("% X|%+X", 42, 42);
// // wildcard_for_min_width_positive()
// 		assert_printf("%*d", 5, 42);
// // wildcard_for_min_width_negative()
// 		assert_printf("{%*d}", -5, 42);
// // wildcard_for_min_width_zero()
// 		assert_printf("{%*d}", 0, 42);
// // wildcard_for_min_width_c_zero()
// 		assert_printf("{%*c}", 0, 0);
// // c_minWidthNegative_zeroValue()
// 		assert_printf("{%*c}", -15, 0);
// // wildcard_for_precision_digit_positive()
// 		assert_printf("{%.*d}", 5, 42);
// // wildcard_for_precision_digit_negative()
// 		assert_printf("{%.*d}", -5, 42);
// // wildcard_for_precision_digit_zero()
// 		assert_printf("{%.*d}", 0, 42);
// // wildcard_for_precision_string_positive()
// 		assert_printf("{%.*s}", 5, "42");
// // wildcard_for_precision_string_negative()
// 		assert_printf("{%.*s}", -5, "42");
// // wildcard_for_precision_string_zero()
// 		assert_printf("{%.*s}", 0, "42");
// // sNullString_zeroMinWidth()
// 		assert_printf("{%*s}", 5, 0);
// // pointer_wildcard()
// 		assert_printf("{%3*p}", 10, 0);
// // wildcard_for_min_width_positive()
// 		assert_printf("%*.*d", 0, 3, 0);
// // digit_wildcard_and_min_width_value1()
// 		assert_printf("{%3*d}", 0, 0);
// // digit_wildcard_and_min_width_value2()
// 		assert_printf("{%*3d}", 0, 0);
// // digit_wildcard_and_min_width_value3()
// 		assert_printf("{%*3d}", 5, 0);
// // digit_wildcard_negativePrecision()
// 		assert_printf("{%05.*d}", -15, 42);
// // simple_small_nbr()
// 		assert_printf("{%f}{%F}", 1.42, 1.42);
// // simple_negative_small_nbr()
// 		assert_printf("{%f}{%F}", -1.42, -1.42);
// // simple_large_nbr()
// 		assert_printf("{%f}{%F}", 1444565444646.6465424242242, 1444565444646.6465424242242);
// // simple_negative_large_nbr()
// 		assert_printf("{%f}{%F}", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654);
	return (0);
}