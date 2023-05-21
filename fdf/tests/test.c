
#include <stdio.h>
#include "mlx.h"


int main() {
	void *mlx = mlx_init();

	void *window = mlx_new_window(mlx, 960, 720, "test");

	mlx_loop(mlx);
}
