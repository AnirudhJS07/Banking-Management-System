#include <iostream>
#include <cmath>
using namespace std;
// Anirudh Sharma 2K20/SE/17

class bank
{
    float balance, rate;

public:
    bank(float cash, float r)
    {
        balance = cash;
        rate = r;
        cout << "Successfully opened your new account!" << endl;
    }
    void deposit()
    {
        float d;
        cout << "Enter the amount you want to deposit in your account: ";
        cin >> d;
        balance += d;
        cout << "Successfully deposited the amount mentioned!" << endl;
    }
    void withdraw()
    {
        float withdrawal;
        cout << "Enter the amount you want to withdraw from your account: ";
        cin >> withdrawal;
        if (balance - withdrawal < 1000)
            cout << "Not enough cash available to withdraw" << endl;
        else
        {
            balance -= withdrawal;
            cout << "Successfully withdrawn the amount mentioned!" << endl;
        }
    }
    float calcinterest(int time)
    {
        float amount;
        amount = balance * pow((1 + (rate / 100)), time);
        float interest = amount - balance;
        balance = amount;
        return interest;
    }
    float getbalance()
    {
        return balance;
    }
    ~bank()
    {
        cout << "Hence,successfully closed your account!" << endl;
    }
};
int n = 0;
void menu(bank &ob)
{
    cout << "\tMENU\n";
    cout << "1.DEPOSIT MONEY\n";
    cout << "2.WITHDRAW MONEY\n";
    cout << "3.CALCULATE INTEREST\n";
    cout << "4.DISPLAY AVAILABLE BALANCE\n";
    cout << "5.CLOSE ACCOUNT\n";
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
        ob.deposit();
        return;
    case 2:
        ob.withdraw();
        return;
    case 3:
        int t;
        cout << "Enter the time (in years) till when you want to keep the money in bank account: ";
        cin >> t;
        cout << "The interest you got is: " << ob.calcinterest(t) << endl;
        return;
    case 4:
        cout << "The current balance is: " << ob.getbalance() << endl;
        return;
    case 5:
        n = 1;
        return;
    }
}
// Driver Code
int main()
{
    int cash, rate;
    cout << "Let's open the bank account first!\n";
    cout << "Enter initial balance: ";
    cin >> cash;
    cout << "Enter the rate of interest of the bank: ";
    cin >> rate;
    bank account(cash, rate);
    while (1)
    {
        menu(account);
        if (n == 1)
            break;
    }
    return 0;
}