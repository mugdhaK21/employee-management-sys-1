#ifndef Header_h
#define Header_h

#include<iostream>
#include<vector>
using namespace std;
class Employee;
class payrollSystem;
class Attendance {
private:
    int attendance = 100;
    int daysPresent;
    int total_workingdays;

    // daysPresent(daysPresent) {};

    // int getEmployeeId() const;
protected:

    Attendance();
    int getDaysPresent() const;
    void setDaysPresent();
    void setAttendance();
    int getAttendance();
    // void displayAttendance();

    friend Employee;

};

// Employee base class
class Employee {
protected:
    string name;
    int employeeId;
    double baseSalary;

    //to update a new record add another vaibles 
    int id;
    string newname;
    double newBaseSalary;
    double newperks;
    double newallowances;
    Attendance* eAttendance=NULL;

public:
    Employee(string name, int employeeId, double baseSalary) : name(name), employeeId(employeeId), baseSalary(baseSalary),eAttendance(new Attendance){}

    virtual ~Employee() {};

    virtual double calculateSalary() const = 0;

    virtual void display() const;

    int getEmployeeId();

    void setBaseSalary(double salary);
    void setAtt();
    int getEAtt();

    //functions for update the new data---let us define in source file 
    void setupdatedNewname(string name);
    void setupdatesperks(double perks);
    void setupdatesallowances(double allowances);
    friend payrollSystem;
};

// Regular Employee derived class
class RegularEmployee : public Employee {
private:
    double perks;
    double allowances;

public:
    RegularEmployee(string name, int employeeId, double baseSalary, double perks, double allowances) : Employee(name, employeeId, baseSalary), perks(perks), allowances(allowances) {}

    double calculateSalary() const;

    void display() const;
};

//Derived class for Contract Employees


class ContractEmployee : public Employee {
private:
    double incentives;

public:
    ContractEmployee(string name, int employeeId, double baseSalary, double incentives) : Employee(name, employeeId, baseSalary), incentives(incentives) {}

    double calculateSalary() const override;

    void display() const override;
};

// Class to maintain monthly attendance records

// Class to maintain employee payroll data

class PayrollSystem {
private:

    vector<Employee*> employees;
  

public:
    /* It is responsible for deallocating memory held by dynamically allocated Employee objects in the employees vector.
         It iterates through the employees vector and deletes each Employee object.*/
    ~PayrollSystem() {
        for (Employee* emp : employees) {
            delete emp;
        }
    }

    void addEmployee(Employee* emp);

    void addAttendanceRecord(int employeeId, int daysPresent);

    /*This function displays details of all employees along with their attendance records.
        It sorts the employees vector based on the salary of each employee in descending order using a lambda functionand sort.
        It then iterates through the sorted employees vectorand displays each employee's details.
        For each employee, it searches for their attendance record in the attendanceRecords vectorand displays the
        number of days present if found, otherwise, it indicates that attendance is not recorded.*/
    void displayAllEmployees() const;




    /*This function searches for an employee by their ID.
        It takes an employee ID as an argumentand returns a pointer to the corresponding Employee object if found, otherwise, it returns nullptr.
        It iterates through the employees vectorand compares the ID of each employee with the provided ID.*/
    Employee* searchEmployeeById(int id) const;



    /*This function deletes an employee record by their ID.
        It takes an employee ID as an argumentand removes the corresponding Employee object from the employees vector.
        It uses the remove_if algorithm along with a lambda function to find the employee with the provided IDand remove it from the vector.
        If an employee is foundand removed, it also deallocates the memory of the corresponding Employee object.*/
    void deleteEmployee(int id);


    /*This function updates the base salary of an employee by their ID.
        It takes an employee IDand the new base salary as arguments.
        It searches for the employee with the provided ID using the searchEmployeeById function.
        If the employee is found, it updates the base salary of the employee using the setBaseSalary function.
        If the employee is not found, it prints a message indicating that the employee with the given ID was not found.*/

    void updateEmployeeData(int id);
   
};



#endif
