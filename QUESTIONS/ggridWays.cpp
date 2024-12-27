#include<iostream>
using namespace std;

int gridWays(int row, int col ,int n , int m)
{
    if(row == n-1 && col == m-1){
        return 1;
    }
    if(row >=n || col>= m){
        return 0;
    }

    int val1 = gridWays(row,col+1,n,m);
    int val2 = gridWays(row+1,col,n,m);

    return val1+val2;
}

int main()
{
    int n,m;
    cout<<"Enter the valuue of n & m :";
    cin>>n>>m;

    int res=gridWays(0,0,n,m);
    cout<<res;
    return 0;
}