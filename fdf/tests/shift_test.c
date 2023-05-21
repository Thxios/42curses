
#include <stdio.h>

typedef unsigned int t_color;

int	clip(int val, int min, int max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}
t_color	rgba2color(int r, int g, int b, int a)
{
	r = clip(r, 0, 255);
	g = clip(g, 0, 255);
	b = clip(b, 0, 255);
	a = clip(a, 0, 255);

	return ((a << 24) | (r << 16) | (g << 8) | b);
}

int main() {
	int a = 255;

	printf("a: %d, %#x\n", a, a);
	t_color b = a << 24;

	printf("b: %u, %#x\n", b, b);

	t_color c = rgba2color(255, 255, 255, 255);
	printf("c: %#x\n", c);
}

