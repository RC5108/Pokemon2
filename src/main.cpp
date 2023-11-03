/*
 * Marc Baldwin & Miles Kent
 * Lab 2
 * Program that uses class Pokemon to simulate a basic pokemon battle
 */

#include "pokemon.hpp"
#include "party.hpp"
#include "pikachu.hpp"
#include "raichu.hpp"
#include <iostream>

using namespace std;

int main() {
	
	srand(time(NULL));
    Party userParty({
        Pokemon("Bulbasaur", "Grass", 100, 20, 20),
        Pokemon("Charmander", "Fire", 100, 20, 20),
        Pokemon("Squirtle", "Water", 100, 20, 20),
        Pikachu(100, 20, 20, 19),
        Pokemon("Jigglypuff", "Normal", 100, 20, 20),
        Pokemon("Meowth", "Normal", 100, 20, 20)
        });
    Party enemyParty({
        Pokemon("Pidgey", "Normal", 100, 20, 20),
        Pokemon("Rattata", "Normal", 100, 20, 20),
        Pokemon("Spearow", "Normal", 100, 20, 20),
        Pikachu(100, 20, 20, 19),
        Pokemon("Zubat", "Poison", 100, 20, 20),
        Pokemon("Caterpie", "Bug", 100, 20, 20)
        });

    while (true) {
        cout << "Enemy encountered! Defeat them to advance!" << endl;
        cout << "Your turn! Current Pokemon: " << userParty.getCurrent().getName() << endl;
        cout << "1. Attack" << endl;
        cout << "2. Switch Pokemon" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            // User attacks
            int initialHP = enemyParty.getCurrent().getHP();
            userParty.getCurrent().performMove(enemyParty.getCurrent());

            // Check if the enemy got hit
            if (initialHP > enemyParty.getCurrent().getHP()) {
                Pokemon* currentPokemon = &userParty.getCurrent();
                Pikachu* pikachu = dynamic_cast<Pikachu*>(currentPokemon);
                if (pikachu != nullptr) {
                    // Successfully casted to Pikachu
                    pikachu->levelUp();
                    cout << "Pikachu has leveled up!" << endl;

                    // Check for evolution
                    if (Raichu* raichu = pikachu->evolve()) {
                        userParty.replaceCurrentPokemon(*raichu);
                        cout << "Pikachu has evolved into Raichu!" << endl;
                    }
                }
                else {
                    cout << "The current Pokemon is not a Pikachu." << endl;
                }
            }
        }
        else if (choice == 2) {
            // Switch Pokemon
            userParty.swapPokemon();
        }
        else {
            cout << "Invalid choice." << endl;
            continue;
        }

        // Check if the AI's current Pokemon has fainted
        if (enemyParty.getCurrent().getHP() <= 0) {
            cout << enemyParty.getCurrent().getName() << " has fainted!" << endl;
            // In a real game, you would check for other Pokemon in the AI's team to switch to
            cout << "You win!" << endl;
            break;
        }

        // AI's turn
        cout << "AI's turn!" << endl;
        enemyParty.getCurrent().performMove(userParty.getCurrent());

        // Check if the user's current Pokemon has fainted
        if (userParty.getCurrent().getHP() <= 0) {
            cout << userParty.getCurrent().getName() << " has fainted!" << endl;
            cout << "You lose!" << endl;
            break;
        }
    }
	return 0;
}
