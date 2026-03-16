#include<bits/stdc++.h>
using namespace std;

class Climbing{
    unordered_map<int, int> series;
    public:
    Climbing(){}

    // Memoization
    int cs(int n) {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;
        
        if(series.count(n) != 0) return  series[n];

        int c = cs(n - 1) + cs(n - 2);
        series[n] = c;

        return series[n];
    }

    // Tabular

    int csTB(int n){
        if(n == 1) return 1;
        vector<int> tab(n+1 , 0);
        tab[1] = 1;
        tab[0] = 1;

        for(int i = 2 ; i <= n ; i++){
            tab[i] = tab[i-1] + tab[i-2];
        }

        return tab[n];
    }

};

int main(){
    int n;
    cout<<"Enter the value of n:";
    cin >> n;

    Climbing c;

    cout << c.cs(n)<<endl;
    cout<<c.csTB(n)<<endl;

    return 0;
}