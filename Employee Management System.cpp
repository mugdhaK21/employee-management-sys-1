#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include<string>
#include "Header.h"
using namespace std;

// Function to display menu
void displayMenu() {
    cout << "------------------------------------------------------------" ;
    cout << "\nPayroll Processing System Menu:" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Display all employees' records" << endl;
    cout << "3. Search employee by ID and display details" << endl;
    cout << "4. Update employee data" << endl;
    cout << "5. Delete employee by ID" << endl;
    cout << "6. Exit" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    PayrollSystem payrollSystem;

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            int type;
            cout << "Enter type of employee (1 for Regular, 2 for Contract): ";
            cin >> type;
            cout << "------------------------------------------------------------" << endl;

            string name;
            int employeeId;
            double baseSalary;

            cout << "Enter employee name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter employee ID: ";
            cin >> employeeId;

            cout << "Enter base salary: ";
            cin >> baseSalary;

            if (type == 1) {
                double perks, allowances;
                cout << "Enter perks: ";
                cin >> perks;

                cout << "Enter allowances: ";
                cin >> allowances;

                payrollSystem.addEmployee(new RegularEmployee(name, employeeId, baseSalary, perks, allowances));
            }
            else if (type == 2) {
                double incentives;
                cout << "Enter incentives: ";
                cin >> incentives;

                payrollSystem.addEmployee(new ContractEmployee(name, employeeId, baseSalary, incentives));
            }
            else {
                cout << "Invalid employee type." << endl;
            }

            int daysPresent;
            cout << "Enter days present for this month: ";
            cin >> daysPresent;
            payrollSystem.addAttendanceRecord(employeeId, daysPresent);
            cout << "------------------------------------------------------------" << endl;
            break;
            
        }
        case 2:
            payrollSystem.displayAllEmployees();
            break;
        case 3: {
            int id;
            cout << "Enter employee ID to search: ";
            cin >> id;
            {
                Employee* emp = payrollSystem.searchEmployeeById(id);
                if (emp != nullptr) {
                    emp->display();
                }
                else {
                    cout << "Employee with ID " << id << " not found." << endl;
                }
            }
            cout << "------------------------------------------------------------" << endl;
            break;
            
        }
        case 4: {
            int id;
            string newname;
            double newBaseSalary;
            double newperks;
            double newallowances;
            cout << "Enter employee ID to update data: ";
            cin >> id;
            cout << "Enter Updated Name of the Emplyee: ";
            cin >> newname;
            cout << "Enter Updates perks for the employee:  ";
            cin >> newperks;
            cout << "Enter Updates Allowances for the employee:  ";
            cin >> newallowances;
            cout << "Enter new base salary: ";
            cin >> newBaseSalary;

            payrollSystem.updateEmployeeData(id,newBaseSalary,newname,newperks,newallowances);
            cout << "------------------------------------------------------------" << endl;
            break;
            
        }
        case 5: {
            int id;
            cout << "Enter employee ID to delete: ";
            cin >> id;
            payrollSystem.deleteEmployee(id);
            cout << "------------------------------------------------------------" << endl;
            break;
            
        }
        case 6:
            cout << "Exiting..." << endl;
            cout << "------------------------------------------------------------" << endl;
            break;
            
        default:
            cout << "Invalid choice. Please try again." << endl;
            cout << "------------------------------------------------------------";
        }
    } while (choice != 6);

    return 0;
}