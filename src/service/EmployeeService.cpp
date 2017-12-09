#include "EmployeeService.h"

EmployeeService::EmployeeService()
{
    //ctor
    ER.ReadFile();
    Records = ER.PassRecords();
}
void EmployeeService::add_employee(const Employee& employee)
{
    Records = ER.PassRecords();
    bool found = false;
    if(IsValidName(employee) && IsValidMonth(employee) && isValidYear(employee) && IsValidSSN(employee) && ISValidSalary(employee))
    {
        for(unsigned int i = 0; i < Records.size(); i++)
        {
            if(Records[i].get_ssn() == employee.get_ssn())
            {
                if((employee.get_month() == Records[i].get_month()) && (employee.get_year() == Records[i].get_year()))
                {
                    found = true;
                    Records[i].set_salary(employee.get_salary());
                    break;
                }
            }
        }
        if(!found)
        {
            Records.push_back(employee);
        }
    }
    ER.WriteFile(Records);
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
    for(unsigned int i = 0; i < Records.size(); i++)
    {
        cout << Records[i] << endl;
    }
}

void EmployeeService::PrintSpecific(string input)
{
    ER.FindInFile(input);
}
