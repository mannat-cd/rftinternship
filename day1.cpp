#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    // Function to input details
    void inputDetails() {
        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Roll Number: ";
        cin >> rollNumber;

        cout << "Enter Marks: ";
        cin >> marks;
    }

    // Function to display details
    void displayDetails() const {
        cout << "\nName: " << name;
        cout << "\nRoll Number: " << rollNumber;
        cout << "\nMarks: " << marks;
        cout << "\nGrade: " << calculateGrade() << endl;
    }

    // Function to calculate grade
    char calculateGrade() const {
        if (marks >= 75)
            return 'A';
        else if (marks >= 50)
            return 'B';
        else if (marks >= 33)
            return 'C';
        else
            return 'F';
    }

    // Getter for marks
    float getMarks() const {
        return marks;
    }

    // Getter for name (for topper)
    string getName() const {
        return name;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Student> students(n);

    // Input details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        students[i].inputDetails();
    }

    // Display details
    cout << "\n--- Student Details ---\n";
    for (const auto &s : students) {
        s.displayDetails();
    }

    // Calculate average marks
    float total = 0;
    for (const auto &s : students) {
        total += s.getMarks();
    }
    float average = total / n;
    cout << "\nAverage Marks: " << average << endl;

    // Find topper
    int topperIndex = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].getMarks() > students[topperIndex].getMarks()) {
            topperIndex = i;
        }
    }

    cout << "\nClass Topper: " << students[topperIndex].getName();
    cout << " (" << students[topperIndex].getMarks() << " marks)" << endl;

    return 0;
}