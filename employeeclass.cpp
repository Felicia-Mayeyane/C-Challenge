#include <iostream>
#include <string>
using namespace std;

// Employee Class
class Employee {
protected:
    string name;
    int age;
    double hourlyRate;
    double hoursWorked;

public:
    Employee(string name, int age, double hourlyRate, double hoursWorked)
        : name(name), age(age), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    virtual void calculatePay() {
        double regularPay = hoursWorked * hourlyRate;
        double overtimePay = 0.0;
        double totalPay = regularPay;

        if (hoursWorked > 40) {
            overtimePay = (hoursWorked - 40) * 2 * hourlyRate; 
            totalPay = regularPay + overtimePay;
        }

        cout << "Employee Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Hourly Rate: R" << hourlyRate << endl;
        cout << "Total Hours Worked: " << hoursWorked << endl;
        cout << "Regular Pay: R" << regularPay << endl;
        cout << "Overtime Pay: R" << overtimePay << endl;
        cout << "Total Pay: R" << totalPay << endl;
    }
};

class FullTimeEmployee : public Employee {
public:
    FullTimeEmployee(string name, int age, double hoursWorked)
        : Employee(name, age, 500.0, hoursWorked) {} 


    void calculatePay() override {
        double regularPay = hoursWorked * hourlyRate;
        double overtimePay = 0.0;
        double totalPay = regularPay;

        if (hoursWorked > 40) {
            overtimePay = (hoursWorked - 40) * 2 * hourlyRate; 
            totalPay = regularPay + overtimePay;
        }

        cout << "Full-Time ";
        Employee::calculatePay(); 
    }
};


class PartTimeEmployee : public Employee {
public:
    PartTimeEmployee(string name, int age, double hoursWorked)
        : Employee(name, age, 750.0, hoursWorked) {} 

    
    void calculatePay() override {
        double regularPay = hoursWorked * hourlyRate;
        double overtimePay = 0.0;
        double totalPay = regularPay;

        if (hoursWorked > 20) {
            overtimePay = (hoursWorked - 20) * 1.5 * hourlyRate; // Overtime pay 1.5  the hourly rate
            totalPay = regularPay + overtimePay;
        }

        cout << "Part-Time ";
        Employee::calculatePay(); 
    }
};

int main() {
    string empType;
    cout << "Employee type (Full-Time or Part-Time): ";
    cin >> empType;

    double hoursWorked;
    cout << "Number of working hours: ";
    cin >> hoursWorked;

    string name;
    int age;
    cout << "Employee's name: ";
    cin.ignore(); // Ignore new chr from previous input
    getline(cin, name);

    cout << "Employee's age: ";
    cin >> age;

    Employee* emp;

    if (empType == "Full-Time") {
        emp = new FullTimeEmployee(name, age, hoursWorked);
    } else if (empType == "Part-Time") {
        emp = new PartTimeEmployee(name, age, hoursWorked);
    } else {
        cout << "Enter correct creds." << endl;
        return 1;
    }

    emp->calculatePay();

    delete emp;

    return 0;
}
