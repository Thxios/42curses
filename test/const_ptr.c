
#include "stdio.h"


void f1(const char *s)
{
	// s[0] = 'a';
	s = "1426";
}

void f2(char const *s)
{
	// s[0] = 'a';
	s = "342";
}

void f3(char * const s)
{
	s[0] = 'a';
	// s = "342";
}


int main()
{
	char s[] = "0239hfafshjksdfhk";
	printf("%s\n", s);
	f1(s);
	f2(s);
	f3(s);
	printf("%s\n", s);
}
