
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libft.h"


int main()
{
	// char s1[100] = "abcdefghijklmnop....0123456789";
	// char s2[100] = "0123456789++++++++++";
	// char s1[100] = "abcdefghij0123456789";
	char s1[100] = "";
	s1[7] = 0;
	char s2[100] = "";
	int sz = 10;

	char *my = ft_strnstr(s1, s2, sz);

	printf("%s\n", s1);
	printf("%s\n", (my ? my : "NULL"));
}

