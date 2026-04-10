// THE OPEN CLOSE  PRINCIPLE STATES THAT THE CLASS IS OPEN FOR EXTENSION AND CLOSE FOR MODIFICATION

#include<bits/stdc++.h>
using namespace std;

// bad design
// class Payment{
//     public:
//     void pay(string type){
//         if(type == "UPI"){
//             cout <<"UPI";
//         }
//         else{
//             cout<<"Card";
//         }
//     }
// };

class Payment{
    public:
    virtual void pay() = 0;
};

class UPI: public Payment{
    public:
    void pay() override{
        cout << "Logic for UPI payment"<<endl;
    }
};

class Card : public Payment{
    public:
    void pay() override{
        cout << "Logic for Card payment"<<endl;
    }
};

int main(){
    UPI u;
    Card c;

    c.pay();
    u.pay();

    return 0;
}