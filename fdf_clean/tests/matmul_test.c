#include <stdio.h>
#include <stdlib.h>

typedef double t_mat4[4][4];

void	matmul(t_mat4 a, t_mat4 b, t_mat4 out)
{
	int	row;
	int	col;
	// printf("size %lu\n", sizeof(a));

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			out[row][col] = a[row][0] * b[0][col] + a[row][1] * b[1][col]
				+ a[row][2] * b[2][col] + a[row][3] * b[3][col];
			// out[row][col] = 0;
			// idx = 0;
			// while (idx < 4)
			// {
			// 	out[row][col] += a[row][idx] * b[idx][col];
			// 	idx++;
			// }
			col++;
		}
		row++;
	}
}

void	show(t_mat4 mat) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("% .2f ", mat[i][j]);
		}
		printf("\n");
	}
}

int main() {
	t_mat4 a = {
		{1, 2, 0, 3},
		{-1, 0, 0, 0},
		{0, -3, 0, 0},
		{-1, 1, 0, 1},
	};
	t_mat4 b = {
		{0, 3, -2, -1},
		{1, 2, 0, -3},
		{2, 1, -1, 0},
		{3, 0, 0, -1},
	};

	t_mat4 out;
	matmul(a, b, out);

	printf("a:\n");
	show(a);
	printf("\nb\n");
	show(b);
	printf("\nout\n");
	show(out);
}
