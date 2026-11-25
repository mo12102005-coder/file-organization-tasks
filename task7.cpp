// Task 7: Sort student names in ascending (A to Z) order.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> names = {
        "Hadeer Mahmoud",
        "Youssef Ali",
        "Ahmed Mostafa",
        "Esraa Ebrahim"
    };

    cout << "Before sorting:\n";
    for (size_t i = 0; i < names.size(); i++) {
        cout << names[i] << '\n';
    }

    // Sort the names from A to Z
    sort(names.begin(), names.end());

    cout << "\nAfter sorting (ascending):\n";
    for (size_t i = 0; i < names.size(); i++) {
        cout << names[i] << '\n';
    }
    return 0;
}
