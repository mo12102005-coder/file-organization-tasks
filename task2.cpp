// Task 1: Save a student's full name, ID and grade in Student.txt.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string name;
    int id;
    float grade;
    cout << "Full name: ";
    getline(cin, name);
    cout << "ID: ";
    cin >> id;
    cout << "Grade: ";
    cin >> grade;
    if (!cin) return 1;
    ofstream file("Student.txt");
    if (!file) {
        cerr << "Cannot open Student.txt\n";
        return 1;
    }
    file << "Name: " << name << '\n';
    file << "ID: " << id << '\n';
    file << "Grade: " << grade << '\n';
    cout << "Data saved in Student.txt\n";
    return 0;
}
