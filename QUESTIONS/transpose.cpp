#include<iostream>
using namespace std;

int main()
{
    int rows,cols;
    cout<<"Enter the rows and columns :";
    cin>>rows>>cols;

    int arr[rows][cols];

    for(int i=0; i<rows ; i++){
        for(int j=0; j<cols ; j++){
            cout<<"Enter the arr"<<"["<<i<<"]"<<"["<<j<<"]";
            cin>>arr[i][j];
        }
    }

    // code for transpose
    int transpose[cols][rows]={0};
    for(int i=0; i<rows ; i++){
        for(int j=0; j<cols ; j++){
            transpose[j][i]=arr[i][j];
        }
    }

    // print
    swap(rows,cols);
    for(int i=0; i<rows ; i++){
        for(int j=0; j<cols ; j++){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }

  return 0;

}