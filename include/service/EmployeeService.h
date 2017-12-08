#ifndef EMPLOYEESERVICE_H
#define EMPLOYEESERVICE_H
#include "Employee.h"
#include "EmployeeRepository.h"
#include "InvalidNameException.h"
#include "InvalidMonthException.h"
#include "InvalidYearException.h"
#include "InvalidSsnException.h"
#include "InvalidSalaryException.h"

class EmployeeService
{
    public:
        EmployeeService();
        void add_employee(const Employee& employee);
        void PrintRecords();
        void PrintSpecific(string input);
        void get_year_salary(string ssn);
    private:
        EmployeeRepository employee_repo;
        bool IsValidName(const Employee& employee);
        bool IsValidSSN(const Employee& employee);
        bool IsValidMonth(const Employee& employee);
        bool isValidYear(const Employee& employee);
        bool ISValidSalary(const Employee& employee);
        vector<Employee> Records;
        EmployeeRepository ER;
};

#endif // EMPLOYEESERVICE_H
