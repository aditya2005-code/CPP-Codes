#include<iostream>
#include<vector>
using namespace std;


void printBoard(vector<vector<char>> arr){
    int n=arr.size();
    for(int i = 0 ; i<n ; i++){
      
        for(int j = 0; j<n ; j++){
            cout<<arr[i][j]<<" ";
        }
       cout<<endl;
    }
}

bool isSafe(vector<vector<char>> arr, int row , int col){
    int n = arr.size();
    // row safety
    for(int i=0 ; i<n ; i++){
        if(arr[row][i] == 'Q'){
            return false;
        }
    }

    //col safety
    for(int i=0 ; i<row ; i++){
        if(arr[i][col] == 'Q'){
            return false;
        }
    }

    //diagonal left safety
    for(int i=row , j = col  ; i>=0 && j>=0 ; i-- , j--){
        if(arr[i][j] == 'Q'){
            return false;
        }
    }

    //diagonal right ssafety
    for(int i=row , j = col  ; i>=0 && j<arr.size() ; i-- , j++){
        if(arr[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

void nQueens(vector<vector<char>> arr, int row)
{
    int n = arr.size();
    if(row == n){
        printBoard(arr);
        return;
    }
    for( int i=0; i<n ; i++){
        if(isSafe(arr,row,i)){
            arr[row][i] = 'Q';
            nQueens(arr,row+1);
            arr[row][i]='.';
        }
    }
    
}

int main()
{
    vector<vector<char>> arr;
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    for(int i = 0 ; i<n ; i++){
        vector<char> newRow;
        for(int j = 0; j<n ; j++){
            newRow.push_back('.');
        }
        arr.push_back(newRow);
    }
    nQueens(arr,0);
    return 0; 
}