#include "Student.h"
#include <algorithm>
#include <iostream>
#include <vector>

Student::Student()
{
	first_name = new std::string("");
	last_name = new std::string("");
	dolg = new std::vector<std::string>;

}
Student::Student(const std::string& first, const std::string& last, const std::vector<std::string>& dol)
{
	*first_name = first;
	*last_name = last;
	*dolg = dol;
}
Student::Student(const Student& copy)
{
	first_name = new std::string(*copy.first_name);
	last_name = new std::string(*copy.last_name);
	dolg = new std::vector<std::string>(*copy.dolg);

}
Student::~Student()
{
	delete first_name;
	delete last_name;
	delete dolg;
}

void Student::printInfo()
{
	std::cout << "Имя: " << *first_name << std::endl;
	std::cout << "Фамилия: " << *last_name << std::endl;
	std::cout << "Долги: ";
	for (const auto& i : *dolg) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void Student::addDolg(const std::string& dol) {
	if (std::find(dolg->begin(), dolg->end(), dol) == dolg->end()) {
		dolg->push_back(dol);
	}
}