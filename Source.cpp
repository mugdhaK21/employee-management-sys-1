#ifndef Source_CPP
#define Source_CPP
#include<iostream>
#include<cstring>
#include "Header.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

void Employee:: display () const
{   
    cout << endl;
    cout << endl; 
    cout << "Name : " << name << endl;
    cout << "Employee ID: " << employeeId << endl;
    cout << "Base Salary: $" << baseSalary << endl;
}

int Employee::getEmployeeId()
{
    return employeeId;
}

void Employee::setBaseSalary(double salary) {
    baseSalary = salary;
}

//-------------------------------------------------------------------------------------------------------------//

double RegularEmployee:: calculateSalary() const {
    return baseSalary + perks + allowances;
}


void RegularEmployee::display() const {
    Employee::display();
    cout << "Perks: $" << perks << ", Allowances: $" << allowances << endl;
}

//--------------------------------------------------------------------------------------------------------------//

double ContractEmployee::  calculateSalary() const {
    return baseSalary + incentives;
}

void ContractEmployee:: display() const{
    Employee::display();
    cout << "Incentives: $" << incentives << endl;
}
//-------------------------------------------------------------------------------------------------------------------// 


int Attendance::getEmployeeId() const {
    return employeeId;
}


int Attendance::getDaysPresent() const {
    return daysPresent;
}

void Attendance::displayAttendance()
{
    int totalattendance;
    cout << "TOTAL WORKING DAYS: " << endl;
    cin >> total_workingdays;

    totalattendance = (daysPresent / total_workingdays) * 100;
    cout << "TOTAL ATTENDANCE" << totalattendance;
}

//------------------------------------------------------------------------------------------//
void PayrollSystem:: addEmployee(Employee* emp)
{
    employees.push_back(emp);
}

void PayrollSystem::addAttendanceRecord(int employeeId, int daysPresent) {
    attendanceRecords.emplace_back(employeeId, daysPresent);
}

void PayrollSystem::displayAllEmployees() const
{
    vector<Employee*> sortedEmployees = employees;
    sort(sortedEmployees.begin(), sortedEmployees.end(), [](Employee* a, Employee* b) {
        return a->calculateSalary() > b->calculateSalary();
        });

    for (Employee* emp : sortedEmployees) {
        emp->display();
        cout << "Attendance: ";
        auto it = find_if(attendanceRecords.begin(), attendanceRecords.end(), [emp](const Attendance& att) {
            return att.getEmployeeId() == emp->getEmployeeId();
            });
        if (it != attendanceRecords.end()) {
           cout << it->getDaysPresent() << " days present this month." << endl;
            //cout << it->displayAttendance() << " days present this month." << endl;
        }
        else {
            cout << "Attendance not recorded for this employee." << endl;
        }
    }
}

Employee* PayrollSystem::searchEmployeeById(int id) const {
    for (Employee* emp : employees) {
        if (emp->getEmployeeId() == id) {
            return emp;
        }
    }
    return nullptr;
}

void PayrollSystem::deleteEmployee(int id) {
    auto it = remove_if(employees.begin(), employees.end(), [id](Employee* emp) {
        return emp->getEmployeeId() == id;
        });

    if (it != employees.end()) {
        delete* it;
        employees.erase(it);
        cout << "Employee with ID " << id << " deleted successfully." << endl;
    }
    else {
        cout << "Employee with ID " << id << " not found." << endl;
    }
}



void PayrollSystem::updateEmployeeData(int id, double newBaseSalary, string newname, double newperks, double newallowances) {
    Employee* emp = searchEmployeeById(id);
    if (emp != nullptr) {
        emp->setupdatedNewname(newname);
        emp->setupdatesperks(newperks);
        emp->setupdatesallowances(newallowances);
        emp->setBaseSalary(newBaseSalary);
        cout << "Employee with ID " << id << " data updated successfully." << endl;
    }
    else {
        cout << "Employee with ID " << id << " not found." << endl;
    }
}

//-------------------------------------------------------------------------------------------------------------------------//

//functions to update employee details 

void Employee::setupdatedNewname(string name)
{
    newname = name;
}
void Employee::setupdatesperks(double perks)
{
    newperks = perks;
}
void Employee::setupdatesallowances(double allowances)
{
    newallowances = allowances;
}
#endif