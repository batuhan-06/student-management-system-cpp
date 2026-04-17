#include "Student.h"
#include <iostream>
using namespace std;


Student::Student(int id_, std::string name_, int age_, std::string department_) : id(id_), name(name_), age(age_), department(department_) {}

int Student::getId() const {
	return id;
}
std::string Student::getName() const {
	return name;
}
int Student::getAge() const {
	return age;
}
std::string Student::getDepartment() const {
	return department;
}

void Student::setName(const std::string& name) {
	this->name = name;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setDepartment(const std::string& department) {
	this->department = department;
}

void Student::display() const {
	cout << "------------------------" << endl;
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Department: " << department << endl;
}