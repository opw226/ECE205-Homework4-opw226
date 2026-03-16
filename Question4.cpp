//Homework 4
//Question 4

#include <iostream>

using namespace std;

void initializeBoard(char board[]) {
    for (int i = 0; i < 9; i++) {
        board[i] = '1' + i;
    }
}

void displayBoard(char board[]) {
    cout << endl;
    cout << board[0] << " " << board[1] << " " << board[2] << endl;
    cout << board[3] << " " << board[4] << " " << board[5] << endl;
    cout << board[6] << " " << board[7] << " " << board[8] << endl;
    cout << endl;
}

bool validMove(char board[], int pos) {
    if (pos < 1 || pos > 9) {
        return false;
    }

    if (board[pos-1] == 'X' || board[pos-1] == 'O') {
        return false;
    }
    return true;
}

void makeMove(char board[], int pos, char player) {
    board[pos-1] = player;
}

bool checkWinner(char board[], char player) {
    if (board[0] == player && board[1] == player && board[2] == player) return true;
    if (board[3] == player && board[4] == player && board[5] == player) return true;
    if (board[6] == player && board[7] == player && board[8] == player) return true;

    if (board[0] == player && board[3] == player && board[6] == player) return true;
    if (board[1] == player && board[4] == player && board[7] == player) return true;
    if (board[2] == player && board[5] == player && board[8] == player) return true;

    if (board[0] == player && board[4] == player && board[8] == player) return true;
    if (board[2] == player && board[4] == player && board[6] == player) return true;

    return false;
}

bool boardFull(char board[]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false;
        }
    }
    return true;
}

int main() {
    char board[9];
    initializeBoard(board);

    char player = 'X';
    int pos;

    while (true) {
        displayBoard(board);

        do {
            cout << "Player " << player << ", enter a position (1-9): ";
            cin >> pos;

            if (!validMove(board, pos)) {
                cout << "Invalid move. Try again.\n";
            }
        } while (!validMove(board, pos));

        makeMove(board, pos, player);
        displayBoard(board);

        if (checkWinner(board, player)) {
            cout << "Player " << player << " wins!\n";
            break;
        }

        if (boardFull(board)) {
            cout << "Game is a tie.\n";
            break;
        }

        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }

    }
    return 0;
}