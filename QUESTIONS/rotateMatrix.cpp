#include<iostream>
using namespace std;

int main()
{
    int rows,cols;
    cout<<"Enter the rows and cols:";
    cin>>rows>>cols;

    int arr[rows][cols];

     for(int i=0 ; i<rows ; i++){
        for(int j=0; j<cols ; j++){
            cout<<"Enter the value of arr "<<"["<<i<<"]"<<"["<<j<<"] :";
            cin>>arr[i][j];
        }
    }

    //logic for rotation
    int rotated[cols][rows];
     for(int i=rows ; i>=0 ; i++){
        for(int j=0; j<=cols ; j++){
            rotated[i][j]=arr[j][i];
        }
    }

     for(int i=0 ; i<cols ; i++){
        for(int j=0; j<rows ; j++){
            cout<<rotated[i][j]<<" ";
        }
    }


    return 0;
}