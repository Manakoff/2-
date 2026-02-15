#include "Student.h"
#include <iostream>
#include <algorithm>

Student::Student()
{
    first_name = "";
    last_name = "";
    m_napr = 0;
    m_curs = 1;
    m_grup = 0;
    m_var = 1;
}

Student::Student(const std::string& first, const std::string& last, int napr, int curs, int grup, int var, const std::vector<std::string>& dolg)
{
    first_name = first;
    last_name = last;
    m_napr = napr;
    m_curs = curs;
    m_grup = grup;
    m_var = var;
    m_dolg = dolg;
}

Student::Student(const Student& copy)
{
    first_name = copy.first_name;
    last_name = copy.last_name;
    m_napr = copy.m_napr;
    m_curs = copy.m_curs;
    m_grup = copy.m_grup;
    m_var = copy.m_var;
    m_dolg = copy.m_dolg;
}

void Student::setFirst(const std::string& first)
{
    first_name = first;
}

void Student::setLast(const std::string& last)
{
    last_name = last;
}

void Student::setNapr(int napr)
{
    m_napr = napr;
}

void Student::setCurs(int curs)
{
    if (curs >= 1 && curs <= 6)
        m_curs = curs;
    else
        throw std::invalid_argument("Введите корректный номер курса (1-6)");
}

void Student::setGrup(int grup)
{
    m_grup = grup;
}

void Student::setVar(int var)
{
    m_var = var;
}

std::string Student::getFirst() { return first_name; }
std::string Student::getLast() { return last_name; }
int Student::getNapr() { return m_napr; }
int Student::getCurs() { return m_curs; }
int Student::getGrup() { return m_grup; }
int Student::getVar() { return m_var; }
const std::vector<std::string>& Student::getDolg() { return m_dolg; }

void Student::printInfo()
{
    std::cout << "Имя: " << first_name << std::endl;
    std::cout << "Фамилия: " << last_name << std::endl;
    std::cout << "Направление: " << m_napr << std::endl;
    std::cout << "Курс: " << m_curs << std::endl;
    std::cout << "Группа: " << m_grup << std::endl;
    std::cout << "Вариант: " << m_var << std::endl;
    std::cout << "Долги: ";
    for (const auto& d : m_dolg)
        std::cout << d << " ";
    std::cout << std::endl;
}

void Student::addDolg(const std::string& dolg)
{
    if (std::find(m_dolg.begin(), m_dolg.end(), dolg) == m_dolg.end())
        m_dolg.push_back(dolg);
}

void Student::nextCurs()
{
    if (m_curs >= 1 && m_curs < 6)
        ++m_curs;
    else
        throw std::invalid_argument("Превышен лимит курсов, максимум - 6");
}


Application Student::AppNextCourse()
{
    Application app;
    app.first_name = first_name;
    app.last_name = last_name;
    app.type = "перевод_на_следующий_курс";
    app.comment = "Запрос на перевод на курс " + std::to_string(m_curs + 1);
    app.data = m_curs + 1;
    Student::nextCurs();
    return app;
}


Application Student::AppAnotherGroup(int newGroup)
{
    Application app;
    app.first_name = first_name;
    app.last_name = last_name;
    app.type = "перевод_в_другую_группу";
    app.comment = "Запрос на перевод в группу " + std::to_string(newGroup);
    app.data = newGroup;
    Student::setGrup(newGroup);
    return app;
}

Student Student::operator+(const Student& other) const
{
    Student result(*this);
    for (const auto& d : other.m_dolg)
        result.addDolg(d);
    result.first_name += ", " + other.first_name;
    result.last_name += ", " + other.last_name;
    return result;
}

Student& Student::operator-=(const Student& other)
{
    for (const auto& d : other.m_dolg)
    {
        auto f = std::find(m_dolg.begin(), m_dolg.end(), d);
        if (f != m_dolg.end())
            m_dolg.erase(f);
    }
    return *this;
}

Student Student::operator/(const Student& other) const
{
    Student result(*this);
    result.m_dolg.clear();
    for (const auto& d : m_dolg)
    {
        if (std::find(other.m_dolg.begin(), other.m_dolg.end(), d) != other.m_dolg.end())
            result.addDolg(d);
    }
    return result;
}