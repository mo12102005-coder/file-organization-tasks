// Task 3: Replace body with one and save the result in welcome.txt.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream original("welcome.txt");
    if (!original) return 1;
    original << "Hello Everybody";
    original.close();

    ifstream input("welcome.txt");
    if (!input) return 1;
    string sentence;
    getline(input, sentence);
    input.close();
    size_t position = sentence.find("body");
    if (position != string::npos) sentence.replace(position, 4, "one");

    // Truncation removes the old final character when the new text is shorter.
    ofstream output("welcome.txt", ios::trunc);
    if (!output) return 1;
    output << sentence;
    cout << sentence << '\n';
    return 0;
}
