#include "EmployeeService.h"

EmployeeService::EmployeeService()
{
    //ctor
    ER.ReadFile();
    Records = ER.PassRecords();
}

void EmployeeService::add_employee(const Employee& employee)
{
    if(IsValidName(employee) && IsValidMonth(employee) && isValidYear(employee) && IsValidSSN(employee) && ISValidSalary(employee))
    {
        employee_repo.add_employee(employee);
    }

}

void EmployeeService::get_year_salary(string ssn)
{
    int year = 0;
    string name;
    for(unsigned int i = 0; i < Records.size(); i++)
    {
        if(Records[i].get_ssn() == ssn)
        {
            name = Records[i].get_name();
            year += Records[i].get_salary();
            cout << Records[i];
        }
    }

    cout << name << " has the year salary of: " << year <<endl;
}

bool EmployeeService::IsValidName(const Employee& employee)
{
    string name = employee.get_name();
    for(unsigned int i = 0; i < name.length(); i++)
    {
        if((!isalpha(name[i])) && (!isspace(name[i])))
        {
            throw (InvalidNameException());
        }
    }
    return true;
}

bool EmployeeService::IsValidSSN(const Employee& employee)
{
    string ssn = employee.get_ssn();
    int number = ssn.length();
    for(unsigned int i = 0; i < ssn.length(); i++)
    {
        if((number != 10) || (!isdigit(ssn[i])))
        {
            throw (InvalidSsnException());
        }
    }
    return true;
}

bool EmployeeService::IsValidMonth(const Employee& employee)
{
    int month = employee.get_month();
    if(!(month <= 1 || month <= 12))
    {
        throw (InvalidMonthException());
    }
    return true;
}

bool EmployeeService::isValidYear(const Employee& employee)
{
    int year = employee.get_year();
    if(!(year == 2017))
    {
        throw (InvalidYearException());
    }
    return true;
}

bool EmployeeService::ISValidSalary(const Employee& employee)
{
    int salary = employee.get_salary();
    if(!(salary > 50000))
    {
        throw(InvalidSalaryException());
    }
    return true;
}

void EmployeeService::PrintRecords()
{
    //ER.ReadFile(input);
    Records = ER.PassRecords();
    for(unsigned int i = 0; i < Records.size(); i++)
    {
        cout << Records[i] << endl;
    }
}

void EmployeeService::PrintSpecific(string input)
{
    ER.FindInFile(input);
}
