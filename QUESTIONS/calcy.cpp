#include<iostream>
using namespace std;

int main()
{
    int repeat,a,b;
    char choice;
    cout<<"The Switch Calculator Welcomes You:"<<endl;
    

 do{
    cout<<"enter the two integers:";
    cin>>a;
    cin>>b;
    cout<<"Choose the operation:"<<endl<<"+ for addition:\n- for subtraction\n* for multiplication\n/for division:"<<endl;
    cin>>choice;
   switch (choice)
   {
   case '+' :
      cout<<a+b;
      break;
   case '-' :
      cout<<"Result:"<<a-b;
      break;
    case '*':
       cout<<"Result:"<<a*b;
       break;
    case '/':
        cout<<"Result:"<<a/b;
        break;
   default:
       cout<<"Result:"<<"Invalid operation";
   }
   cout<<"you want to do it again"<<endl;
   cin>>repeat;
 }while(repeat==1);

    return 0;
}