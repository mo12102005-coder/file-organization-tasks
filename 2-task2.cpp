// Task 2: Read fruit.txt, then append a message without losing its contents.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream input("fruit.txt");
    if (!input) {
        cerr << "Create fruit.txt with a fruit list before running.\n";
        return 1;
    }
    string line;
    while (getline(input, line)) {
        cout << line << '\n';
    }
    // Check the final character so the message always starts on a new line.
    input.clear();
    input.seekg(0, ios::end);
    bool needsNewline = false;
    if (input.tellg() > 0) {
        input.seekg(-1, ios::end);
        char last;
        input.get(last);
        needsNewline = last != '\n';
    }
    input.close();
    ofstream output("fruit.txt", ios::app);
    if (!output) {
        cerr << "Cannot write to fruit.txt\n";
        return 1;
    }
    if (needsNewline) output << '\n';
    output << "Fresh Fruits\n";
    return 0;
}
