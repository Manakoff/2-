#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Student
{
protected:
    //для дочерних классов

private:
    short kyrs;
    int variant;
    int gruppa;
    string first_name;
    string last_name;
    int napravlenie;

public:

    Student()
    {
        first_name = "";
        last_name = "";
        napravlenie = 0;
        kyrs = 1;
        variant = 1;
        gruppa = 1;
    }


    Student(const string& first, const string& last, int naprav, short kyr, int grup, int vari)
    {
        assert (vari > 0);
        assert (kyr > 0);
        assert (kyr < 7);
        first_name = first;
        last_name = last;
        napravlenie = naprav;
        kyrs = kyr;
        variant= vari;
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

    ~Student()
    {
        cout << "Class_Student_Destr.";
    }

    string getFirstName() { return first_name; }
    string getLastName() { return last_name; }
    int getNapravlenie() { return napravlenie; }
    int getGruppa() { return gruppa; }
    short getKyrs() { return kyrs; }
    int getVariant() { return variant; }

    void setKyrs(int ky) 
    { 
        if (ky < 1 or ky > 6)
            cout << "Попробуйте ещё раз";
        else
            kyrs = ky; 
    }
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
        int k = kyrs + 1;
        if (k > 6)
            cout << "Превышен лимит курсов" << endl;

        else
            kyrs++;
        
    }
};

int main()
{
    setlocale(LC_ALL, "RU");

    Student s_1("Андрей", "Манаков", 1122, 1, 2, 3);
    s_1.printInfo();

    Student s2 = s_1;
    s2.printInfo();


    s_1.nextKyrs();
    s_1.printInfo();

    s_1.setVariant(3);
    s_1.getVariant();
    s_1.setKyrs(0);
    cout << endl;


    return 0;
}
