#include<iostream>
#include<unordered_map>
using namespace std;

void binaryString(int n , int prev , string s ){
    if( n == 0){
        cout<<s<<endl;
        return;
    }

    if(prev !=  1){
        binaryString(n-1,1,s+'1');
        binaryString(n-1,0,s+'0');
    }
    else{
        binaryString(n-1,0,s+'0');
    }
    
}

int main(){
    int n;
    cin >> n;
    binaryString(n,0,"");
}