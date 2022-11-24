
#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char *format_string, ...);


int main() {
	int my, abs;

	my = ft_printf("hello\n");
	abs = printf("hello\n");
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("hello print3 %d\n", 3);
	abs = printf("hello print3 %d\n", 3);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("hello printhex %x\n", 255);
	abs = printf("hello printhex %x\n", 255);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("str null %s\n", NULL);
	abs = printf("str null %s\n", NULL);
	printf("my %d, abs %d\n\n", my, abs);
}

