
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "context/context.h"
#include "render/buffer.h"
#include "events/events.h"
#include "render/draw.h"
#include "utils/utils.h"
#include "update/frame.h"


int x = 0;
t_image *img;


// int frame(void *addr) {
// 	(void)addr;
// 	fill(img, 0);

// 	// draw_line(img, (t_pos){100, 100}, (t_pos){300, 200}, 0xff0000);
// 	// draw_line(img, (t_pos){500, 500}, (t_pos){300, 200}, 0x00ff00);
// 	// draw_line(img, (t_pos){100, 100}, (t_pos){100, 300}, 0x0000ff);
// 	// draw_line(img, (t_pos){300, 200}, (t_pos){100, 300}, 0x00ffff);
// 	// draw_line(img, (t_pos){600, 200}, (t_pos){500, 700}, 0xff00ff);
// 	// draw_line_grad(img, (t_pos){100, 100}, (t_pos){300, 200}, make_grad(0xff0000, 0xff));
// 	// draw_line_grad(img, (t_pos){500, 500}, (t_pos){300, 200}, make_grad(0xff0000, 0xff));
// 	// draw_line_grad(img, (t_pos){100, 100}, (t_pos){100, 300}, make_grad(0xff0000, 0xff));
// 	// draw_line_grad(img, (t_pos){300, 200}, (t_pos){100, 300}, make_grad(0xff0000, 0xff));
// 	// draw_line_grad(img, (t_pos){600, 200}, (t_pos){500, 700}, make_grad(0xff0000, 0xffff));
// 	// set_pixel(img, x/10, 300, rgb2color(255, 0, 0));
// 	// mlx_put_image_to_window(mlx(), window(), img->image, 0, 0);
// 	// x++;
// 	// if (x % 100 == 0)
// 	// 	printf("%d\n", x);
// 	return (0);
// }

t_upd upd_var;


int main() {
	init_context();
	launch_window(1280, 960, "test");
	// mlx_key_hook(window(), keydown_event, &keys);
	mlx_hook(window(), 17, 0, quit_event, NULL);
	mlx_hook(window(), 2, 1 << 0, keydown_event, &upd_var.key);
	mlx_hook(window(), 3, 1 << 1, keyup_event, &upd_var.key);

	// img = new_image(1280, 960);
	upd_var.render.img = new_image(1280, 960);
	// set_pixel(img, 100, 100, rgb2color(255, 0, 0));

	// draw_line_grad(img, (t_pos){100, 100}, (t_pos){300, 200}, make_grad(0xff0000, 0xff));
	// draw_line_grad(img, (t_pos){500, 500}, (t_pos){300, 200}, make_grad(0xff0000, 0xff));
	// draw_line_grad(img, (t_pos){100, 100}, (t_pos){100, 300}, make_grad(0xff0000, 0xff));
	// draw_line_grad(img, (t_pos){300, 200}, (t_pos){100, 300}, make_grad(0xff0000, 0xff));
	// draw_line_grad(img, (t_pos){600, 200}, (t_pos){500, 700}, make_grad(0xff0000, 0xff));
	// draw_line_grad(img, (t_pos){600, 200}, (t_pos){500, 700}, make_grad(0xff0000, 0xffff));


	// mlx_put_image_to_window(mlx(), window(), img->image, 0, 0);


	mlx_loop_hook(mlx(), frame, &upd_var);
	mlx_loop(mlx());
	printf("here\n");


	return (0);
}
