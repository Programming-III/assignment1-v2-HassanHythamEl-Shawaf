#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Instructor.h"
#include "Course.h"

using namespace std;

	Person::Person(string name, int id) {
		this->name = name;
		this->id = id;
	}
	void Person::display() {
		cout << "Name: " << name << endl;
		cout << "ID: " << id << endl;
	}
	string Person::getName() {
		return name;
	}
	void Person::setName(string name) {
		this->name = name;
	}
	int Person::getId() {
		return id;
	}
	void Person::setId(int id) {
		this->id = id;
	}


	Student::Student(string name, int id, int yearLevel, string major) :Person(name, id) {
		this->yearLevel = yearLevel;
		this->major = major;
	}
	void Student::display() {
		cout << "Name:" << this->getName() << endl;
		cout << "ID:" << this->getId() << endl;
		cout << "Year:" << yearLevel << endl;
		cout << "Major:" << major << endl;
	}
	string Student::getMajor(){
		return major;
	}
	int Student::getYearLevel() {
		return yearLevel;
	}






	Instructor::Instructor(string name, int id, string department, int experienceYears) :Person(name, id) {
		this->department = department;
		this->experienceYears = experienceYears;
	}
	Instructor::~Instructor(){
	}
	void Instructor::display() {
		cout << "Name:" << this->getName() << endl;
		cout << "Department:" << department << endl;
		cout << "Experience:" << experienceYears << endl;
	}
	string Instructor::getDepartment() {
		return department;
	}
	int Instructor::getExperienceYears() {
		return experienceYears;
	}




	Course::Course(string courseCode, string courseName, int maxStudents) {
		this->courseCode = courseCode;
		this->courseName = courseName;
		this->maxStudents = maxStudents;
		students = new Student[maxStudents];
		currentStudents = 0;
	}
	Course::~Course() {
		delete[] students;
	}
	void Course::addStudent(const Student& s) {
		if (currentStudents < maxStudents) {
			students[currentStudents + 1] = s;
		}
		else cout << "Max Students Reached" << endl;
	}
	void Course::displayCourseInfo() {
		cout << "Course:" << courseName << endl;
		cout << "Max Students:" << maxStudents << endl;
		cout << "Currently Enrolled:";
		for (int i = 0; i < maxStudents; i++) {
			cout << students[i].getName() << "(" << students[i].getId() << ")" << " ";
		}
		cout << endl;
	}


int main() {
	Course c("12C30", "CS101-Introduction to Programming:", 20);
	Student s("Omar Nabil",2202,2,"Informatics");
	c.addStudent(s);
	c.displayCourseInfo();
	Instructor i("Dr.linda Khaled", 2313, "Computer Science", 5);
	cout << "Instructor Info:" << endl;
	i.display();
	cout << "Student Info;" << endl;
	s.display();

    return 0;
}
