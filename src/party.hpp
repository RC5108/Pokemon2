#ifndef PARTY_H
#define PARTY_H
#include <iostream>
#include <vector>
#include "pikachu.hpp"

class Party {
public:
	Party(vector<Pokemon> p) : team(p) {}

	Pokemon& getCurrent() {
		return team[currentPokemon];
	}
	void swapPokemon();
	
	// Function to replace pikachu with raichu in party
	// Will have to overload with different pokemon types 
	void replaceCurrentPokemon(Raichu r);
	


protected:
	vector<Pokemon> team;
	int currentPokemon = 0;
	int i;
};


#endif // PARTY_H