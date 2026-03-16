//Homework 4
//Question 1

#include <iostream>

using namespace std;

void getNumbers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter non-negative integer #" << i + 1 << ": ";
        cin >> arr[i];
    }
}

int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void makeHistogram(int arr[], int size, int bins[], int numBins) {
    for (int i = 0; i < numBins; i++) {
        bins[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int binIndex = arr[i] / 10;
        bins[binIndex]++;
    }
}

void printHistogram(int bins[], int numBins) {
    cout << "\nHistogram:\n";
    for (int i = 0; i < numBins; i++) {
        int start = i*10;
        int end = start + 9;
        cout << start << " - " << end << ": " << bins[i] << endl;
    }
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int arr[100];
    getNumbers(arr, size);

    int maxVal = findMax(arr, size);
    int numBins = maxVal / 10 + 1;

    int bins[100];
    makeHistogram(arr, size, bins, numBins);
    printHistogram(bins, numBins);

    return 0;
}