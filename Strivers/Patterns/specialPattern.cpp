#include<bits/stdc++.h>
using namespace std;

void specialPattern(int n){
    // for(int i = 0 ; i  < 2 * n - 1 ; i++){
    //     for(int j = 0 ; j > 2*n-1 ; j++){
    //         int top = i;
    //         int left = j;
    //         int bottom = (2*n-2)-i;
    //         int right = (2*n-2)-j;

    //         int minDist = min(min(top, bottom), min(left, right));

    //         cout<<n-minDist<<" ";
    //     }
    //     cout<<endl;
    // }
    for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < 2 * n - 1; j++) {
                int top = i;
                int left = j;
                int bottom = (2 * n - 2) - i;
                int right = (2 * n - 2) - j;

                int minDist = min(min(top, bottom), min(left, right));

                cout << (n - minDist) << " ";
            }
            cout << endl;
        }
}

int main(){
    int n;
    cin >> n;

    specialPattern(n);

    return 0;
}