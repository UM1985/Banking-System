#include <iostream>
#include <math.h>
using namespace std;

class BankAccount
{
protected:
    long long accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor
    BankAccount(long long accountNumber, string accountHolderName, double balance)
    {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    // Deposit method
    void deposit(double amount)
    {
        if (amount > 0)
        {
            this->balance += amount;
            cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount. Amount must be positive." << endl;
        }
    }

    // Withdraw method
    bool withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Withdrawal failed: Insufficient balance." << endl;
            return false;
        }
        else if (amount <= 0)
        {
            cout << "Invalid withdrawal amount. Amount must be positive." << endl;
            return false;
        }
        else
        {
            this->balance -= amount;
            cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
            return true;
        }
    }

    // Get balance method
    void getBalance()
    {
        cout << "Available Balance is " << balance << endl;
    }

    // Account info method
    void Accountinfo()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Available Balance: " << balance << endl;
    }
};

class SavingAccount : public BankAccount
{
public:
    // Constructor
    SavingAccount(long long accountNumber, string accountHolderName, double balance)
        : BankAccount(accountNumber, accountHolderName, balance) {}

    // Simple interest calculation
    void simpleinterestRate(double years, double interestRate)
    {
        double interest = balance * (interestRate / 100) * years;
        balance += interest;
        cout << "Interest Applied: " << interest << " | New Balance: " << balance << endl;
    }
};

class CheckingAccount : public BankAccount
{
protected:
    double overdraftLimit;

public:
    // Constructor
    CheckingAccount(long long accountNumber, string accountHolderName, double balance, double overdraftLimit)
        : BankAccount(accountNumber, accountHolderName, balance)
    {
        this->overdraftLimit = overdraftLimit;
    }

    // Withdraw method with overdraft limit
    bool withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid withdrawal amount. Amount must be positive." << endl;
            return false;
        }
        else if (amount > balance + overdraftLimit)
        {
            cout << "Withdrawal failed: Overdraft limit exceeded." << endl;
            return false;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
            return true;
        }
    }
};

class FixedDepositAccount : public BankAccount
{
public:
    // Constructor
    FixedDepositAccount(long long accountNumber, string accountHolderName, double balance)
        : BankAccount(accountNumber, accountHolderName, balance) {}

    // Calculate maturity amount
    void calculateMaturityAmount(double interestRate, double term)
    {
        double maturityAmount = balance * pow(1 + (interestRate / (100 * 12)), term);
        cout << "Maturity Amount after " << term << " months: " << maturityAmount << endl;
    }
};

int main()
{

    // BankAccount b1(3434456676566, "Utkarsh Patel", 23453);
    // b1.Accountinfo();
    // b1.deposit(22000);
    // b1.withdraw(5000);
    // b1.getBalance();

    // SavingAccount s1(3434456676566, "Utkarsh Patel", 23453);
    // s1.Accountinfo();
    // s1.deposit(5000);
    // s1.simpleinterestRate(3,5);
    // s1.getBalance();

    // CheckingAccount ca1(3434456676566, "Utkarsh Patel", 23453, 5000);
    // ca1.Accountinfo();
    // ca1.withdraw(29000); // Uses overdraft limit
    // ca1.getBalance();

    // FixedDepositAccount fda1(3434456676566, "Utkarsh Patel", 23453);
    // fda1.Accountinfo();
    // fda1.calculateMaturityAmount(6,5);
}