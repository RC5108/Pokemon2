#ifndef PIKACHU_H
#define PIKACHU_H
#include "pokemon.hpp"
#include "raichu.hpp"

class Pikachu : public Pokemon {
public:
	// Name will always be Pikachu
	// Type will always be electric
	Pikachu(int hp, int att, int def, int lev) :
		Pokemon("Pikachu", "Electric", hp, att, def, lev) {
		buildMoves();
	};
	Pikachu() : Pokemon("Pikachu", "Electric", 20, 10, 10), level(0) {
		buildMoves();
	};

	void gainExp(int ep);
	void levelUp();
	Raichu* evolve();
	bool checkEvolution();

protected:
	bool isEvolved = false;
	int level; 
	int exp = 0;
	int levelUpXp = 100;
};

#endif // PIKACHU_H
