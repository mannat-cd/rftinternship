#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base Class
class Employee {
protected:
    string name;
    int id;

public:
    Employee(string n, int i) {
        name = n;
        id = i;
    }

    // Virtual function for runtime polymorphism
    virtual double calculateSalary() = 0;

    // Virtual function to display details
    virtual void displayDetails() {
        cout << "Employee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
    }

    virtual ~Employee() {}
};

// FullTime Employee Class
class FullTimeEmployee : public Employee {
private:
    double monthlySalary;
    double bonus;

public:
    FullTimeEmployee(string n, int i, double salary, double b)
        : Employee(n, i) {
        monthlySalary = salary;
        bonus = b;
    }

    double calculateSalary() override {
        return monthlySalary + bonus;
    }

    void displayDetails() override {
        cout << "\n--- Full Time Employee ---" << endl;
        Employee::displayDetails();
        cout << "Monthly Salary: " << monthlySalary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << calculateSalary() << endl;
    }
};

// PartTime Employee Class
class PartTimeEmployee : public Employee {
private:
    int hoursWorked;
    double hourlyRate;

public:
    PartTimeEmployee(string n, int i, int hours, double rate)
        : Employee(n, i) {
        hoursWorked = hours;
        hourlyRate = rate;
    }

    double calculateSalary() override {
        return hoursWorked * hourlyRate;
    }

    void displayDetails() override {
        cout << "\n--- Part Time Employee ---" << endl;
        Employee::displayDetails();
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Hourly Rate: " << hourlyRate << endl;
        cout << "Total Salary: " << calculateSalary() << endl;
    }
};

int main() {
    vector<Employee*> employees;

    // Adding employees
    employees.push_back(new FullTimeEmployee("Rahul", 101, 50000, 5000));
    employees.push_back(new PartTimeEmployee("Sneha", 102, 120, 300));
    employees.push_back(new FullTimeEmployee("Amit", 103, 60000, 7000));
    employees.push_back(new PartTimeEmployee("Priya", 104, 100, 250));

    double highestSalary = 0;
    string highestPaidEmployee = "";

    cout << "===== Employee Salary Details =====" << endl;

    // Runtime Polymorphism
    for (auto emp : employees) {
        emp->displayDetails();

        double salary = emp->calculateSalary();

        if (salary > highestSalary) {
            highestSalary = salary;
            highestPaidEmployee = typeid(*emp).name();
        }
    }

    cout << "\n===== Highest Paid Employee =====" << endl;
    cout << "Highest Salary: " << highestSalary << endl;

    // Free memory
    for (auto emp : employees) {
        delete emp;
    }

    return 0;
}