#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Student.h"
using namespace std;

void showMenu() {
    cout << "\n===== Student Management System =====" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Show students" << endl;
    cout << "3. Delete student" << endl;
    cout << "4. Update student" << endl;
    cout << "5. Save to file" << endl;
    cout << "6. Load from file" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose: ";
}

void addStudent(vector<Student>& students) {
    int id;
    string name;
    int age;
    string department;

    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Department: ";
    getline(cin, department);

   // Student newStudent(id, name, age, department);
   // students.push_back(newStudent);
    
    students.emplace_back(id, name, age, department);
    cout << "Student added successfully." << endl;
}

void showStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students found." << endl;
    }
    else {
        for (const auto& student : students) {
            student.display();
        }
    }
}

void deleteStudent(vector<Student>& students) {
    if (students.empty()) {
        cout << "No students available." << endl;
        return;
    }

    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    bool found = false;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            students.erase(students.begin() + i);
            cout << "Student deleted successfully." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }
}

void updateStudent(vector<Student>& students) {
    if (students.empty()) {
        cout << "No students available." << endl;
        return;
    }

    int id;
    cout << "Enter ID to update: ";
    cin >> id;
    cin.ignore();

    bool found = false;

    for (auto& student : students) {
        if (student.getId() == id) {

            string name;
            int age;
            string department;

            cout << "Enter new Name: ";
            getline(cin, name);

            cout << "Enter new Age: ";
            cin >> age;
            cin.ignore();

            cout << "Enter new Department: ";
            getline(cin, department);

            student.setName(name);
            student.setAge(age);
            student.setDepartment(department);

            cout << "Student successfully updated." << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }
}

void saveToFile(const vector<Student>& students) {
    ofstream file("students.txt");

    if (!file) {
        cout << "File could not be opened." << endl;
        return;
    }

    for (const auto& student : students) {
        file << student.getId() << ", " << student.getName() << ", " << student.getAge() << ", " << student.getDepartment() << endl;
    }

    file.close();
    cout << "Students saved to file successfully." << endl;
}

void loadFromFile(vector<Student>& students) {
    ifstream file("students.txt");

    if (!file) {
        cout << "File could not be opened." << endl;
        return;
    }
    students.clear();
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, name, ageStr, department;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, ageStr, ',');
        getline(ss, department, ',');

        int id = stoi(idStr);
        int age = stoi(ageStr);

        students.emplace_back(id, name, age, department);
    }
    file.close();

    cout << "Students loaded from file successfully." << endl;
}


int main() {

    vector<Student> students;
    int choice;

    do {
        showMenu();
        cin >> choice;
        cout << endl;

        switch (choice){
        case 1:
            addStudent(students);
            break;
        case 2:
            showStudents(students);
            break;
        case 3:
            deleteStudent(students);
            break;
        case 4:
            updateStudent(students);
            break;
        case 5:
            saveToFile(students);
            break;
        case 6:
            loadFromFile(students);
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again!" << endl;
        }

    } while (choice != 0);

	return 0;
}