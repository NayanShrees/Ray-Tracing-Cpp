#include "game.h"

#include <math.h>

#include <iostream>

#include "canvas.h"
#include "data_structures/color.h"

Projectile tick(Environment env, Projectile proj) {
    Tuple position = proj.position + proj.velocity;
    Tuple velocity = proj.velocity + env.gravity + env.wind;
    return Projectile{position, velocity};
}

void play() {
    Canvas canvas(900, 550);
    Color color(1, 0.8, 0.6);
    Projectile p{Point(0, 1, 0), Vector(1, 1.8, 0).normalize() * 11.25};
    Environment e{Vector(0, -0.1, 0), Vector(-0.01, 0, 0)};

    int ticks = 0;

    while (p.position.get_y() > 0) {
        if (0 < p.position.get_y() && p.position.get_y() <= canvas.height &&
            0 < p.position.get_x() && p.position.get_x() <= canvas.width) {
            canvas.pixels[(int)round(canvas.height - p.position.get_y())]
                         [(int)round(p.position.get_x())] = color;
        }
        p = tick(e, p);
        ticks++;
    }
    canvas.save_ppm();
}