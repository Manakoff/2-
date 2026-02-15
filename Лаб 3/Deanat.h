#pragma once
#include "Student.h"
#include <string>
#include <vector>


class Deanat
{
private:
    std::string m_address;
    std::vector<Student*> m_ptrs;

public:
    Deanat(const std::string& address);
    ~Deanat();

    Deanat(const Deanat& other) = delete;
    Deanat& operator=(const Deanat& other) = delete;

    void addStud(Student* stud);
    void removeStud(Student* stud);
    std::string& getAddress();
    std::vector<Student*>& getStudents();
};
