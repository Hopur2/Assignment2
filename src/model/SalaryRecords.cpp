#include "SalaryRecords.h"

SalaryRecords::SalaryRecords(string name, string ssn, int salary, int month, int year)
{
    _name = name;
    _SSN = ssn;
    _salary = salary;
    _month = month;
    _year = year;
}

ostream& operator << (ostream& out, const SalaryRecords& rec)
{
    out << "Name: " << rec._name << endl;
    out << "SSN: " << rec._SSN << endl;
    out << "Year: " << rec._year << endl;
    out << "Month: " << rec._month << endl;
    out << "Salary: " << rec._salary << endl;

    return out;
}
