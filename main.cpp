#include <iostream>
#include <vector>
#include "src/prime.hpp"
using namespace std;

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Factorizer factorizer;
    int num;
    char choice;

    do {
        cout << "Enter a number to factorize: ";
        cin >> num;

        if (num <= 1) {
            cout << "[]" << endl;
        } else {
            vector<int> result = factorizer.prime(num);
            printVector(result);
        }

        cout << "Do you want to factorize another number? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
