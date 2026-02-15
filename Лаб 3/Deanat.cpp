#include "Deanat.h"
#include <algorithm>

Deanat::Deanat(const std::string& address)
{
    m_address = address;
}


Deanat::~Deanat()
{
}

void Deanat::addStud(Student* stud)
{
    if (std::find(m_ptrs.begin(), m_ptrs.end(), stud) == m_ptrs.end())
        m_ptrs.push_back(stud);
}

void Deanat::removeStud(Student* stud)
{
    auto f = std::find(m_ptrs.begin(), m_ptrs.end(), stud);
    if (f != m_ptrs.end())
        m_ptrs.erase(f);
}

std::string& Deanat::getAddress()
{
    return m_address;
}

std::vector<Student*>& Deanat::getStudents()
{
    return m_ptrs;
}