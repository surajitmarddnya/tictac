#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

int checkwin(); // FUNCTION FOR RESULT
void board(); // FUNCTION TO DRAW THE BOARD
void guide(); // FUNCTION FOR USER GUIDE

int main() {
    char ch[20];
    int j = 0, o = 0;
    char choice1;
    cout << "Enter the password within a trial period of 4 times:";

    while (o < 4) {
        for (j = 0; j < 8; j++) {
            ch[j] = cin.get();
            cout << "*";
        }
        ch[j] = '\0';
        if (strcmp(ch, "password") == 0) {
            cout << "\a\nACCESS GRANTED\n";
            break;
        } else {
            cout << "\a\nACCESS DENIED\n";
            o++;
        }
    }

    if (o >= 4) {
        cout << "\nYou have entered the wrong password 4 times";
        return -999;
    }

    int player = 1, i, choice, option;
    char mark;
    do {
        cout << "\n1. ENTER THE GAME\n2. USER GUIDE\n3. EXIT\n";
        cin >> option;
        switch (option) {
            case 1:
                do {
                    board();
                    player = (player % 2) ? 1 : 2;
                    cout << "Player " << player << ", enter a number:  ";
                    cin >> choice;
                    mark = (player == 1) ? 'X' : 'O';

                    if (choice == 1 && square[1] == '1')
                        square[1] = mark;
                    else if (choice == 2 && square[2] == '2')
                        square[2] = mark;
                    else if (choice == 3 && square[3] == '3')
                        square[3] = mark;
                    else if (choice == 4 && square[4] == '4')
                        square[4] = mark;
                    else if (choice == 5 && square[5] == '5')
                        square[5] = mark;
                    else if (choice == 6 && square[6] == '6')
                        square[6] = mark;
                    else if (choice == 7 && square[7] == '7')
                        square[7] = mark;
                    else if (choice == 8 && square[8] == '8')
                        square[8] = mark;
                    else if (choice == 9 && square[9] == '9')
                        square[9] = mark;
                    else {
                        cout << "Invalid move ";
                        player--;
                        cin.ignore().get();
                    }
                    i = checkwin();
                    player++;
                } while (i == -1);
                board();
                if (i == 1)
                    cout << "==>\aPlayer " << --player << " wins ";
                else
                    cout << "==>\aGame draw";
                break;

            case 2:
                guide();
                break;

            case 3:
                exit(0);
                break;

            default:
                cout << "Wrong Choice";
                break;
        }
        cout << "\nDo you want to continue? (y/n)";
        cin >> choice1;
    } while (choice1 == 'y' || choice1 == 'Y');

    return 0;
}

int checkwin() {
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}

void board() {
    system("CLS"); // Use system call to clear the screen (Windows-specific)
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)\n\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << "\n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << "\n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << "\n";
    cout << "\t\t     |     |     \n\n";
}

void guide() {
    system("CLS"); // Use system call to clear the screen (Windows-specific)
    cout << "\nThe TIC-TAC-TOE games board is similar to that of # key\nor it looks something like this:\n";
    cout << "\t\t\t    _|_|_\n";
    cout << "\t\t\t    _|_|_\n";
    cout << "\t\t\t     | |  \n";
    cout << "\nIn this gaps turn by turn crosses and zeroes have to be filled up";
    cout << "\nTIC-TAC-TOE is basically a X and O game in which the player has to complete 3 crosses or zeroes which may be horizontal, vertical or even diagonal\n";
    cout << "Example patterns:\n";
    cout << "Horizontal: x|x|x\n";
    cout << "Vertical:   x\n           x\n           x\n";
    cout << "Diagonal: x\n            x\n             x\n";
}
