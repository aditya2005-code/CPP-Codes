#include<iostream>
using namespace std;

void SpiralMaatrix( int arr[][4],int rows,int cols ){
    int srow=0,scol=0,erow=rows-1,ecols=cols-1;

    while(srow<=erow && scol<=ecols){

        //top
        for(int i=scol ; i<=ecols ; i++){
            cout<<arr[srow][i]<<" ";
        }

        //right
        for(int j=srow+1 ; j<=erow ; j++){
            if(srow==erow)
            break;
            cout<<arr[j][ecols]<<" ";
        }

        //bottom

        for(int i=ecols-1 ; i<=scol ; i--){
            if(ecols==scol)
            break;
            cout<<arr[erow][i]<<" ";
        }

        //left

        for(int j=erow-1 ; j<= srow+1 ; j--){
            cout<<arr[j][scol]<<" ";
        }
        srow++; scol++;
        erow--; ecols--;

    }
}



int main(){
    int row,col;
    cout<<"Enter the number of row and cols respectively :";
    cin>>row>>col;

    int arr[row][col];

    cout<<"Enter the elements of matrix";
    for(int i=0 ; i<=row ; i++){
        for(int j=0; j<=col ; j++){
            cout<<"Enter the value of arr "<<"["<<i<<"]"<<"["<<j<<"] :";
            cin>>arr[i][j];
        }
    }


    SpiralMaatrix(arr,row,col);
    return 0;

}