#include <iostream>
#include <vector>

using namespace std;

class Methods {
private:
    vector<char> square{ '0','1','2','3','4','5','6','7','8','9' };
    int turn = 0; // To keep track of turns

public:
    void playerChoose(const string& prompt) {
        char choice;
        cout << prompt;
        cin >> choice;

        // Update the square with player's choice
        if (choice >= '1' && choice <= '9') {
            int index = choice - '0'; // Convert char to int
            if (square[index] != 'X' && square[index] != 'O') {
                square[index] = (turn % 2 == 0) ? 'X' : 'O'; // 'X' for player 1, 'O' for player 2
                turn++;
            } else {
                cout << "Square already taken! Choose again.\n";
                playerChoose(prompt); // Recursive call to re-prompt for a valid choice
            }
        } else {
            cout << "Invalid choice! Please choose a number between 1 and 9.\n";
            playerChoose(prompt); 
        }
    }

    void display() {
        cout << "\n\n";
        for (int i = 1; i <= 9; i++) {
            cout << "\t" << square[i];
            if (i % 3 == 0)
                cout << "\n\n";
        }
    }

    bool checkWin() {
        // Check rows, columns, and diagonals for a win
        for (int i = 1; i <= 3; i++) {
            if (square[i * 3 - 2] == square[i * 3 - 1] && square[i * 3 - 1] == square[i * 3]) {
                cout << "Winner: " << square[i * 3 - 2] << "\n";
                return true;
            }
            if (square[i] == square[i + 3] && square[i + 3] == square[i + 6]) {
                cout << "Winner: " << square[i] << "\n";
                return true;
            }
        }
        if (square[1] == square[5] && square[5] == square[9]) {
            cout << "Winner: " << square[1] << "\n";
            return true;
        }
        if (square[3] == square[5] && square[5] == square[7]) {
            cout << "Winner: " << square[3] << "\n";
            return true;
        }
        return false;
    }
};
