#ifndef RAICHU_H
#define RAICHU_H

#include "pokemon.hpp"

class Raichu : public Pokemon {
public:
    Raichu(int hp, int atk, int def, int level);
    Raichu();
    void thunderShock(Pokemon& target);
};

#endif // RAICHU_H

