
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
}

