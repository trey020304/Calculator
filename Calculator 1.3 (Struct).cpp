#include <iostream>
#include <limits>
#include <string>
using namespace std;

const int size = 5;

struct Calculation {
    double num1;
    double num2;
    double result;
    char op;
    string history;
};

Calculation calcu[size];

void inputdata(int index) {
    index + 1;

    while (!(cin >> calcu[index].num1 >> calcu[index].op >> calcu[index].num2) ||
           (calcu[index].op == '/' && calcu[index].num2 == 0)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (calcu[index].op == '/' && calcu[index].num2 == 0)
            cout << "Error: Division by zero is not allowed. Please try again." << endl
                 << endl;
        else
            cout << "Invalid format of the operation. Please try again." << endl << endl;
    }
}

void add(double* num1, double* num2, double* result) {
    *result = *num1 + *num2;
}

void sub(double* num1, double* num2, double* result) {
    *result = *num1 - *num2;
}

void mul(double* num1, double* num2, double* result) {
    if (*num2 == 0)
        *result = 0;
    else
        *result = *num1 * *num2;
}

void divide(double* num1, double* num2, double* result) {
    if (*num2 == 0)
        *result = 0;
    else
        *result = *num1 / *num2;
}

void displayInputHistory() {
    cout << endl
         << "Input History: " << endl;
    for (int i = 0; i < size; i++) {
        cout << endl
             << (i + 1) << ".)" << endl;
        calcu[i].history =
            (to_string(calcu[i].num1) + " " + calcu[i].op + " " +
             to_string(calcu[i].num2) + " = " + to_string(calcu[i].result));
        cout << "Memory Address: " << &calcu[i].history << endl;
        cout << "Value: " << calcu[i].history << endl;
    }
}

void resetCalculator() {
    for (int i = 0; i < size; i++) {
        calcu[i].num1 = 0;
        calcu[i].num2 = 0;
        calcu[i].result = 0;
        calcu[i].op = '\0';
        calcu[i].history = "";
    }
}

int main() {
    cout << "CALCULATOR" << endl
         << endl;
    bool repeat = true;
    while (repeat) {
        for (int i = 0; i < size; i++) {
            inputdata(i);
            switch (calcu[i].op) {
                case '+':
                    add(&calcu[i].num1, &calcu[i].num2, &calcu[i].result);
                    calcu[i].history =
                        (to_string(calcu[i].num1) + " " + calcu[i].op + " " +
                         to_string(calcu[i].num2) + " = " + to_string(calcu[i].result));
                    cout << endl
                         << "Value: " << calcu[i].history << endl;
                    cout << "Memory Address: " << &calcu[i].history << endl
                         << endl;
                    break;
                case '-':
                    sub(&calcu[i].num1, &calcu[i].num2, &calcu[i].result);
                    calcu[i].history =
                        (to_string(calcu[i].num1) + " " + calcu[i].op + " " +
                         to_string(calcu[i].num2) + " = " + to_string(calcu[i].result));
                    cout << endl
                         << "Value: " << calcu[i].history << endl;
                    cout << "Memory Address: " << &calcu[i].history << endl
                         << endl;
                    break;
                case '*':
                    mul(&calcu[i].num1, &calcu[i].num2, &calcu[i].result);
                    calcu[i].history =
                        (to_string(calcu[i].num1) + " " + calcu[i].op + " " +
                         to_string(calcu[i].num2) + " = " + to_string(calcu[i].result));
                    cout << endl
                         << "Value: " << calcu[i].history << endl;
                    cout << "Memory Address: " << &calcu[i].history << endl
                         << endl;
                    break;
                case '/':
                    if (calcu[i].num2 != 0) {
                        divide(&calcu[i].num1, &calcu[i].num2, &calcu[i].result);
                        calcu[i].history =
                            (to_string(calcu[i].num1) + " " + calcu[i].op + " " +
                             to_string(calcu[i].num2) + " = " + to_string(calcu[i].result));
                        cout << endl
                             << "Value: " << calcu[i].history << endl;
                        cout << "Memory Address: " << &calcu[i].history << endl
                             << endl;
                    } else {
                        cout << "Error: Division by zero is not allowed. Please try again." << endl
                             << endl;
                        i--;
                    }
                    break;
                default:
                    cout << "Invalid operator. Please try again." << endl << endl;
                    i--;
                    break;
            }
        }

        displayInputHistory();

        char choice;
        cout << "\n\n\nDo you want to input calculations again?\nType 'Y' or 'y' if yes, or type any input if no: ";
        cin >> choice;
        repeat = (choice == 'Y' || choice == 'y');

        if (repeat) {
            resetCalculator();
            system("cls");
            cout << "CALCULATOR" << endl
                 << endl;
        }
    }

    return 0;
}
