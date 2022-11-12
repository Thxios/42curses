
#include <stdio.h>
#include <limits.h>


int main()
{
	int ret;
	unsigned long long a = 0x0f0000000000000f;
	ret = printf("%d %d", a);
	printf(" ret %d\n", ret);
}
