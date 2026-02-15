#include <iostream>
#include "Student.h"
#include "Deanat.h"
#include "Application.h"

int main()
{
    setlocale(LC_ALL, "ru");
    try
    {
        Student s1("Иван", "Иванов", 101, 2, 10, 1, {});
        s1.printInfo();



        Deanat dean("ул.Ленина, д.1");
        dean.addStud(&s1);


        Application app1 = s1.AppNextCourse();
        std::cout << "Заявление: " << app1.type << " для " << app1.first_name << " " << app1.last_name << ", " << app1.comment << ", data: " << app1.data << std::endl;


        Application app2 = s1.AppAnotherGroup(12);
        std::cout << "Заявление: " << app2.type << " для " << app2.first_name << " " << app2.last_name << ", " << app2.comment << ", data: " << app2.data << std::endl;

        s1.printInfo();
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}
