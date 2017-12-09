#ifndef EMPLOYEEREPOSITORY_H
#define EMPLOYEEREPOSITORY_H
#include "Employee.h"
#include "NoFileException.h"
//#include "SalaryRecords.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>


class EmployeeRepository
{
    public:
        EmployeeRepository();
        void WriteFile(vector<Employee> records);
        void ReadFile();
        void FindInFile(string input);
        void Filterrecords(string line);
        int Converttoint(string input);
        vector<Employee> PassRecords();
    private:
        vector<Employee> Records;

};

#endif // EMPLOYEEREPOSITORY_H
