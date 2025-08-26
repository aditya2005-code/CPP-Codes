#include<iostream>
#include<unordered_map>
using namespace std;

int friendPairing(int n){
    if(n == 0 || n== 1){
        return 1;
    }

    return friendPairing(n-1)+friendPairing(n-2)*(n-1);
}

int main(){
    int n;
    cin >> n;
    int res = friendPairing(n);
    cout<<res;
    return 0;
}