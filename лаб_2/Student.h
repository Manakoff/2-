#pragma once

class Student
{
private:
	std::string* first_name;
	std::string* last_name;
	std::vector<std::string>* dolg;

public:

	Student();
	Student(const std::string& first, const std::string& last, const std::vector<std::string>& dol);
	Student(const Student& copy_stud);
	~Student();

	void setFirst(const std::string& first) { *first_name = first; }
	void setLast(const std::string& last) { *last_name = last; }

	std::string getFirst() { return *first_name; }
	std::string getLast() { return *last_name; }
	std::vector<std::string> getDolg() { return *dolg; }


	void printInfo();
	void addDolg(const std::string& dolg);

	/*
	Student operator=(const Student& s1, const Student& s2);
	Student operator+(const Student& s1, const Student& s2); 
	Student operator-=(const Student& s1, const Student& s2);
	Student operator/(const Student& s1, const Student& s2);
	*/

};