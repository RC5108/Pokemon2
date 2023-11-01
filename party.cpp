#include "party.hpp"
#include "pokemon.hpp"
#include "pikachu.hpp"
#include "raichu.hpp"

void Party::swapPokemon() {
    cout << "Select a Pokemon to swap to: " << endl;
    for (i = 0; i < team.size(); i++) {
        if (i != currentPokemon) {
            cout << i + 1 << ". " << team[i].getName() << " HP: " << team[i].getHP() << endl;
        }
    }
    int choice;
    cin >> choice;
    choice--;
    if (choice >= 0 && choice < team.size() && choice != currentPokemon && team[choice].getHP() > 0) {
        currentPokemon = choice;
        cout << "Go " << team[currentPokemon].getName() << "!" << endl;
    }
    else {
        cout << "Invalid choice." << endl;
    }
}

void Party::replaceCurrentPokemon(Raichu r) {

}