#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <string> 


class Student {
private:
	int id;
	std::string name;
	int age;
	std::string department;

public:
	Student(int id_ = 0, std::string name_ = "", int age_ = 0, std::string department_ = "");

	int getId() const;
	std::string getName() const;
	int getAge() const;
	std::string getDepartment() const;

	void setName(const std::string& name);
	void setAge(int age);
	void setDepartment(const std::string& department);

	void display() const;
};
#endif