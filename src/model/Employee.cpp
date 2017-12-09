#include "Employee.h"

Employee::Employee(string ssn, string name, int salary, int month,int year)
{
    _ssn = ssn;
    _name = name;
    _salary = salary;
    _month = month;
    _year = year;
}

ostream& operator << (ostream& out,const Employee& employee)
{
    out <<employee._ssn <<"|";
    out <<employee._name <<"|";
    out <<employee._salary <<"|";
    out <<employee._month << "|";
    out <<employee._year << "|" << endl;
    return out;
}

string Employee::get_name() const
{
    return _name;
}

string Employee::get_ssn() const
{
    return _ssn;
}

int Employee::get_salary() const
{
    return _salary;
}

int Employee::get_month() const
{
    return _month;
}

int Employee::get_year() const
{
    return _year;
}

void Employee::set_salary(int salary)
{
    _salary = salary;
}
