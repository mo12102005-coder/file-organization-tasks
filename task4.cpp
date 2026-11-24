// Task 4 (Lab 1): Store persons, load a vector, and find youngest/oldest.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int count;
    cout << "Number of persons: ";
    if (!(cin >> count) || count <= 0) {
        cerr << "Enter a positive number.\n";
        return 1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    ofstream output("persons.txt");
    if (!output) return 1;
    for (int i = 0; i < count; ++i) {
        Person person;
        cout << "Name: ";
        getline(cin, person.name);
        cout << "Age: ";
        if (!(cin >> person.age) || person.age < 0) return 1;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        output << person.name << '\n' << person.age << '\n';
    }
    output.close();

    ifstream input("persons.txt");
    if (!input) return 1;
    vector<Person> persons;
    Person person;
    while (getline(input, person.name) && input >> person.age) {
        input.ignore(numeric_limits<streamsize>::max(), '\n');
        persons.push_back(person);
    }
    input.close();
    if (persons.empty()) return 1;
    int youngest = persons[0].age;
    int oldest = persons[0].age;
    for (const Person &p : persons) {
        if (p.age < youngest) youngest = p.age;
        if (p.age > oldest) oldest = p.age;
    }
    ofstream results("results.txt");
    if (!results) return 1;
    results << "Youngest persons:\n";
    for (const Person &p : persons)
        if (p.age == youngest) results << p.name << ", " << p.age << '\n';
    results << "Oldest persons:\n";
    for (const Person &p : persons)
        if (p.age == oldest) results << p.name << ", " << p.age << '\n';
    cout << "Results saved in results.txt\n";
    return 0;
}
