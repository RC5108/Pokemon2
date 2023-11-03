#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "move.hpp"
using namespace std;

class Pokemon {

public:
	Pokemon(string nIn, string tIn, int hpIn, int aIn, int dIn, int lvl = 1) :
		name(nIn), type(tIn), HP(hpIn), attack(aIn), defence(dIn) {
		buildMoves();
	};

	// Default constructor that assigns the default pokemon to Magikarp
	Pokemon() : name("Magikarp"), type("water"), HP(12), attack(10), defence(20), level(1) {
		buildMoves();
	};

	virtual ~Pokemon() {}

	// Accessors
	int getHP() { return HP; };
	int getDefence() { return defence; };
	int getAttack() { return attack; };
	int getLevel() { return level; };
	string getType() { return type; };
	string getName() { return name; };
	vector<Move>& getVector() { return listMoves; }


	// Mutators
	void setHP(int newHP) { HP = newHP; };
	void setDefence(int ac) { defence = ac; };
	void setAttack(int atk) { attack = atk; };
	void setName(string nm) { name = nm; }
	void setVector(vector<Move> nv) { listMoves = nv; }
	void performMove(Pokemon& p);
	void receiveDamage(int damage);
	void setLevel(int lvl) { level = lvl; }
	string setType(string tp);
	void buildMoves();

	// void method that displays pokemon's current stats to the player
	void displayStats();

private:
	string type;
	string name;
	int HP;
	int attack;
	int defence;
	vector<Move> listMoves;
	int level;
};


#endif // POKEMON_H
