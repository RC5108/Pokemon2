#include "raichu.hpp"
#include <iostream>
using namespace std;

// Contructors utilize Pikachu's constructor since Raichu is evolve from Pikachu
Raichu::Raichu(int hp, int atk, int def, int lvl) : Pokemon("Raichu", "Electric", hp, atk, def) {
    buildMoves();
    setLevel(lvl);
}

Raichu::Raichu() : Pokemon("Raichu", "Electric", 60, 90, 55) {
    buildMoves();
    setLevel(1);
}

void Raichu::thunderShock(Pokemon& target) {
    cout << getName() << " used Thunder Shock!" << endl;
    int damage = (getAttack() * 2) - target.getDefence();
    if (damage < 0) damage = 0;
    target.receiveDamage(damage);
    cout << target.getName() << " received " << damage << " damage." << endl;
}
