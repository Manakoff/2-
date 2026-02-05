#include "Student.h"
#include <iostream>

int main() {
    
    setlocale(LC_ALL, "ru");

    Student s1("К", "КС", { "А1", "А2", "Б1" });
    s1.printInfo();

    Student s2("Б", "БС", { "Б1", "В1", "В2" });
    s2.printInfo();
    
    Student s3 = s1;
    s3.setFirstName("Петр");
    s3.setLastName("Петров");
    s3.printInfo();

    
    Student s4 = s1 + s2;
    s4.printInfo();

    Student s5 = s1 / s2;
    s5.printInfo();
    
    s1 -= s2; 
    s1.printInfo();

    
    

    return 0;
}