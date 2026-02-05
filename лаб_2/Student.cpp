#include "Student.h"
#include <iostream>
#include <algorithm>

Student::Student()
{
    first_name = new std::string("");
    last_name = new std::string("");
    dolg = new std::vector<std::string>;
}

Student::Student(const std::string& first, const std::string& last, const std::vector<std::string>& dol)
{
    first_name = new std::string(first);
    last_name = new std::string(last);
    dolg = new std::vector<std::string>(dol);
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

void Student::setFirstName(const std::string& first)
{
    *first_name = first;
}

void Student::setLastName(const std::string& last)
{
    *last_name = last;
}

std::string Student::getFirst()
{
    return *first_name;
}

std::string Student::getLast()
{
    return *last_name;
}

std::vector<std::string> Student::getDolg()
{
    return *dolg;
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

void Student::addDolg(const std::string& dol)
{
    bool exists = false;
    for (const auto& d : *dolg)
        if (d == dol) {
            exists = true;
            break;
        }
    if (!exists)
        dolg->push_back(dol);
}

Student& Student::operator=(const Student& copy)
{
    if (this != &copy)
    {
        delete first_name;
        delete last_name;
        delete dolg;

        first_name = new std::string(*copy.first_name);
        last_name = new std::string(*copy.last_name);
        dolg = new std::vector<std::string>(*copy.dolg);
    }
    return *this;
}

Student Student::operator+(const Student& copy)
{
    Student result(*first_name + ", " + *copy.first_name,
        *last_name + ", " + *copy.last_name,
        *dolg);
    for (const auto& d : *copy.dolg)
        result.addDolg(d);
    return result;
}

Student& Student::operator-=(const Student& copy)
{
    for (const auto& d : *copy.dolg)
    {
        auto f = std::find(dolg->begin(), dolg->end(), d);
        if (f != dolg->end())
        {
            dolg->erase(f);
        }
    }
    return *this;
}

Student Student::operator/(const Student& copy)
{
    Student result(*first_name + ", " + *copy.first_name,
        *last_name + ", " + *copy.last_name,
        {});
    for (const auto& d : *dolg)
    {
        auto f = std::find(copy.dolg->begin(), copy.dolg->end(), d);
        if (f != copy.dolg->end())
        {
            result.addDolg(d);
        }
    }
    return result;
}