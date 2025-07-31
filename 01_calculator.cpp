#include<iostream>
using namespace std;
int main (){
    float num1, num2;
    char operation;
    char choice;

    do
    {
        cout<< "Enter your First Number: ";
        cin>> num1;
        cout<< "Enter your Second Number: ";
        cin>> num2;
        cout<< "Enter your Operators ('+,-,*,/'): ";
        cin>> operation;

        switch (operation)
        {
        case '+':
            cout<< "Result is: " << num1+num2 <<endl;
            break;

            case '-':
            cout<< "Result is: " << num1-num2 <<endl;
            break;

            case '*':
            cout<< "Result is: " << num1*num2 <<endl;
            break;

            case '/':
            if (num2 != 0)
            
                cout<< "Result is: " << num1/num2 <<endl;
                else
                    cout<< "Error! Invalid Number:" <<endl;
            break;
        
            default: 
            cout<< "Invalid Operator! Try another:" <<endl;
            break;
        }

        cout<< "Do you want to continue your Calculation?(Yes/No):" <<endl;
        cin>> choice;
        
    } while (choice == 'Y' || choice == 'y');
    return 0;

}