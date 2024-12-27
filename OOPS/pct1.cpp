#include<iostream>
#include<string>
using namespace std;
 
class Insta{
    private:
       int id;
       string password;
    public:
       string user_name;
    //constructor
    Insta(int id){
        this->id=id;
    }

    //setters
    void getPassword(string password){
        this->password=password;
    }
    //getters
    string Pass(){
        return password;
    }
    
};

int main()
{
    Insta u1(101);
    u1.getPassword("Password");
    u1.user_name="aditya__84";

    cout<<u1.Pass()<<" "<<u1.user_name;
    return 0;


}