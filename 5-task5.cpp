// Task 5 (Lab 2): Append student records separated by $ to students.txt.
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

struct Student {
    char name[20];
    int id;
    float grade;
    char delim;
};

int main() {
    ofstream file("students.txt", ios::app);
    if (!file) {
        cerr << "Cannot open students.txt\n";
        return 1;
    }
    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        Student student;
        cout << "Name (up to 19 characters): ";
        cin.getline(student.name, 20);
        if (!cin) {
            cerr << "Name is too long.\n";
            return 1;
        }
        cout << "ID: ";
        cin >> student.id;
        cout << "Grade: ";
        cin >> student.grade;
        if (!cin) return 1;
        student.delim = '$';
        file << student.name << ", " << student.id << ", "
             << student.grade << ' ' << student.delim << '\n';
        do {
            cout << "Add another record? (y/n): ";
            if (!(cin >> choice)) return 1;
        } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}
