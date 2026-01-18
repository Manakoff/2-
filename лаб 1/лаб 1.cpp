#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int kyrs;
    int variant;
    int gruppa;
    string first_name;
    string last_name;
    string napravlenie;

public:

    Student()
    {
        first_name = "";
        last_name = "";
        napravlenie = "";
        kyrs = 1;
        variant = 1;
        gruppa = 1;
    }


    Student(const string& first, const string& last, const string& naprav, int kyr, int grup, int vari)
    {
        first_name = first;
        last_name = last;
        napravlenie = naprav;
        kyrs = kyr;
        variant = vari;
        gruppa = grup;
    }

    Student(const Student& copy)
    {
        first_name = copy.first_name;
        last_name = copy.last_name;
        napravlenie = copy.napravlenie;
        kyrs = copy.kyrs;
        variant = copy.variant;
        gruppa = copy.gruppa;
    }

    string getFirstName() { return first_name; }
    string getLastName() { return last_name; }
    string getNapravlenie() { return napravlenie; }
    int getGruppa() { return gruppa; }
    int getKyrs() { return kyrs; }
    int getVariant() { return variant; }

    void setKyrs(int ky) { kyrs = ky; }
    void setVariant(int var) { variant = var; }

    void printInfo()
    {
        cout << "Имя: " << first_name << endl;
        cout << "Фамилия: " << last_name << endl;
        cout << "Направление: " << napravlenie << endl;
        cout << "Номер курса: " << kyrs << endl;
        cout << "Номер группы: " << gruppa << endl;
        cout << "Номер варианта: " << variant << endl << endl;
    }

    void nextKyrs()
    {
        kyrs++;
    }
};

int main()
{
    setlocale(LC_ALL, "RU");

    Student student_1("Андрей", "Манаков", "ИИАД-2", 1, 2, 1);
    student_1.printInfo();

    student_1.nextKyrs();
    student_1.printInfo();

    student_1.setVariant(3);
    student_1.printInfo();

    return 0;
}