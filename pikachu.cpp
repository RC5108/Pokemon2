#include "pikachu.hpp"
#include  "raichu.hpp"

void Pikachu::levelUp() {
    level++;
    exp = 0;
    levelUpXp *= 1.1;  // Increase the required experience for the next level
    cout << "Pikachu leveled up! It's now level " << level << "!" << endl;

    // Check for evolution
    if (level >= 20) {  // Assuming Pikachu evolves at level 20
        evolve();
    }
}

// Function to evolve Pikachu into Raichu
Raichu* Pikachu::evolve() {
    if (getLevel() >= 20) {
        // Return new Raichu object in place of Pikachu
        Raichu* raichu = new Raichu(getHP(), getAttack(), getDefence(), getLevel());
        return raichu;
    }
    return nullptr;
}

// Function to give experience to Pikachu to raise levels
void Pikachu::gainExp(int exp) {
    exp += exp;
    if (exp >= levelUpXp) {
        levelUp();
    }
}

// Check to see if Pikachu is the correct level to evolve
bool Pikachu::checkEvolution() {
    if (level >= 20 && !isEvolved) {
        return true;
    }
    return false;
}
