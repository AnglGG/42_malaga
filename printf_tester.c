#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void test_pointer(void)
{
	const char *nombre = "alicia"; 
	int contador = ft_printf("Hola me llamo: %p", nombre);
	printf("\nft_printf contador: %d\n", contador);
	contador = printf("Hola me llamo: %p", nombre);
	printf("\nprintf contador: %d\n", contador);
}

void test_string(void)
{
	const char *str = "Hello, World!";
	int contador = ft_printf("String: %s", str);
	printf("\nft_printf contador: %d\n", contador);
	contador = printf("String: %s", str);
	printf("\nprintf contador: %d\n", contador);
}

void test_string_null(void)
{
	const char *str = NULL;
	int contador = printf("String: %s", str);
	printf("\nprintf contador: %d\n", contador);
	contador = ft_printf("String: %s", str);
	printf("\nft_printf contador: %d\n", contador);
}
void test_pointer_null(void)
{
	int contador = printf("The NULL macro represents the %p address", ((void*)0));
	printf("\nprintf contador: %d\n", contador);
	contador = ft_printf("The NULL macro represents the %p address", ((void*)0));
	printf("\nprintf contador: %d\n", contador);
}

void test_pointer_null_2(void)
{
	int contador = printf(" %p ", NULL);
	printf("\nprintf contador: %d\n", contador);
	contador = ft_printf(" %p ", NULL);
	printf("\nprintf contador: %d\n", contador);
}

void test_hex_min_zero(void)
{
	int contador = printf("El 0 es igual a %x", 0);
	printf("\nprintf contador: %d\n", contador);
	contador = ft_printf("El 0 es igual a %x", 0);
	printf("\nprintf contador: %d\n", contador);
}

void test_hex_min(void)
{
	int contador = printf("El resutlado es: %x", 3735929054u);
	printf("\nprintf contador: %d\n", contador);
	contador = ft_printf("El resultado es: %x", 3735929054u);
	printf("\nprintf contador: %d\n", contador);
}
//bonus
void test_negative(void)
{
	int contador = printf("El resutlado es: %-5d", 42);
	printf("\nprintf contador: %d\n", contador);
	contador = ft_printf("El resultado es: %-5d", 42);
	printf("\nprintf contador: %d\n", contador);
}

void test_negative_2(void)
{
	int contador = printf("El resutlado es: %-5d", 1234567);
	printf("\nprintf contador: %d\n", contador);
	contador = ft_printf("El resultado es: %-5d", 1234567);
	printf("\nprintf contador: %d\n", contador);
}

void test_right_justification(void)
{
	int contador = printf("El resutlado es: %5d", 123);
	printf("\nprintf contador: %d\n", contador);
	contador = ft_printf("El resultado es: %5d", 123);
	printf("\nprintf contador: %d\n", contador);
}

void test_right_justification_2(void)
{
	int contador = printf("El resutlado es: %5s", "123456");
	printf("\nprintf contador: %d\n", contador);
	contador = ft_printf("El resultado es: %5s", "123456");
	printf("\nprintf contador: %d\n", contador);
}

void test_dot_1(void)
{
	int contador = printf("La frase es: %.2s", "hi there");
	printf("\nprintf contador: %d\n", contador);
	contador = ft_printf("La frase es: %.2s", "hi there");
	printf("\nprintf contador: %d\n", contador);
}

void test_dot_2(void)
{
	int contador = printf("La frase es: %.s", "hi there");
	printf("\nprintf contador: %d\n", contador);
	contador = ft_printf("La frase es: %.s", "hi there");
	printf("\nprintf contador: %d\n", contador);
}

void test_dot_3(void)
{
	int contador = printf("La frase es: %.d", 0);
	printf("\nprintf contador: %d\n", contador);
	contador = ft_printf("La frase es: %.d", 0);
	printf("\nprintf contador: %d\n", contador);
}

void test_dot_4(void)
{
	int contador = printf("El número es: %42.20d", 42000);
	printf("\nprintf contador: %d\n", contador);
	contador = ft_printf("El número es: %42.20d", 42000);
	printf("\nprintf contador: %d\n", contador);
}

void negative_with_zero(void)
{
	int contador = printf("EL número es: %012d", (int)-2147483648);
	printf("\nprintf contador: %d\n", contador);
	contador = ft_printf("El número es: %012d", (int)-2147483648);
	printf("\nprintf contador: %d\n", contador);
}

void long_max_x(void)
{
	int contador = printf("EL número es: %x", LONG_MAX);
	printf("\nprintf contador: %d\n", contador);
	contador = ft_printf("El número es: %x", LONG_MAX);
	printf("\nprintf contador: %d\n", contador);
}

int main()
{
	test_pointer();
	test_string();
	test_string_null();
	test_pointer_null();
	test_hex_min_zero();
	test_hex_min();
	test_negative();
	test_negative_2();
	test_right_justification();
	test_right_justification_2();
	test_dot_1();
	test_dot_2();
	test_dot_3();
	test_dot_4();
	negative_with_zero();
	long_max_x();
	test_pointer_null_2();

	return 0;
}
