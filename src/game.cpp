#include "game.h"

#include <iostream>

Projectile tick(Environment env, Projectile proj) {
    Tuple position = proj.position + proj.velocity;
    Tuple velocity = proj.velocity + env.gravity + env.wind;
    return Projectile{position, velocity};
}

void play() {
    Projectile p{Point(0, 1, 0), Vector(1, 1, 0).normalize()};
    Environment e{Vector(0, -0.1, 0), Vector(-0.01, 0, 0)};

    int ticks = 0;

    while (p.position.get_y() > 0) {
        std::cout << "Tick: " << ticks << "\n"
                  << "Position: "
                  << "x=" << p.position.get_x() << " y=" << p.position.get_y()
                  << " z=" << p.position.get_z() << std::endl;
        p = tick(e, p);
        ticks++;
    }
    std::cout << "Total ticks for y to be <=0: " << ticks << std::endl;
}