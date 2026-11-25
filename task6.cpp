// Task 6: Manage grades stored in grades.txt
// 1) create the file with five integer grades
// 2) read and print them with a correct reading loop
// 3) ask for a grade to delete and write the rest to a temporary file
// 4) replace the original file and show a success or error message
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main() {
    // 1) Create grades.txt and write five integer grades
    ofstream out("grades.txt");
    if (!out) {
        cout << "Error: cannot create grades.txt" << endl;
        return 1;
    }
    int initial[5] = {85, 90, 70, 95, 60};
    for (int i = 0; i < 5; i++) {
        out << initial[i] << endl;
    }
    out.close();

    // 2) Read and print the grades (loop condition is the read itself)
    ifstream in("grades.txt");
    if (!in) {
        cout << "Error: cannot open grades.txt" << endl;
        return 1;
    }
    cout << "Grades in file (before deletion):" << endl;
    int g;
    while (in >> g) {
        cout << g << endl;
    }
    in.close();

    // 3) Ask for a grade to delete and copy the others to a temporary file
    int target;
    cout << "Enter the grade to delete: ";
    cin >> target;

    in.open("grades.txt");
    ofstream temp("temp.txt");
    if (!in || !temp) {
        cout << "Error: cannot open files" << endl;
        return 1;
    }
    bool found = false;
    while (in >> g) {
        if (g == target) {
            found = true;           // skip this grade
        } else {
            temp << g << endl;
        }
    }
    in.close();
    temp.close();

    // 4) Replace the original file and show a message
    if (!found) {
        remove("temp.txt");
        cout << "Error: grade " << target << " was not found. File unchanged." << endl;
        return 1;
    }
    if (remove("grades.txt") != 0 || rename("temp.txt", "grades.txt") != 0) {
        cout << "Error: could not replace the original file." << endl;
        return 1;
    }
    cout << "Success: grade " << target << " deleted." << endl;

    // Show the file after deletion
    in.open("grades.txt");
    cout << "Grades in file (after deletion):" << endl;
    while (in >> g) {
        cout << g << endl;
    }
    return 0;
}
