
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#include "libft.h"

// void	*free_str_array(char **arr, int n);
void	*free_str_array(char **arr, int n)
{
	int	idx;

	idx = 0;
	while (idx < n)
	{
		free(arr[idx]);
		idx++;
	}
	free(arr);
	return (NULL);
}

void test00()  // ft_split
{
	// char s[] = " sf  sadjfkn asf as wd asdf af fdfasf t  sadfa asdfasa  sfsdf  asf";
	char s[] = "";
	char delimiter = ' ';
	char **splitted = ft_split(s, delimiter);

	printf("target string:\n");
	printf("\"%s\"\n", s);
	printf("splitted:\n");
	int i = 0;
	for (; splitted[i]; i++)
	{
		printf("%02d: \"%s\"\n", i, splitted[i]);
	}
	free_str_array(splitted, i);
}

void test01()  // ft_cmp
{
	char s1[100] = "abcdeFGHIJ012345789.....";
	char s2[100] = "abcdeFGHIJa12345789.....";
	char s3[100] = "abcdeFG";
	char s4[100] = "bsn";
	int ret1, ret2;

	printf("target string:\n");
	printf("s1: \"%s\"\n", s1);
	printf("s2: \"%s\"\n", s2);
	printf("s3: \"%s\"\n", s2);

	ret1 = ft_strncmp(s1, s4, 0);
	ret2 = strncmp(s1, s4, 0);
	printf("my %d, abs %d\n", ret1, ret2);

	ret1 = ft_strncmp(s1, s2, 10);
	ret2 = strncmp(s1, s2, 10);
	printf("my %d, abs %d\n", ret1, ret2);

	ret1 = ft_strncmp(s1, s2, 11);
	ret2 = strncmp(s1, s2, 11);
	printf("my %d, abs %d\n", ret1, ret2);

	ret1 = ft_strncmp(s1, s3, 7);
	ret2 = strncmp(s1, s3, 7);
	printf("my %d, abs %d\n", ret1, ret2);

	ret1 = ft_strncmp(s1, s3, 8);
	ret2 = strncmp(s1, s3, 8);
	printf("my %d, abs %d\n", ret1, ret2);


	ret1 = ft_memcmp(s1, s2, 11);
	ret2 = memcmp(s1, s2, 11);
	printf("my %d, abs %d\n", ret1, ret2);

	s1[4] = 0;
	s2[4] = 0;
	ret1 = ft_memcmp(s1, s2, 8);
	ret2 = memcmp(s1, s2, 8);
	printf("my %d, abs %d\n", ret1, ret2);

}

void putnbr_itoa(int n)
{
	char *num_str = ft_itoa(n);
	printf("%s", num_str);
	free(num_str);
	fflush(NULL);
}

void test02()
{
	char s[] = "target string!!fsdaf+sad sfas\t sadf\nsa sd  ";

	printf("%s\n", s);
	ft_putendl_fd(s, 1);
	fflush(NULL);

	int n;
	n = INT_MAX;
	printf("my : ");
	fflush(NULL);
	// ft_putnbr_fd(n, 1);
	putnbr_itoa(n);
	ft_putchar_fd('\n', 1);
	printf("abs: %d\n", n);

	n = INT_MIN;
	printf("my : ");
	fflush(NULL);
	// ft_putnbr_fd(n, 1);
	putnbr_itoa(n);
	ft_putchar_fd('\n', 1);
	printf("abs: %d\n", n);

	n = 0;
	printf("my : ");
	fflush(NULL);
	// ft_putnbr_fd(n, 1);
	putnbr_itoa(n);
	ft_putchar_fd('\n', 1);
	printf("abs: %d\n", n);

	n = -235;
	printf("my : ");
	fflush(NULL);
	// ft_putnbr_fd(n, 1);
	putnbr_itoa(n);
	ft_putchar_fd('\n', 1);
	printf("abs: %d\n", n);
}

void test03()
{
	char s[] = " Adf532ERH\nkunaPFoj642e&wa \tFdsn u4ak2 -`";

	printf("target string:\n");
	printf("\"%s\"\n", s);

	int target = 256 + 65;
	printf("my : %s\n", ft_strchr(s, target));
	printf("abs: %s\n", strchr(s, target));
}

int main()
{
	test03();
}
