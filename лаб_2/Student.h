#pragma once
#include <string>
#include <vector>

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

    void setFirstName(const std::string& first);
    void setLastName(const std::string& last);

    std::string getFirst();
    std::string getLast();
    std::vector<std::string> getDolg();

    void printInfo();
    void addDolg(const std::string& dolg);

    Student& operator=(const Student& copy);
    Student operator+(const Student& copy);
    Student& operator-=(const Student& copy);
    Student operator/(const Student& copy);
};