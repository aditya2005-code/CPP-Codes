#include<bits/stdc++.h>
using namespace std;

class Fib{
    unordered_map<int,int> series;
    public:
    Fib(){};

    int fib(int n){
        if( n == 0 || n == 1){
            return 1;
        }

        return fib(n-1)+fib(n-2);
    }

    int fibDP(int n){
        if(n == 0 ) return 0;
        if(n == 1) return 1;

        if(series.count(n) != 0) return series[n];

        int f = fib(n-1)+fib(n-2);
        series[n] = f;

        return series[n];
    }
};

int main(){
    int n;
    cout<<"Enter the value of  n :";
    cin >> n;

    Fib f;

    cout<<f.fib(n)<<endl;
    cout<<f.fibDP(n)<<endl;

    return 0;
}