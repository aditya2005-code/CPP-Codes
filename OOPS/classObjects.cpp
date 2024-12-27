#include<iostream>
#include<string>
using namespace std;

class Students{
    //Properties
    private:
    int rollNo;
    string name;
    public:
    float cgpa;

    //methods
    void getCgpa(){
        cout<<cgpa*10<<endl;
    }

    //Setters

    void enterName(string nameVal){
        name=nameVal;
    }

    void enterRollno(int rollVal){
        rollNo=rollVal;
    }

    //Getters

    string nameo(){
        return name;
    }
    int rollCall(){
        return rollNo;
    }

};


int main()
{
   Students s1;
   cout<<"Enter the student name :";
   s1.enterName("Aditya");
   s1.enterRollno(2023);

   cout<<s1.nameo()<<" "<<s1.rollCall();
   return 0;
}