#include<iostream>
using namespace std;

class bankaccount{
    protected:
        long int accountNumber;
        string accountHolderName;
        double balance;

    public:
        void createAccount(long int accNo, string name, double initialBalance) {
            accountNumber = accNo;
            accountHolderName = name;
            balance = initialBalance;
        }

        virtual void deposit(double amount){
            if(amount > 0){
                balance += amount;
                cout<<amount<<" deposited successfully."<<endl;
            }else{
                cout<<"Invalid deposite account.";
            }
        }

        virtual void withdraw(double amount){
            if(amount > 0 && amount <= balance){
                balance -= amount;
                cout<<amount<<" withdraw successfully."<<endl;
            }else{
                cout<<"Invalid deposite account.";
            }
        }

        double getBalance(){
            return balance;
        }

        virtual void displayAccountInfo(){
            cout<<"---------Account Created Successfully---------"<<endl;
            cout<<"Account Number : "<<accountNumber<<endl;
            cout<<"Account Holder : "<<accountHolderName<<endl;
            cout<<"current balance  : "<<balance<<endl;
        }
};

class SavingAccount : public bankaccount{
    protected:
        float interestRate = 5;

    public:
        void calculateInterest(float interestRate, double balance)
        {
            cout<<"Your Balance: "<<this->balance<<endl;
            this->balance += this->balance * interestRate;
            cout << "Interest Applied. New balance is: " << this->balance << endl;
        }
        void display()
        {
            cout << "Interest Rate: " << this->interestRate << endl;
        }
};

class CheckingAccount : public bankaccount {
    protected:
        double overdraftLimit = 5000;

    public:
        void checkOverdraft(double withdrawAmount) {
            if (withdrawAmount <= this->balance + overdraftLimit && this->balance > 0) {
                withdraw(withdrawAmount);
            } else {
                cout << "Withdrawal amount exceeds balance and overdraft limit." << endl;
            }
        }

        void display() {
            cout << "Overdraft Limit: " << this->overdraftLimit << endl;
        }
};

class FixedDepositAccount : public bankaccount {
    protected:
        int term;
        float interestRate = 5;

    public:
        void calculateInterest() {
            cout << "Term: " << term << " months" << endl;
            cout << "Your Balance: " << this->balance << endl;
            this->balance += this->balance * interestRate * term / 12;
            cout << "Interest Applied. New balance is: " << this->balance << endl;
        }

        void display() {
            cout << "Term: " << term << " Months" << endl;
        }
};

int main(){
    int accNo;
    string name;
    double initaialBalance;
    char accountType;

    cout<<"---------Create Bank Account---------"<<endl;
    cout<<"Enter Account Number : ";
    cin>>accNo;
    cout<<"Enter Account Holder Name : ";
    cin>>name;
    cout<<"Enter Initalial Balance : ";
    cin>>initaialBalance;

    cout<<endl;

    cout<<"---------select Account type---------"<<endl;
    cout<<"press 'S' for Saving Account."<<endl;
    cout<<"press 'C' for Checking Account."<<endl;
    cout<<"press 'F' for Fixed Deposite Account."<<endl;
    cout<<"Enter your Choice: ";
    cin>>accountType;

    SavingAccount savingAcc;
    CheckingAccount checkingAcc;
    FixedDepositAccount fixedAcc;

    switch(accountType){
        case 'S':
            savingAcc.createAccount(accNo, name, initaialBalance);
            savingAcc.displayAccountInfo();
            break;
        case 'C':
            checkingAcc.createAccount(accNo, name, initaialBalance);
            checkingAcc.displayAccountInfo();
            break;
        case 'F':
            fixedAcc.createAccount(accNo, name, initaialBalance);
            fixedAcc.displayAccountInfo();
            break;
        default:
            cout << "Invalid account type.\n";
            return 0;
    }

    int choice;
    double depositAmount,withdrawAmount;

    cout<<endl;

    do{
        cout<<"--------- Menu ---------"<<endl;
        cout<<"1. Deposite Money"<<endl;
        cout<<"2. Withdraw money"<<endl;
        cout<<"3. Get Balance"<<endl;
        cout<<"4. Display account Information"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"\nEnter amount to deposite: ";
                cin>>depositAmount;
                    if(accountType == 'S'){
                        savingAcc.deposit(depositAmount);
                    }
                    else if(accountType == 'C'){
                        checkingAcc.deposit(depositAmount);
                    }
                    else if(accountType == 'F') {
                        fixedAcc.deposit(depositAmount);
                    }
                break;
            case 2:
                cout<<"\nEnter amount to withdraw: ";
                cin>>withdrawAmount;
                if(accountType == 'S'){ 
                    savingAcc.withdraw(withdrawAmount);
                }
                else if(accountType == 'C') {
                    checkingAcc.withdraw(withdrawAmount);
                }
                else if(accountType == 'F') {
                    fixedAcc.withdraw(withdrawAmount);
                }
                break;
            case 3:
                if(accountType == 'S'){
                    cout << "Current balance: " << savingAcc.getBalance() << endl;
                }
                else if(accountType == 'C'){
                    cout << "Current balance: " << checkingAcc.getBalance() << endl;
                }
                else if(accountType == 'F'){ 
                    cout << "Current balance: " << fixedAcc.getBalance() << endl;
                }
                break;
            case 4:
                if(accountType == 'S'){
                    savingAcc.displayAccountInfo();
                }
                else if(accountType == 'C'){
                    checkingAcc.displayAccountInfo();
                }
                else if(accountType == 'F'){
                    fixedAcc.displayAccountInfo();
                }
                break;
            case 5:
                cout<<"Exiting... Thank you!.";
                break;
            default:
                cout<<"Invalid Option.";
        }

    }while(choice!= 5);

    return 0;

}