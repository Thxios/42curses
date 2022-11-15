
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
	char s[] = "_ Adf532ERH  ^kunaPFoj642e&wa \tFdsn u4ak2 -`";

	printf("target string:\n");
	printf("\"%s\"\n", s);
	int target;

	target = 256 + 65;
	printf("my : %s\n", ft_strchr(s, target));
	printf("abs: %s\n", strchr(s, target));

	target = ' ';
	printf("my : %s\n", ft_strchr(s, target));
	printf("abs: %s\n", strchr(s, target));
	printf("my : %s\n", ft_strrchr(s, target));
	printf("abs: %s\n", strrchr(s, target));

	target = '_';
	printf("my : %s\n", ft_strrchr(s, target));
	printf("abs: %s\n", strrchr(s, target));

	target = 'K';
	printf("my : %s\n", ft_strchr(s, target));
	printf("abs: %s\n", strchr(s, target));

	for (int i = 0; s[i]; i++)
		printf("%c", ft_tolower(s[i]));
	printf("\n");
	for (int i = 0; s[i]; i++)
		printf("%c", ft_toupper(s[i]));
	printf("\n");
}

void test04()
{
	char s[] = "   sadj4^#2870 sadfa a5sdf";
	char *sub;

	printf("target string:\n");
	printf("\"%s\" len %d\n", s, ft_strlen(s));

	sub = ft_substr(s, 0, 10);
	printf("\"%s\" len %d\n", sub, ft_strlen(sub));

	sub = ft_substr(s, 5, 0);
	printf("\"%s\" len %d\n", sub, ft_strlen(sub));

	sub = ft_substr(s, 20, 10);
	printf("\"%s\" len %d\n", sub, ft_strlen(sub));

	char s1[] = "abc";
	char s2[] = "0123456";
	char *joined = ft_strjoin(s1, s2);
	printf("%s %d\n", joined, ft_strlen(joined));

	char st[] = "  o ";
	char to_trim[] = " ";
	char *trimmed = ft_strtrim(st, to_trim);
	printf("before trim:\n");
	printf("\"%s\" len %d\n", st, ft_strlen(st));
	printf("after trim:\n");
	printf("\"%s\" len %d\n", trimmed, ft_strlen(trimmed));
}

char apply_func(unsigned int idx, char c)
{
	if (idx % 2)
		return ft_tolower(c);
	else
		return ft_toupper(c);
}
void apply_func2(unsigned int idx, char *c)
{
	if (idx % 2)
		*c = ft_tolower(*c);
	else
		*c = ft_toupper(*c);
}

void test05()
{
	char s[] = "   sa 23456ASDasdDgdj4^#2870 sadfa a5sdf";
	char *sub;

	printf("target string:\n");
	printf("\"%s\" len %d\n", s, ft_strlen(s));
	
	char *mapped;
	mapped = ft_strmapi(s, &apply_func);
	printf("\"%s\" len %d\n", mapped, ft_strlen(mapped));

	ft_striteri(s, &apply_func2);
	printf("\"%s\" len %d\n", mapped, ft_strlen(mapped));
}

t_list *make_str_list(char *s)
{
	t_list *begin = NULL;

	for (int i = 0; s[i]; i++)
		ft_lstadd_back(&begin, ft_lstnew(&s[i]));
	
	return begin;
}

void	print_str_list(t_list *begin)
{
	t_list *cur = begin;
	int idx = 0;
	while (cur)
	{
		printf("%02d: %x \'%c\'\n", idx, cur->content, *((char *)cur->content));
		idx++;
		cur = cur->next;
	}
}

void del_elem(void *data)
{
	// printf("del_elem \'%x\'\n", data);
	printf("del_elem %x \'%c\'\n", data, *((char *)data));
}

void *mapping(void *data)
{
	char *ret = malloc(sizeof(char));
	*ret = ft_toupper(*((char*)data));
	return ret;
}

void iter_func(void *data)
{
	printf("iter_elem \'%c\'\n", *((char *)data));
}

void test06()
{
	char s[] = "Da sdDg#27 f";
	char *sub;

	printf("target string:\n");
	printf("\"%s\" len %d\n", s, ft_strlen(s));

	t_list *list = make_str_list(s);
	print_str_list(list);

	printf("list len %d\n", ft_lstsize(list));

	t_list *mapped = ft_lstmap(list, &mapping, &del_elem);
	print_str_list(mapped);

	ft_lstiter(list, &iter_func);

	print_str_list(list);

	char tod = '!';
	t_list *todel = ft_lstnew(&tod);
	ft_lstdelone(todel, &del_elem);
	ft_lstclear(&mapped, &del_elem);
	print_str_list(mapped);
}

void test07()
{
	char s[] = "   sa 23456ASDasdDgdj4^#2870 sadfa a5sdf";
	char *sub;

	sub = ft_substr("", 2, 1);
	printf("\"%s\" len %d\n", sub, ft_strlen(sub));
}

void test08()
{
	char src[100] = "0123456789abcdefghij..........";
	char *s = src;
	char *d = src+10;

	printf("target string:\n");
	printf("\"%s\" len %d\n", src, ft_strlen(src));

	printf("source \"%s\" len %d\n", s, ft_strlen(s));

	ft_memmove(d, s, 15);
	printf("dest   \"%s\" len %d\n", d, ft_strlen(d));
	printf("target string:\n");
	printf("\"%s\" len %d\n", src, ft_strlen(src));
}

void test09()
{
	strnstr(NULL, "fake", 3);
}

int main()
{
	test09();
}
