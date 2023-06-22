#include <iostream>
#include <limits>
#include <string>
using namespace std;

const int size = 5;
double num1_array[size], num2_array[size], result_array[size];
char op_array[size];
string history_array[size], *history_pointer[size];

void inputdata(int index)
{
    index + 1;

    while (!(cin >> num1_array[index] >> op_array[index] >> num2_array[index]) || num2_array[index] == 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (num2_array[index] == 0)
            cout << "Error: Division by zero is not allowed. Please try again." << endl << endl;
        else
            cout << "Invalid format of the operation. Please try again." << endl << endl;
    }
}

void add(double* num1, double* num2, double* result)
{
    *result = *num1 + *num2;
}

void sub(double* num1, double* num2, double* result)
{
    *result = *num1 - *num2;
}

void mul(double* num1, double* num2, double* result)
{
    *result = *num1 * *num2;
}

void divide(double* num1, double* num2, double* result)
{
    *result = *num1 / *num2;
}

void displayInputHistory()
{
    cout << endl << "Input History: " << endl;
    for (int i = 0; i < size; i++) {
        cout << endl << (i + 1) << ".)" << endl << endl;
        history_array[i] = (to_string(num1_array[i]) + " " + op_array[i] + " " + to_string(num2_array[i]) + " = " + to_string(result_array[i]));
        history_pointer[i] = &history_array[i];
        cout << "Memory Address: " << &history_array[i] << endl;
        cout << "Value: " << *history_pointer[i] << endl;
    }
}

void resetCalculator()
{
    for (int i = 0; i < size; i++) {
        num1_array[i] = 0;
        num2_array[i] = 0;
        result_array[i] = 0;
        op_array[i] = '\0';
        history_array[i] = "";
        history_pointer[i] = nullptr;
    }
}

int main()
{
    cout << "CALCULATOR" << endl << endl;
    bool repeat = true;
    while (repeat) {
        for (int i = 0; i < size; i++)
        {
            inputdata(i);
            switch (op_array[i])
            {
                case '+':
                    add(&num1_array[i], &num2_array[i], &result_array[i]);
                    history_array[i] = (to_string(num1_array[i]) + " " + op_array[i] + " " + to_string(num2_array[i]) + " = " + to_string(result_array[i]));
                    history_pointer[i] = &history_array[i];
                    cout << endl << "Value: " << *history_pointer[i] << endl;
                    cout << "Memory Address: " << history_pointer[i] << endl << endl;
                    break;
                case '-':
                    sub(&num1_array[i], &num2_array[i], &result_array[i]);
                    history_array[i] = (to_string(num1_array[i]) + " " + op_array[i] + " " + to_string(num2_array[i]) + " = " + to_string(result_array[i]));
                    history_pointer[i] = &history_array[i];
                    cout << endl << "Value: " << *history_pointer[i] << endl;
                    cout << "Memory Address: " << history_pointer[i] << endl << endl;
                    break;
                case '*':
                    mul(&num1_array[i], &num2_array[i], &result_array[i]);
                    history_array[i] = (to_string(num1_array[i]) + " " + op_array[i] + " " + to_string(num2_array[i]) + " = " + to_string(result_array[i]));
                    history_pointer[i] = &history_array[i];
                    cout << endl << "Value: " << *history_pointer[i] << endl;
                    cout << "Memory Address: " << history_pointer[i] << endl << endl;
                    break;
                case '/':
                    if (num2_array[i] != 0)
                    {
                        divide(&num1_array[i], &num2_array[i], &result_array[i]);
                        history_array[i] = (to_string(num1_array[i]) + " " + op_array[i] + " " + to_string(num2_array[i]) + " = " + to_string(result_array[i]));
                        history_pointer[i] = &history_array[i];
                        cout << endl << "Value: " << *history_pointer[i] << endl;
                        cout << "Memory Address: " << history_pointer[i] << endl << endl;
                    }
                    else
                    {
                        cout << "Error: Division by zero is not allowed. Please try again." << endl << endl;
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
        cout << "Do you want to input calculations again? Type 'Y' or 'y' if yes, or type any input if no: ";
        cin >> choice;
        repeat = (choice == 'Y' || choice == 'y');

        if (repeat) {
            resetCalculator();
            system("cls");
            cout << "CALCULATOR" << endl << endl;
        }
    }

    return 0;
}
