
/* Tic-Tac-Toe Project
Character vector<
square>
Gary Luechtefeld
*/
#include <iostream> // Enable Input - Output
#include<string>
#include<vector>
#include <iomanip> // Enable Input - Output manipulations
#include <fstream> //library needed for printing output
#include"Methods.h"
void Display(); // Display function header
void playerChoose(std::string);
void win(void);
int j = 1;
using namespace std; // Using standard header names
int main() {
    Methods game1;
    Methods game2;

    while (true) {
        cout << "\nRound 1\n";
        game1.display();
        game1.playerChoose("\n\tPlease choose a square (1-9): ");

        if (game1.checkWin()) {
            game1.display();
            break;
        }
        
        /*// Check if all squares are filled
        if (game.getTurnCount() >= 9) {
            cout << "It's a draw!\n";
            game.display();
            break;
        }*/
    }

    while (true) {
        cout << "\nRound 2:\n";
        game2.display();
        game2.playerChoose("\n\tPlease choose a square (1-9): ");

        if (game2.checkWin()) {
            game2.display();
            break;
        }
    }

    return 0;
}
