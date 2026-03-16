#include<bits/stdc++.h>
using namespace std;

class Fib{
    unordered_map<int,int> series;
    public:
    Fib(){};

    // Tabular DP
    int fibTB(int n){
        if(n == 1) return 1;
        vector<int> tab(n+1 , 0);
        tab[1] = 1;
        tab[0] = 1;

        for(int i = 2 ; i <= n ; i++){
            tab[i] = tab[i-1] + tab[i-2];
        }

        return tab[n];
    }

    // Recursive
    int fib(int n){
        if( n == 0 || n == 1){
            return 1;
        }

        return fib(n-1)+fib(n-2);
    }
    // Memoization
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
    cout<<f.fibTB(n)<<endl;
    return 0;
}