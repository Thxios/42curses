
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "context/context.h"
#include "render/buffer.h"
#include "events/events.h"
#include "render/draw.h"
#include "utils/utils.h"
#include "update/frame.h"
#include "object/object.h"
#include "utils/matrix.h"
#include "config.h"


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

t_vertex make_vertex(double x, double y, double z){
	t_vertex out;

	out.p = (t_vec){x, y, z};
	return out;
}

t_obj3d *new_obj_test(void)
{
	t_obj3d	*obj = new_object3d((t_vec){0, 0, 10});

	double SIZE = 2;
	obj->n_vertices = 6;
	obj->v = calloc(obj->n_vertices, sizeof(t_vertex));
	// obj->v[0] = make_vertex(1, 1, 0);
	// obj->v[1] = make_vertex(-1, 0, 0);
	// obj->v[2] = make_vertex(1, -1, 1);

	obj->n_edges = 12;
	obj->e = calloc(obj->n_edges, sizeof(t_edge));
	// obj->e[0] = (t_edge){0, 1};
	// obj->e[1] = (t_edge){1, 2};

    obj->v[0] = make_vertex(SIZE, 0, 0);
    obj->v[1] = make_vertex(-SIZE, 0, 0);
    obj->v[2] = make_vertex(0, SIZE, 0);
    obj->v[3] = make_vertex(0, 0, SIZE);
    obj->v[4] = make_vertex(0, -SIZE, 0);
    obj->v[5] = make_vertex(0, 0, -SIZE);

    obj->e[0] = (t_edge){0, 2};
    obj->e[1] = (t_edge){0, 3};
    obj->e[2] = (t_edge){0, 4};
    obj->e[3] = (t_edge){0, 5};
    obj->e[4] = (t_edge){1, 2};
    obj->e[5] = (t_edge){1, 3};
    obj->e[6] = (t_edge){1, 4};
    obj->e[7] = (t_edge){1, 5};
    obj->e[8] = (t_edge){2, 3};
    obj->e[9] = (t_edge){3, 4};
    obj->e[10] = (t_edge){4, 5};
    obj->e[11] = (t_edge){5, 2};

	return obj;
}

int main() {
	init_context();
	launch_window(WIDTH, HEIGHT, "test");
	// mlx_key_hook(window(), keydown_event, &keys);
	mlx_hook(window(), 17, 0, quit_event, NULL);
	mlx_hook(window(), 2, 1 << 0, keydown_event, &upd_var.key);
	mlx_hook(window(), 3, 1 << 1, keyup_event, &upd_var.key);
	mlx_hook(window(), 4, 1 << 2, mousedown_event, NULL);

	printf("camera proj mat:\n");
	print_matrix(camera()->proj_mat);

	// img = new_image(1280, 960);
	upd_var.img = new_image(WIDTH, HEIGHT);
	upd_var.obj = new_obj_test();
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
