#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
Create a simple collage software system to control college
courses which contains:

	 ? Instructor class that has:
		 ? Attributes: (First Name, Last Name, id, password)
		 ? Methods: (Default and Parameterized Constructors,
		 Setters, Getters, Print info).

	? Student class that has:
		? Attributes: (First Name, Last Name, id, password)
		? Methods: (Default and Parameterized Constructors,
		Setters, Getters, Print info).

	? Course class that has:
		 ? Attributes: (Name, id, Instructor, Vector <Student>
		 Students)
		 ? Methods: (Default and Parameterized Constructors,
		 Setters, Getters, A method to return all students info,
		 Print all course info)
*/


class Person {
private:
	//Attributes:
	string firstName, lastName, id, password;
public:
	//Constructors:
	Person() {

	}
	Person(string firstName, string lastName, string id, string password) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->id = id;
		this->password = password;
	}


	//Setters:
	void setFirstName(string firstName) {
		this->firstName = firstName;
	}
	void setLastName(string lastName) {
		this->lastName = lastName;
	}
	void setID(string id) {
		this->id = id;
	}
	void setPassword(string password) {
		this->password = password;
	}

	//Getters:
	string getFirstName() {
		return firstName;
	}
	string getLastName() {
		return lastName;
	}
	string getID() {
		return id;
	}
	string getFPassword() {
		return password;
	}

	//Methods:
	void printInfo() {
		cout << "First Name: " << firstName << endl;
		cout << "Last Name: " << lastName << endl;
		cout << "ID: " << id << endl;
		cout << "Password: " << password << endl;
	}
};

class Instructor : public Person {
public:
	//Constructors:
	Instructor(string firstName, string lastName, string id, string password) : Person(firstName, lastName, id, password) {
	}
	Instructor() : Person() {}
};

class Student : public Person {
public:
	//Constructors:
	Student(string firstName, string lastName, string id, string password) : Person(firstName, lastName, id, password) {
	}
	Student() : Person() {}
};

class Course {
private:
	//Attributes:
	string name, id;
	Instructor instructor;
	vector<Student> students;
public:
	//Constructors:
	Course() {

	}
	Course(string name, string id, Instructor instructor, vector<Student> students) {
		this->name = name;
		this->id = id;
		this->instructor = instructor;
		this->students = students;

	}

	//Setters:
	void setName(string name) {
		this->name = name;
	}
	void setID(string id) {
		this->id = id;
	}
	void setInstructor(Instructor instructor) {
		this->instructor = instructor;
	}
	void setStudents(vector<Student> students) {
		this->students = students;
	}

	//Getters:
	string getName() {
		return name;
	}
	string getID() {
		return id;
	}
	Instructor getInstructor() {
		return instructor;
	}
	vector<Student> getSudents() {
		return students;
	}

	//Methods:
	void studentsInfo() {
		for (int i = 0; i < students.size(); i++) {
			cout << "Student no. " << i + 1 << endl;
			students[i].printInfo();
			cout << "===========================\n";
		}
	}
	void courseInfo() {
		cout << "Course Name: " << name << endl;
		cout << "Course ID: " << id << endl;
		cout << "=================================\n";
		cout << "Instructor Information: " << endl;
		instructor.printInfo();
		cout << "=================================\n";
		studentsInfo();
	}
};

int main() {
	Instructor s("Moatasem ", "Diab", "12345", "moatasem");
	Student s1("Moatasem", "Mohamed", "124234", "mohamed123");
	Student s2("Khaled", "mostafa", "124234", "khaled123");
	Student s3("mona", "ahmed", "124234", "mona23");
	vector<Student> students;
	students.push_back(s1);
	students.push_back(s2);
	students.push_back(s3);
	Course course("ITI", "ITI2020", s, students);
	course.courseInfo();
}
