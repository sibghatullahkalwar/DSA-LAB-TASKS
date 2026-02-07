#include<iostream>
using namespace std;

class BankAccount{
	public:
		double balance;
			BankAccount(){
				balance = 250;
				cout<<"Balance = "<<balance<<endl;
			}
			
			BankAccount(int ammount){
				balance = ammount;
				cout<<"Balance = "<<balance<<endl;
			}
					
};

int main(){
	BankAccount account1;
	BankAccount account2(1000);
	BankAccount account3(account2);
	account3.balance = account3.balance - 200;
	cout<<"account3 | "<<account3.balance<<endl;
	cout<<"account2 | "<<account2.balance;
	
}
