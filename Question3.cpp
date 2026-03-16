//Homework 4
//Question 3

#include <iostream>

using namespace std;

const int ROWS = 10;
const int COLS = 4;

void initializeSeats(char seats[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        seats[i][0] = 'A';
        seats[i][1] = 'B';
        seats[i][2] = 'C';
        seats[i][3] = 'D';
    }

    seats[0][1] = 'X';
    seats[2][3] = 'X';
    seats[4][0] = 'X';
}

void displaySeats(char seats[][COLS]) {
    cout << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << i + 1 <<  " ";
        for (int j = 0; j < COLS; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int seatLetterToIndex(char seatLetter) {
    if (seatLetter == 'A') return 0;
    if (seatLetter == 'B') return 1;
    if (seatLetter == 'C') return 2;
    if (seatLetter == 'D') return 3;
    return -1;
}

bool isAvailable(char seats[][COLS], int row, char seatLetter) {
    int col = seatLetterToIndex(seatLetter);
    if (row < 1 || row > 10 || col == -1) {
        return false;
    }
    return seats[row-1][col] != 'X';
}

void assignSeat(char seats[][COLS], int row, char seatLetter) {
    int col = seatLetterToIndex(seatLetter);
    seats[row-1][col] = 'X';
}

bool allSeatsTaken(char seats[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j] != 'X') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char seats[ROWS][COLS];
    initializeSeats(seats);

    char again = 'y';

    while ((again == 'y' || again == 'Y') && !allSeatsTaken(seats)) {
        displaySeats(seats);

        int row;
        char seatLetter;
        
        do {
            cout << "Enter desired row number: ";
            cin >> row;
            cout << "Enter desired seat letter (A-D): ";
            cin >> seatLetter;

            if (seatLetter >= 'a' && seatLetter <= 'd') {
                seatLetter = seatLetter - 'a' + 'A';
            }

            if (!isAvailable(seats, row, seatLetter)) {
                cout << "Seat not available. Please choose another seat.\n";
            }
        } while (!isAvailable(seats, row, seatLetter));

        assignSeat(seats, row, seatLetter);
        displaySeats(seats);

        if (!allSeatsTaken(seats)) {
            cout << "Do you want to add another seat? (y/n): ";
            cin >> again;
        }
    }

    if (allSeatsTaken(seats)) {
        cout << "All seats are taken.\n";
    }
}