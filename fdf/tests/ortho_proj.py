
import numpy as np
import pygame as pg
import time
from math import degrees, radians, pi, sin, cos, tan
pg.init()
np.set_printoptions(precision=2, suppress=True)

def vec(*args):
    return np.array(args, dtype=float)

WIDTH, HEIGHT = 800, 600

SCALE = 100

LEFT, RIGHT = -10, 10
# BOTTOM, TOP = 0, 6
BOTTOM, TOP = -7.5, 7.5
# LEFT, RIGHT = 0, 1
# TOP, BOTTOM = 0, 1
# BOTTOM, TOP = 0, WIDTH/SCALE
NEAR, FAR = 0.1, 1000


def get_qt(theta, v):
    _a = np.cos(theta/2)
    _b, _c, _d, *_ = np.sin(theta/2) * v
    _q = np.array((_a, _b, _c, _d))
    mag = np.sqrt(np.sum(_q * _q))
    return _q / mag

def get_rot_mat(r, i, j, k):
    # return np.array([
    #     [1 - 2*(j**2 + k**2), 2*(i*j - k*r), 2*(i*k + j*r)],
    #     [2*(i*j + k*r), 1 - 2*(i**2 + k**2), 2*(j*k - i*r)],
    #     [2*(i*k-j*r), 2*(j*k + i*r), 1 - 2*(i**2 + j**2)]
    # ])
    return np.array([
        [1 - 2*(j**2 + k**2), 2*(i*j - k*r), 2*(i*k + j*r), 0],
        [2*(i*j + k*r), 1 - 2*(i**2 + k**2), 2*(j*k - i*r), 0],
        [2*(i*k-j*r), 2*(j*k + i*r), 1 - 2*(i**2 + j**2), 0],
        [0, 0, 0, 1],
    ])

#  make 0 ~ 1
# proj2 = np.array([
#     [1/(RIGHT-LEFT), 0, 0, -LEFT/(RIGHT-LEFT)],
#     [0, 1/(TOP-BOTTOM), 0, -BOTTOM/(TOP-BOTTOM)],
#     [0, 0, 1/(FAR-NEAR), -NEAR/(FAR-NEAR)],
#     [0, 0, 0, 1],
# ])

# translate = np.array([
#     [1, 0, 0, -(LEFT+RIGHT)/2],
#     [0, 1, 0, -(BOTTOM+TOP)/2],
#     [0, 0, 1, -(NEAR+FAR)/2],
#     [0, 0, 0, 1],
# ])
# rescale = np.array([
#     [2/(RIGHT-LEFT), 0, 0, 0],
#     [0, 2/(TOP-BOTTOM), 0, 0],
#     [0, 0, 2/(FAR-NEAR), 0],
#     [0, 0, 0, 1],
# ])
proj3 = np.array([
    [2/(RIGHT-LEFT), 0, 0, (LEFT+RIGHT)/(LEFT-RIGHT)],
    [0, 2/(TOP-BOTTOM), 0, (BOTTOM+TOP)/(BOTTOM-TOP)],
    [0, 0, 2/(FAR-NEAR), (NEAR+FAR)/(NEAR-FAR)],
    [0, 0, 0, 1],
])

# p = vec(1, 1, 3.4641, 1)
# p = vec(1, 1, 3.4641, 1)
# print(p3)
# proj_mat = np.dot(rescale, translate)
proj_mat = proj3
# print(proj_mat)
# proj_mat = proj2
# print(proj2)
# print(np.dot(proj_mat, p))

fov = 60
f = 1 / np.tan(radians(fov / 2))
# f = np.tan(radians(fov / 2))

# normalize = np.array([
#     [NEAR, 0, (LEFT+RIGHT)/(LEFT-RIGHT), 0],
#     [0, NEAR, (BOTTOM+TOP)/(BOTTOM-TOP), 0],
#     [0, 0, (NEAR+FAR)/(NEAR-FAR), (2*NEAR*FAR)/(NEAR-FAR)],
#     [0, 0, -1, 0],
# ])
# rescale = np.array([
#     [2/(RIGHT-LEFT), 0, 0, 0],
#     [0, 2/(TOP-BOTTOM), 0, 0],
#     [0, 0, 1, 0],
#     [0, 0, 0, 1],
# ])

a = HEIGHT/WIDTH
q = FAR/(FAR-NEAR)
perspective_mat = np.array([
    [a*f, 0, 0, 0],
    [0, f, 0, 0],
    [0, 0, q, -q*NEAR],
    [0, 0, 1, 0],
])

def proj_perspect(vt):
    out = np.dot(perspective_mat, vt)
    if abs(out[3]) > 1e-7:
        out /= out[3]
    return out

def proj_ortho(vt):
    return np.dot(proj3, vt)

cur_proj = 1
camera_projection = proj_perspect if cur_proj else proj_ortho

# p1 = p
# p1 = np.dot(perspective_proj, p)
# print(p1)
# p2 = p1 / p1[3]
# print(p2)

# quit()
# rescale = np.array([
#     [2/(RIGHT-LEFT), 0, 0, 0],
#     [0, 2/(TOP-BOTTOM), 0, 0],
#     [0, 0, 2/(FAR-NEAR), 0],
#     [0, 0, 0, 1],
# ])

camera_pos = vec(0, 0, 0, 1)
camera_rotate = np.array([
    [1, 0, 0, 0],
    [0, 1, 0, 0],
    [0, 0, 1, 0],
    [0, 0, 0, 1],
], dtype=float)


p = vec(0, 0, 10, 1)
print(p)
p1 = np.dot(camera_rotate, p)
print(p1)

def camera_transform(vt):
    return np.dot(camera_rotate, vt - camera_pos)

# quit()

def rotate_camera(angle, axis):
    global camera_rotate
    rot = get_rot_mat(*get_qt(angle, axis))
    camera_rotate = np.dot(camera_rotate, rot)


# quit()

# proj_mat = np.array([
#     [2/(RIGHT-LEFT), 0, (RIGHT+LEFT)/(RIGHT-LEFT), 0],
#     [0, 2/(TOP-BOTTOM), (TOP+BOTTOM)/(TOP-BOTTOM), 0],
#     [0, 0, 1/(FAR-NEAR), -NEAR/(FAR-NEAR)],
#     [0, 0, 0, 1],
# ]).T







class Key:
    q = False
    e = False
    a = False
    d = False
    w = False
    s = False
    up = False
    down = False
    left = False
    right = False
    space = False
    lshift = False
    i = False
    j = False
    k = False
    l = False
    u = False
    o = False

keymap = {
    pg.K_w: 'w',
    pg.K_a: 'a',
    pg.K_s: 's',
    pg.K_d: 'd',
    pg.K_q: 'q',
    pg.K_e: 'e',
    pg.K_UP: 'up',
    pg.K_DOWN: 'down',
    pg.K_LEFT: 'left',
    pg.K_RIGHT: 'right',
    pg.K_SPACE: 'space',
    pg.K_LSHIFT: 'lshift',
    pg.K_i: 'i',
    pg.K_j: 'j',
    pg.K_k: 'k',
    pg.K_l: 'l',
    pg.K_u: 'u',
    pg.K_o: 'o',
}




class Obj:
    def __init__(self, vts, edges, center=None) -> None:
        self.vts = np.array(vts)
        self.edges = edges
        self.center = center
        if center is None:
            self.center = vec(0, 0, 10, 1)
        self.rot = np.array([
            [1, 0, 0, 0],
            [0, 1, 0, 0],
            [0, 0, 1, 0],
            [0, 0, 0, 1],
        ], dtype=float)

    def rotate(self, axis, angle):
        q = get_qt(angle, axis)
        rot = get_rot_mat(*q)
        # self.rot = np.dot(self.rot, rot)
        self.vts = np.dot(self.vts, rot)

    def get_vts(self):
        return self.center + self.vts
        # return self.center + np.dot(self.vts, self.rot)

    def get_edges(self):
        for s, e in self.edges:
            yield self.center + self.vts[s], self.center + self.vts[e]

class EularObj(Obj):
    def __init__(self, center=None) -> None:
        super().__init__([
            vec(0, 0, 0, 0),
            vec(0, 0, 0, 1),
            vec(1, 0, 0, 1),
            vec(0, 1, 0, 1),
            vec(0, 0, 1, 1),
        ],
        [
            (0, 1),
            (2, 1),
            (3, 1),
            (4, 1),
        ], center)
        self.theta = radians(90)
        self.phi = radians(90)
        self.set_p()

    def set_p(self):
        self.vts[0][0] = sin(self.theta)*cos(self.phi)
        self.vts[0][2] = sin(self.theta)*sin(self.phi)
        self.vts[0][1] = cos(self.theta)

    def rot_theta(self, diff):
        self.theta += diff
        self.set_p()
    def rot_phi(self, diff):
        self.phi += diff
        self.set_p()



SIZE = 2
rect1 = Obj(
    [
        vec(SIZE, 0, 0, 0),
        vec(-SIZE, 0, 0, 0),
        vec(0, SIZE, 0, 0),
        vec(0, 0, SIZE, 0),
        vec(0, -SIZE, 0, 0),
        vec(0, 0, -SIZE, 0),
    ],
    [
        (0, 2),
        (0, 3),
        (0, 4),
        (0, 5),
        (1, 2),
        (1, 3),
        (1, 4),
        (1, 5),
        (2, 3),
        (3, 4),
        (4, 5),
        (5, 2),
    ],
    p
)
rect2 = Obj(
    [
        vec(SIZE, SIZE, -SIZE, 0),
        vec(SIZE, -SIZE, -SIZE, 0),
        vec(-SIZE, -SIZE, -SIZE, 0),
        vec(-SIZE, SIZE, -SIZE, 0),
        vec(SIZE, SIZE, SIZE, 0),
        vec(SIZE, -SIZE, SIZE, 0),
        vec(-SIZE, -SIZE, SIZE, 0),
        vec(-SIZE, SIZE, SIZE, 0),
    ],
    [
        (0, 1),
        (1, 2),
        (2, 3),
        (3, 0),
        (4, 5),
        (5, 6),
        (6, 7),
        (7, 4),
        (0, 4),
        (1, 5),
        (2, 6),
        (3, 7),
    ],
    p
)
rect3 = EularObj(p)

rect = rect2



print(p)
print(proj_mat)
print(np.dot(proj_mat, p))

def rescale_cam(scr_pos):
    return (scr_pos[0] + 1)/2 * WIDTH, (-scr_pos[1] + 1)/2 * HEIGHT
def to_screen(vt):
    rel_pos = camera_transform(vt)
    scr_pos = camera_projection(rel_pos)
    return rescale_cam(scr_pos)



BG_COLOR = (43, 43, 43)
scr = pg.display.set_mode((800, 600))
running = True
clock = pg.time.Clock()

speed = 0.1
rot_speed = 2
cam_speed = 0.05
cam_rot_speed = 1

tt = 0
cnt = 0
while running:
    st_t = time.time()
    cnt += 1
    for event in pg.event.get():
        if event.type == pg.QUIT:
            running = False

        elif event.type == pg.KEYDOWN:
            if event.key in keymap:
                setattr(Key, keymap[event.key], True)
            elif event.key == pg.K_RETURN:
                print(p)
            elif event.key == pg.K_TAB:
                cur_proj = 1 - cur_proj
                if cur_proj:
                    camera_projection = proj_perspect
                else:
                    camera_projection = proj_ortho

        elif event.type == pg.KEYUP:
            if event.key in keymap:
                setattr(Key, keymap[event.key], False)

    if Key.up:
        p[1] += speed
    if Key.down:
        p[1] -= speed
    if Key.right:
        p[0] += speed
    if Key.left:
        p[0] -= speed
    if Key.space:
        p[2] += speed
    if Key.lshift:
        p[2] -= speed

    if Key.w:
        rect.rotate(vec(1, 0, 0), -radians(rot_speed))
    if Key.s:
        rect.rotate(vec(1, 0, 0), radians(rot_speed))
    if Key.a:
        rect.rotate(vec(0, 1, 0), -radians(rot_speed))
    if Key.d:
        rect.rotate(vec(0, 1, 0), radians(rot_speed))
    if Key.q:
        rect.rotate(vec(0, 0, 1), -radians(rot_speed))
    if Key.e:
        rect.rotate(vec(0, 0, 1), radians(rot_speed))

    # if Key.i:
    #     # camera_pos[1] += cam_speed
    #     rect.rot_theta(-radians(cam_rot_speed))
    # if Key.k:
    #     # camera_pos[1] -= cam_speed
    #     rect.rot_theta(radians(cam_rot_speed))
    # if Key.j:
    #     # camera_pos[0] -= cam_speed
    #     rect.rot_phi(radians(cam_rot_speed))
    # if Key.l:
    #     # camera_pos[0] += cam_speed
    #     rect.rot_phi(-radians(cam_rot_speed))

    if Key.u:
        rotate_camera(radians(cam_rot_speed), vec(0, 1, 0))
    if Key.o:
        rotate_camera(-radians(cam_rot_speed), vec(0, 1, 0))


    scr.fill(BG_COLOR)

    for pp in rect.get_vts():
        pg.draw.circle(scr, (255, 0, 0), to_screen(pp), 3)
    for sp, ep in rect.get_edges():
        pg.draw.line(scr, (255, 0, 0), to_screen(sp), to_screen(ep))

    # scr_pos = np.dot(proj_mat, p)
    # scr_pos = camera_projection(p)
    scr_pos = camera_projection(camera_transform(p))
    x, y = rescale_cam(scr_pos)


    pg.draw.circle(scr, (0, 255, 255), (x, y), 3)

    pg.display.flip()
    ed_t = time.time()
    tt += ed_t - st_t
    if cnt >= 60:
        print(p, scr_pos, cnt, tt)
        pg.display.set_caption(f'fps: {cnt/tt:.2f}')
        tt = 0
        cnt = 0
    clock.tick(60)

