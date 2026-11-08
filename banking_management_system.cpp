#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string name;
    double balance;

    string* Transaction_history;
    double* Amount_history;
    int transactionCount;

public:

    // Constructor
    BankAccount()
    {
        accountNumber = 0;
        name = "";
        balance = 0;
        transactionCount = 0;

        Transaction_history = nullptr;
        Amount_history = nullptr;
    }

    // Destructor
    ~BankAccount()
    {
        delete[] Transaction_history;
        delete[] Amount_history;
    }


    // Create account
    void createAccount(int number, string n)
    {
        accountNumber = number;
        name = n;
        balance = 0;

        cout << "Account created successfully!\n";
    }

    // Get account number
    int getAccountNumber()
    {
        return accountNumber;
    }


    //Adding the transation history and amount in new memory
    void addTransaction(string transaction, double amount)
    {
        string* temp1 = new string[transactionCount + 1];

        double* temp2 = new double[transactionCount + 1];

        for (int i = 0; i < transactionCount; i++)
        {
            temp1[i] = Transaction_history[i];
            temp2[i] = Amount_history[i];
        }

        temp1[transactionCount] = transaction;
        temp2[transactionCount] = amount;

        delete[] Transaction_history;
        delete[] Amount_history;

        Transaction_history = temp1;
        Amount_history = temp2;

        transactionCount++;
    }

    // Display account details
    void display()
    {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nAccount Holder: " << name;
        cout << "\nBalance: Rs. " << balance << endl;
    }

    // Deposit money
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance = balance + amount;
            addTransaction("Money Deposited", amount);
            cout << "Money deposited successfully!\n";
        }
        else
        {
            cout << "Invalid amount entered!\n";
        }
    }

    // Withdraw money
    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid amount entered!\n";
        }
        else if (amount > balance)
        {
            cout << "Insufficient balance!\n";
        }
        else
        {
            balance = balance - amount;
            addTransaction("Money Withdrawn", amount);
            cout << "Money withdrawn successfully!\n";
        }
    }

    // Check balance
    void checkBalance()
    {
        cout << "Current Balance: Rs. " << balance << endl;
    }

    // Show transaction history
    void showHistory()
    {
        cout << "\nTransaction History:\n";

        if (transactionCount == 0)
        {
            cout << "No transactions found.\n";
        }

        for (int i = 0; i < transactionCount; i++)
        {
            cout << i + 1 << ". " << Transaction_history[i] << " => Rs. " << Amount_history[i] << endl;
        }
    }
};

int main()
{
    const int MAX_ACCOUNTS = 10;

    BankAccount accounts[MAX_ACCOUNTS];

    int totalAccounts = 0;
    int choice, accNo, index;
    double amount;
    string name;

    do
    {
        cout << "\n===== BANKING MANAGEMENT SYSTEM =====\n";

        cout << "1. Create Account\n";
        cout << "2. View All Accounts\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Check Balance\n";
        cout << "6. Transaction History\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:  //create account

                if (totalAccounts >= MAX_ACCOUNTS)
                {
                    cout << "\nMaximum account limit reached!\n";
                    break;
                }

                if (totalAccounts < MAX_ACCOUNTS)
                {
                    cout << "Enter Account Holder Name: ";
                    cin >> name;

                    accounts[totalAccounts].createAccount(
                        1001 + totalAccounts, name
                    );

                    cout << "Your Account Number: "
                         << 1001 + totalAccounts << endl;

                    totalAccounts++;
                }
                else
                {
                    cout << "Account limit reached!\n";
                }

                break;

            case 2:  //view all accounts

                for (int i = 0; i < totalAccounts; i++)
                {
                    accounts[i].display();
                }

                if (totalAccounts == 0)
                {
                    cout << "No accounts available!\n";
                }

                break;

            case 3:  //deposite money

                if (totalAccounts == 0)
                {
                    cout << "No accounts available! Please create an account first.\n";
                    break;
                }

                cout << "Enter Account Number: ";
                cin >> accNo;

                index = -1;

                for (int i = 0; i < totalAccounts; i++)
                {
                    if (accounts[i].getAccountNumber() == accNo)
                    {
                        index = i;
                    }
                }

                if (index != -1)
                {
                    cout << "Enter Deposit Amount: ";
                    cin >> amount;

                    accounts[index].deposit(amount);
                }
                else
                {
                    cout << "Account not found!\n";
                }

                break;

            case 4:  //Withdraw money

                if (totalAccounts == 0)
                {
                    cout << "No accounts available! Please create an account first.\n";
                    break;
                }

                cout << "Enter Account Number: ";
                cin >> accNo;

                index = -1;

                for (int i = 0; i < totalAccounts; i++)
                {
                    if (accounts[i].getAccountNumber() == accNo)
                    {
                        index = i;
                    }
                }

                if (index != -1)
                {
                    cout << "Enter Withdraw Amount: ";
                    cin >> amount;

                    accounts[index].withdraw(amount);
                }
                else
                {
                    cout << "Account not found!\n";
                }

                break;

            case 5:  //Check balance

                if (totalAccounts == 0)
                {
                    cout << "No accounts available! Please create an account first.\n";
                    break;
                }

                cout << "Enter Account Number: ";
                cin >> accNo;

                index = -1;

                for (int i = 0; i < totalAccounts; i++)
                {
                    if (accounts[i].getAccountNumber() == accNo)
                    {
                        index = i;
                    }
                }

                if (index != -1)
                {
                    accounts[index].checkBalance();
                }
                else
                {
                    cout << "Account not found!\n";
                }

                break;

            case 6:  //Transaction History

                if (totalAccounts == 0)
                {
                    cout << "No accounts available! Please create an account first.\n";
                    break;
                }

                cout << "Enter Account Number: ";
                cin >> accNo;

                index = -1;

                for (int i = 0; i < totalAccounts; i++)
                {
                    if (accounts[i].getAccountNumber() == accNo)
                    {
                        index = i;
                    }
                }

                if (index != -1)
                {
                    accounts[index].showHistory();
                }
                else
                {
                    cout << "Account not found!\n";
                }

                break;

            case 0:  //Exit

                cout << "Thank you for using our bank!\n";
                break;

            default:

                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}