
#include <stdio.h>

int main()
{
	int ret;

	printf("\n%%9d:\n");
	ret = printf("|%9d|\n", 10);
	printf("ret %d\n", ret);

	printf("\n%%3d:\n");
	ret = printf("|%3d|\n", 1234);
	printf("ret %d\n", ret);

	printf("\n%%#d: undefined\n");
	printf("\n%%x:\n");
	ret = printf("|%x|\n", 1234);
	printf("ret %d\n", ret);

	printf("\n%%#10x:\n");
	ret = printf("|%#10x|\n", 1234);
	printf("ret %d\n", ret);

	printf("\n%%+10d:\n");
	ret = printf("|%0+10d|\n", 1234);
	printf("ret %d\n", ret);

	printf("\n%% .d:\n");
	ret = printf("|% .d|\n", 1);

	printf("\n%% 010d:\n");
	ret = printf("|% 010d|\n", 1234);
	printf("ret %d\n", ret);

	printf("\n%%+10d:\n");
	ret = printf("|%+10d|\n", 1234);
	printf("ret %d\n", ret);

	printf("\n%% +d:\n");
	ret = printf("|% +d|\n", 1234);
	printf("ret %d\n", ret);

	printf("\n%%10.5d:\n");
	ret = printf("|%10.5d|\n", 1234);
	printf("ret %d\n", ret);

	printf("\n%%005d:\n");
	ret = printf("|%005d|\n", 1234);
	printf("ret %d\n", ret);

	printf("\n%% 10:\n");
	ret = printf("|% 10|\n", 1234);
	printf("ret %d\n", ret);

	printf("\n%%10%%\n");
	ret = printf("|%10%|\n", 1234);
	printf("ret %d\n", ret);

	printf("\n%%d\n");
	ret = printf("|%d|\n", 214748364899ll);
	printf("ret %d\n", ret);

	char *s = "asdf";
	printf("\n%% 15p\n");
	ret = printf("|% 15p|\n", s);
	printf("ret %d\n", ret);

	printf("\n%%u\n");
	ret = printf("|%u|\n", 214748364899ll);
	printf("ret %d\n", ret);

	printf("\n%%+10d:\n");
	ret = printf("|%+10d|\n", 1234);
	printf("ret %d\n", ret);

	printf("\n%% -10d:\n");
	ret = printf("|% -10d|\n", 1234);
	printf("ret %d\n", ret);

	printf("\n%%20.10d:\n");
	ret = printf("|%20.10d|\n", -1234);
	printf("ret %d\n", ret);

	printf("\n%% .10d:\n");
	ret = printf("|% .10d|\n", 1234);
	printf("ret %d\n", ret);

	printf("\n%% +d:\n");
	ret = printf("|% +d|\n", 0);
	printf("ret %d\n", ret);

	printf("\n%%020.10d:\n");
	ret = printf("|%020.10d|\n", 1234);
	printf("ret %d\n", ret);

	printf("\n%%.d:\n");
	ret = printf("|%.d|\n", 0);
	printf("ret %d\n", ret);

	printf("\n%%10.d:\n");
	ret = printf("|%10.d|\n", 0);
	printf("ret %d\n", ret);

	printf("\n%%+.d:\n");
	ret = printf("|%+.d|\n", 0);
	printf("ret %d\n", ret);

	printf("\n%%0#10x:\n");
	ret = printf("|%0#10x|\n", 123);
	printf("ret %d\n", ret);

	printf("\n%%#10.0x:\n");
	ret = printf("|%#10.0x|\n", 0);
	printf("ret %d\n", ret);

	printf("\n%%p:\n");
	ret = printf("|%p|\n", 0);
	printf("ret %d\n", ret);

	printf("\n%%-10p:\n");
	ret = printf("|%-10p|\n", 0);
	printf("ret %d\n", ret);

	printf("\n%%-10c:\n");
	ret = printf("|%-10c|\n", 'T');
	printf("ret %d\n", ret);

	printf("\n%%20.10s:\n");
	ret = printf("|%20.10s|\n", "abcde0123456789");
	printf("ret %d\n", ret);

	printf("\n%%10.0s:\n");
	ret = printf("|%10.0s|\n", "abcde0123456789");
	printf("ret %d\n", ret);

	printf("\n%%10.0c:\n");
	ret = printf("|%10.0c|\n", 'a');
	printf("ret %d\n", ret);

	printf("\n%%.10s:\n");
	ret = printf("|%.10s|\n", "1234");
	printf("ret %d\n", ret);

	printf("\n%%10%%s:\n");
	ret = printf("|%10%|\n");
	printf("ret %d\n", ret);
}
