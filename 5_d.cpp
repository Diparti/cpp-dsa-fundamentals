#include<iostream>
using namespace std;

class BankAccount
{
    string accountHolder;
    string accountNumber;
    double balance;
    public:

    void deposit(double n);
    void withdraw(double n);
    void display();
};

void BankAccount :: deposit(double n)
{
    balance += n;
    cout << "\nDeposit complete ,Thank you !!";
}

void BankAccount :: withdraw(double n)
{
    if(balance-n<0)
    {
        cout <<"Insufficient balance\n";
    }
    else
    {
        balance -= n;
        cout << "\nwithdraw complete ,Thank you !!\n";   
    }
}

void BankAccount :: display()
{
    cout << "\nThe amount is :" << balance;
}


int main()
{
    BankAccount user;
    double amount;

    int choice;
    do{
    cout << "\n\n---BANK ACCOUNT---";
    cout << "\nEnter 1 to deposit amount ";
    cout << "\nEnter 2 to withdraw amount ";
    cout << "\nEnter 3 to display amount ";
    cout << "\nEnter 4 to exit \n";
    cin >>choice;
    switch(choice)
    {
        case 1:
            
            cout <<"Enter amount to deposit  :";
            cin >>amount;
            user.deposit(amount);
            break;
        
        case 2:
            
            cout <<"Enter amount to widhdraw  :";
            cin >>amount;
            user.withdraw(amount);
            break;

        case 3:
            user.display();
            break;
            
        default :
            cout <<"\nInvalid choice";    
    }
    }while(choice !=4);
}
