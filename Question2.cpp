//Homework4
//Question 2

#include <iostream>

using namespace std;

double getDifficulty() {
    double difficulty;
    do {
        cout << "Enter degree of difficulty (1.2 to 3.8): ";
        cin >> difficulty;
    } while (difficulty < 1.2 || difficulty > 3.8);
    return difficulty;
}

void getScores(double scores[], int size) {
    for (int i = 0; i < size; i++) {
        do {
            cout << "Enter judge score #" << i + 1 << " (0 to 10): ";
            cin >> scores[i];
        } while (scores[i] < 0 || scores[i] > 10);
    }
}

double findLowest(double scores[], int size) {
    double low = scores[0];
    for (int i = 0; i < size; i++) {
        if (scores[i] < low) {
            low = scores[i];
        }
    }
    return low;
}

double findHighest(double scores[], int size) {
    double high = scores[0];
    for (int i = 1; i < size; i++) {
        if (scores[i] > high) {
            high = scores[i];
        }
    }
    return high;
}

double calcScore(double difficulty, double scores[], int size) {
    double low = findLowest(scores, size);
    double high = findHighest(scores, size);

    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }

    sum = sum - low - high;
    return sum * difficulty * 0.6;
}

int main() {
    const int SIZE = 7;
    double scores[SIZE];

    double difficulty = getDifficulty();
    getScores(scores, SIZE);

    double finalScore = calcScore(difficulty, scores, SIZE);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Final diver score: " << finalScore << endl;

    return 0;
}