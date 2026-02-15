#pragma once
#include <string>
#include <vector>
#include "Application.h"

class Student
{
private:
    std::string first_name;
    std::string last_name;
    int m_napr;
    int m_curs;
    int m_grup;
    int m_var;
    std::vector<std::string> m_dolg;

public:
    Student();
    Student(const std::string& first, const std::string& last, int m_napr, int m_curs, int m_grup, int m_var, const std::vector<std::string>& dolg);
    Student(const Student& copy);
    ~Student() = default;

    std::string getFirst();
    std::string getLast();
    int getNapr();
    int getCurs();
    int getGrup();
    int getVar();
    const std::vector<std::string>& getDolg();

    void setFirst(const std::string& first);
    void setLast(const std::string& last);
    void setNapr(int napr);
    void setCurs(int curs);
    void setGrup(int grup);
    void setVar(int var);

    void printInfo();
    void addDolg(const std::string& dolg_);
    void nextCurs();


    Application AppNextCourse();


    Application AppAnotherGroup(int newGroup);


    Student operator+(const Student& other) const;
    Student& operator-=(const Student& other);
    Student operator/(const Student& other) const;
};
