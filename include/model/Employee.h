#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>

using namespace std;

class Employee
{
    public:
        Employee(string ssn,string name,int salary, int month,int year);
        string get_name() const;
        string get_ssn() const;
        int get_salary() const;
        int get_month() const;
        int get_year() const;
        void set_salary(int salary);

        friend ostream& operator << (ostream& out,const Employee& employee);
    private:
        string _name;
        string _ssn;
        int _salary;
        int _month;
        int _year;
};

#endif // EMPLOYEE_H
