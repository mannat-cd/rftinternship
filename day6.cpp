#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char op;
    char choice;

    do {
        try {
            // Input
            cout << "Enter first number: ";
            cin >> num1;

            // Check for non-numeric input
            if (cin.fail()) {
                throw "Invalid input! Please enter numbers only.";
            }

            cout << "Enter operator (+, -, *, /): ";
            cin >> op;

            cout << "Enter second number: ";
            cin >> num2;

            // Check for non-numeric input
            if (cin.fail()) {
                throw "Invalid input! Please enter numbers only.";
            }

            // Perform calculation
            switch (op) {
                case '+':
                    result = num1 + num2;
                    cout << "Result: " << result << endl;
                    break;

                case '-':
                    result = num1 - num2;
                    cout << "Result: " << result << endl;
                    break;

                case '*':
                    result = num1 * num2;
                    cout << "Result: " << result << endl;
                    break;

                case '/':
                    if (num2 == 0) {
                        throw "Error! Division by zero is not allowed.";
                    }
                    result = num1 / num2;
                    cout << "Result: " << result << endl;
                    break;

                default:
                    throw "Invalid operator entered!";
            }
        }

        // Handle errors
        catch (const char* message) {
            cout << message << endl;

            // Clear error flags and ignore bad input
            cin.clear();
            cin.ignore(1000, '\n');
        }

        // Continue or exit
        cout << "\nDo you want to continue? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Calculator exited. Goodbye!" << endl;

    return 0;
}