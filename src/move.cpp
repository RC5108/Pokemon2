#include "move.hpp"

int Move::calculateDamage(int att, int tDef)
{
	int moveDmg = getDamage();

	// Damage multipler depending on opponenets type
	double typeEffective = 1.0;

	if (type == "Water") {
		if (targetType == "Fire" || targetType == "Fire/Water") {
			typeEffective = 2.0; // Super effective against Fire
		}
		else if (targetType == "Water") {
			typeEffective = 0.5;
		}
	}
	else if (type == "Grass") {
		if (targetType == "Water" || targetType == "Water/Grass") {
			typeEffective = 2.0; // Super effective against Water
		}
		else if (targetType == "Grass") {
			typeEffective = 0.5;
		}
	}
	else if (type == "Fire") {
		if (targetType == "Grass" || targetType == "Grass/Fire") {
			typeEffective = 2.0; // Super effective against Grass
		}
		else if (targetType == "Fire") {
			typeEffective = 0.5;
		}
	}

	int calcDmg = static_cast<int>((moveDmg + att) * typeEffective - tDef);
	return max(calcDmg, 0);

}
