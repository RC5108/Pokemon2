#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

class Move {
public:
	// Default constructor
	Move() : name("Tackle"), type("Normal"), damage(5) {};
	Move(string nIn, string tIn, int dmg) : name(nIn), type(tIn), damage(dmg) {};

	// Accessors
	string getName() { return name; };
	string getType() { return type; };
	int getDamage() { return damage; };

	// Mutators
	void setName(string nm) { name = nm; };
	void setType(string ty) { type = ty; };
	int calculateDamage(int attack, int tDefence);



private:
	string name;
	string type;
	int damage;
	string targetType;

};




#endif // MOVE_H
