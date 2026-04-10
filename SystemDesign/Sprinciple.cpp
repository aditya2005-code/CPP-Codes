// A class should have only one reason to change i.e A class should do only one thing.
#include<bits/stdc++.h>
using namespace std;

// THIS STRUCTURE VIOLATES THE S DESIGN PRINCIPLE BECAUSE ITS PERFORMING MULTIPLE TASK INSTEAD OF ONE

// class Invoice{
//     public:
//     Invoice(){}

//     void sumTotal(vector<int> product){
//         int sum = 0;
//         for(int i = 0 ; i < product.size() ; i++){
//             sum += product[i];
//         }
//         cout << "The total sum of product is : " << sum<<endl;
//     }

//     void printInvoice(vector<pair<string,int>> &bill){
//         for(int i = 0 ; i  <bill.size() ; i++){
//             cout<<bill[i].first<<" "<<bill[i].second<<endl;
//         }
//     }

//     void sendThanks(){
//         cout<<"Thank  u for visiting";
//     }
// };


class Product{
     public:
     string name;
     int price;

     Product(string name , int price){
        this->name = name;
        this->price = price;
     }
};

class  ShoppingCart{
    vector<Product*> bill;
    public:

    void addProduct(Product *p){
        bill.push_back(p);
    }

    vector<Product*>& getProduct(){
        return bill;
    }

    void calculateSum(){
        int sum = 0;
        for(auto p : bill){
            sum += p->price;
        }
        cout << "Total sum is : " << sum << endl;
    }

};

class printInvoice{
    public:
    void print(vector<Product*> bill){
        
        int i = 1;

        for(auto p : bill){
            cout<< p->name << p->price << endl;
        }
    }
};

class saveToDb{
    public:
    void save(){
        cout << "Logic to save in database" << endl;
    }
};

int main(){
    ShoppingCart s;
    s.addProduct(new Product("Laptop" , 50000));
    s.addProduct(new Product("Mobile" , 10000));
    
    s.calculateSum();

    printInvoice p;
    p.print(s.getProduct());

    saveToDb d;
    d.save();

    return 0;
}
