#ifndef SALARYRECORDS_H
#define SALARYRECORDS_H
#include <string>
#include <iostream>

using namespace std;

class SalaryRecords
{
    public:
        SalaryRecords(string name, string ss, int salary, int month, int year);
        friend ostream& operator << (ostream& out, const SalaryRecords& rec);
    private:
        string _name;
        string _SSN;
        int _salary;
        int _month;
        int _year;
};

#endif // SALARYRECORDS_H
