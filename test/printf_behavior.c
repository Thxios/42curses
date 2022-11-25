
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
}
