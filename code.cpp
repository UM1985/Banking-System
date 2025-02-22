#include <iostream>
using namespace std;

class BankAccount
{
protected:
    long long accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(long long accountNumber, string accountHolderName, double balance)
    {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    void deposit(double amount)
    {

        this->balance = balance + amount;

        cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
    }
    double withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Withdrawal failed: Insufficient balance." << endl;
        }
        else
        {
            this->balance = balance - amount;
            cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
        }
    }

    void getBalance()
    {

        cout << "Available Balance is " << balance << endl;
    }

    void Accountinfo()
    {
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder Name : " << accountHolderName << endl;
        cout << "Available Balance : " << balance << endl;
    }
};

class SavingAccount : public BankAccount
{
public:
    SavingAccount(long long accountNumber, string accountHolderName, double balance) : BankAccount(accountNumber, accountHolderName, balance)
    {
    }

    void simpleinterestRate(double years, double interestRate)
    {
        double interest = balance * (interestRate / 100) * years;
        balance += interest;
        cout << "Interest Applied: " << interest << " | New Balance: " << balance << endl;
    }
};

class CheckingAccount : protected BankAccount
{

    double overdraftLimit;
};

class FixedDepositAccount : protected BankAccount
{

    double term;
};

int main()
{

    // BankAccount b1(3434456676566, "Utkarsh Patel", 23453);
    // b1.Accountinfo();
    // b1.deposit(22000);
    // b1.withdraw(5000);
    // b1.getBalance();

    SavingAccount s1(3434456676566, "Utkarsh Patel", 23453);
    s1.Accountinfo();
    s1.deposit(2000);
    s1.simpleinterestRate(3,5);
    s1.getBalance();
}