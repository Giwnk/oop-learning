// Task 2 - Basic Encapsulation

#include <iostream>
using namespace std;

class BankAccount
{
private:
    string ownerName;
    double balance;
public:
    BankAccount(){
        balance = 100000;
    }

    void setOwnername(string inputOwnername){
        ownerName = inputOwnername;
    }

    int depositBalance(int inputBalance){
        balance += inputBalance;
        return balance;
    }

    void withdrawBalance(int inputBalance){
        if (balance != 0)
        {
            balance -= inputBalance;
        }
        else
        {
            cout << "Can't withdraw, Your Balance is 0." << endl;
        }
        
    }

    void getBalance(){
        cout << "Owner: " << ownerName << endl;
        cout << "Your Balance is: " << balance << endl;
    }
};

int main(int argc, char const *argv[])
{
    BankAccount account1;

    account1.setOwnername("Giwank");
    account1.getBalance();

    account1.depositBalance(250000);
    account1.getBalance();

    account1.withdrawBalance(300000);
    account1.getBalance();
    return 0;
}
