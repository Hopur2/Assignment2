#ifndef EMPLOYEEUI_H
#define EMPLOYEEUI_H
#include "Employee.h"
#include "EmployeeService.h"

class EmployeeUI
{
    public:
        EmployeeUI();
        void menuUI();

    private:
        void validate_user_input(char input);
        EmployeeService employee_service;
        Employee create_employee();
        void failure_check(int check);
        EmployeeService ES;
};

#endif // EMPLOYEEUI_H
