#include <iostream>
#include <limits>
using namespace std;

const int size = 5;
double num1_array[size];
double num2_array[size];
double result_array[size];
char op_array[size];

void inputdata(int index)
{
    index + 1;

    while (!(cin >> num1_array[index] >> op_array[index] >> num2_array[index]))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please try again" << endl << endl;
    }
}

void add(int index)
{
    if (op_array[index] == '+') {
        result_array[index] = num1_array[index] + num2_array[index];
        cout << num1_array[index] << " " << op_array[index] << " " << num2_array[index] << " = " << result_array[index] << endl;
    }
}

void sub(int index)
{
    if (op_array[index] == '-') {
        result_array[index] = num1_array[index] - num2_array[index];
        cout << num1_array[index] << " " << op_array[index] << " " << num2_array[index] << " = " << result_array[index] << endl;
    }
}

void mul(int index)
{
    if (op_array[index] == '*') {
        result_array[index] = num1_array[index] * num2_array[index];
        cout << num1_array[index] << " " << op_array[index] << " " << num2_array[index] << " = " << result_array[index] << endl;
    }
}

void divide(int index)
{
    if (op_array[index] == '/') {
        result_array[index] = num1_array[index] / num2_array[index];
        cout << num1_array[index] << " " << op_array[index] << " " << num2_array[index] << " = " << result_array[index] << endl;
    }
}

void displayInputHistory()
{
    cout << endl << "Input History: " << endl;
    for (int i = 0; i < size; i++) {
        cout << num1_array[i] << " " << op_array[i] << " " << num2_array[i] << " = " << result_array[i] << endl;
    }
}

int main()
{
    cout << "CALCULATOR" << endl << endl;
    for (int i = 0; i < size; i++)
    {
        inputdata(i);
        add(i);
        sub(i);
        mul(i);
        divide(i);
    }
    
    displayInputHistory();
    
    return 0;
}
