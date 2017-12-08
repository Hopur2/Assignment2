#include "EmployeeUI.h"
#include <cstdlib>

EmployeeUI::EmployeeUI()
{
    //ctor
}

void EmployeeUI::menuUI()
{
    cout << "Hi person who is using this program to do something" << endl;
    while(true)
    {
        cout << "Pick the number for the corresponding option" << endl;
        cout << "------------------OPTIONS-------------------" << endl;
        cout << "1. Employee"<< endl;
        cout << "2. Get salary record"<<endl;
        cout << "3. Get employee salary" << endl;
        cout << "4. Exit" <<endl;
        cout << endl;
        char input;
        cin >> input;
        validate_user_input(input);
    }
}

void EmployeeUI::validate_user_input(char input)
{
        if(input == '1')
        {
            try{
                employee_service.add_employee(create_employee());
            }
            catch(InvalidNameException){
                system("cls");
                cout << "zup brah, invalid name, no numbers brah" << endl<<endl;
            }
            catch(InvalidMonthException){
                system("cls");
                cout << "zup brah, months need to be between 1 - 12 and not string" << endl<<endl;
            }
            catch(InvalidYearException){
                system("cls");
                cout << "zup brah, year needs to be 2017 and not string" << endl<<endl;
            }
            catch(InvalidSsnException){
                system("cls");
                cout << "zup brah, SSN needs to be 10 digits and not a string" << endl<<endl;
            }
            catch(InvalidSalaryException){
                system("cls");
                cout << "zup brah, Salary needs to be over 50000 and not a string" << endl<<endl;
            }

        }
        else if(input == '2')
        {
            string input;
            cout << "enter SSN: ";
            cin >> input;
            ES.PrintSpecific(input);


        }
        else if(input == '3')
        {
            string ssn;
            cout << "enter SSN: ";
            cin >> ssn;
            ES.get_year_salary(ssn);

        }
        else if(input == '4')
        {
            exit(1);
        }
        else
        {
            cout << "invalid input!" << endl;
        }
}

Employee EmployeeUI::create_employee()
{
    string name,ssn;
    int salary,month,year;
    cout <<"Name: ";
    cin.ignore();
    getline(cin, name);

    cout <<"SSN: ";
    cin >> ssn;
    cout << ssn.length() <<endl;

    cout <<"Salary: ";
    cin >> salary;
    failure_check(salary);

    cout <<"Month: ";
    cin >> month;
    failure_check(month);

    cout <<"Year: ";
    cin >> year;
    failure_check(year);

    Employee employee(ssn,name,salary,month,year);
    return employee;
}

void EmployeeUI::failure_check(int check){
    if(cin.fail()){
        cin.clear();
        cin.ignore(256,'\n');
        check = 0;
    }
}
