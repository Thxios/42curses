
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int	ft_printf(const char *format_string, ...);


int main() {
	int my, abs;

	my = ft_printf("hello\n");
	abs = printf("hello\n");
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("hello print3 %d\n", 3);
	abs = printf("hello print3 %d\n", 3);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("hello printhex %x\n", -1);
	abs = printf("hello printhex %x\n", -1);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("hello printhex %X\n", 0);
	abs = printf("hello printhex %X\n", 0);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("str null %s\n", NULL);
	abs = printf("str null %s\n", NULL);
	printf("my %d, abs %d\n\n", my, abs);

	char *ptr = "asdf";
	my = ft_printf("ptr %p\n", ptr);
	abs = printf("ptr %p\n", ptr);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("percent %%c\n");
	abs = printf("percent %%c\n");
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("percent %%%%c\n");
	abs = printf("percent %%%%c\n");
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("%%c\n");
	abs = printf("%%c\n");
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("|% -10d|\n", 1234);
	abs = printf("|% -10d|\n", 1234);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("|%+-10d|\n", 1234);
	abs = printf("|%+-10d|\n", 1234);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("|%010d|\n", -1234);
	abs = printf("|%010d|\n", -1234);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("|%20.10d|\n", -1234);
	abs = printf("|%20.10d|\n", -1234);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("|% .10d|\n", 1234);
	abs = printf("|% .10d|\n", 1234);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("|%.1d|\n", 0);
	abs = printf("|%.1d|\n", 0);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("|%.2d|\n", 1);
	abs = printf("|%.2d|\n", 1);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("|%.2d|\n", -1);
	abs = printf("|%.2d|\n", -1);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("|%.3d|\n", 11);
	abs = printf("|%.3d|\n", 11);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("|% 10.3d|\n", 11);
	abs = printf("|% 10.3d|\n", 11);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("|%-4d|\n", 9);
	abs = printf("|%-4d|\n", 9);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("|%0#10x|\n", 1234);
	abs = printf("|%0#10x|\n", 1234);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("|%#10.6x|\n", 0);
	abs = printf("|%#10.6x|\n", 0);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("|%#x|\n", LONG_MIN);
	abs = printf("|%#x|\n", LONG_MIN);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("|%-20p|\n", LONG_MIN);
	abs = printf("|%-20p|\n", LONG_MIN);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("|%20p|\n", LONG_MAX);
	abs = printf("|%20p|\n", LONG_MAX);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("%08.3x\n", 8375);
	abs = printf("%08.3x\n", 8375);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("%.03s\n", NULL);
	abs = printf("%.03s\n", NULL);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("%3.6s\n", NULL);
	abs = printf("%3.6s\n", NULL);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("%20.6s\n", NULL);
	abs = printf("%20.6s\n", NULL);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("%.6s\n", NULL);
	abs = printf("%.6s\n", NULL);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("%15.3p\n", NULL);
	abs = printf("%15.3p\n", NULL);
	printf("my %d, abs %d\n\n", my, abs);

	my = ft_printf("%-15p\n", NULL);
	abs = printf("%-15p\n", NULL);
	printf("my %d, abs %d\n\n", my, abs);
}

