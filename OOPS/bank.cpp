#include<iostream>
using namespace std;

class BankAccount{
   int accNumber,balance;
   public:

   BankAccount(){
    cout<<"Welcome to APS bank"<<endl;
    cout<<"Sabka sath sabka vikas"<<endl;
   }

   int deposit(int d){
    balance+=d;
    return balance;
   }
   int Withdrawl(int bVal){
      balance=balance-bVal;
      return balance;
   }


   void setBalance(int bval){
    balance=bval;
   }

   void acc( int num){
    accNumber=num;
   }

   void getBalance(){
    cout<<balance<<endl;
   }

};

int main(){
    BankAccount b1,b2;
   b1.acc(1);
   b1.setBalance(4000);
   b1.getBalance();
   int dep,wd;
   cout<<b1.deposit(dep);
   cout<<endl;
   
   cout<<b1.Withdrawl(wd);
    
}