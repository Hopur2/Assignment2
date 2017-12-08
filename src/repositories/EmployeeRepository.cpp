#include "EmployeeRepository.h"

EmployeeRepository::EmployeeRepository()
{
    //ctor
}

void EmployeeRepository::add_employee(const Employee& employee)
{
    ofstream fout;
    fout.open("employee.txt",ios::app);
    if(fout.is_open())
    {
        fout << employee;
        fout.close();
    }
    else{
        //throw error
    }
}

void EmployeeRepository::FindInFile(string input)
{
    string line;
    ifstream fin;
    fin.open("employee.txt");
    if(fin.is_open())
    {
        while(getline(fin,line))
        {
            if(line.find(input) !=string::npos)
            {
                cout << line << endl;
            }
        }
        fin.close();
    }
    else
    {
        cout << "File Couldn't be opened" << endl;
    }
}

void EmployeeRepository::ReadFile()
{
    string line;
    ifstream fin;
    fin.open("employee.txt");
    if(fin.is_open())
    {
        while(!fin.eof())
        {
            getline(fin, line);
            Filterrecords(line);
            if(fin.eof()){
                break;
            }
        }

        fin.close();
    }
    else
    {
        cout << "File Couldn't be opened" << endl;
    }
}

void EmployeeRepository::Filterrecords(string line)
{
    string record[5];
    int counter = 0;
    for(unsigned int i = 0; i < line.size(); i++)
    {
        if(line[i] == '|')
        {
            counter++;
        }
        else
        {
            record[counter] += line[i];
        }
    }
    Employee rec(record[0], record[1], Converttoint(record[2]), Converttoint(record[3]), Converttoint(record[4]));
    Records.push_back(rec);

}

vector<Employee> EmployeeRepository::PassRecords()
{
    return Records;
}

int EmployeeRepository::Converttoint(string input)
{
    stringstream ss;
    int out = 0;
    ss << input;
    ss >> out;

    return out;

}
