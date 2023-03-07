#ifndef GAME_H_
#define GAME_H_

#include "data_structures/tuples.h"

struct Projectile {
    Tuple position;
    Tuple velocity;
};

struct Environment {
    Tuple gravity;
    Tuple wind;
};

Projectile tick(Environment env, Projectile proj);

void play();

#endif  // GAME_H_