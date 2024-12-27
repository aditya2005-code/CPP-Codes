#include<iostream>
using namespace std;

void Diagonal_sum( int arr[][4], int rows, int cols)
{
    int p=0,q=0;
        for(int i=0 ; i<=rows ; i++){
            for(int j=0; j<=cols ; j++){
                if(i==j){
                    p+=arr[i][j];
                }
                else if(j=cols-i-1){
                    q+=arr[i][j];
                }
            }
        }
    
    cout<<"\nThe sum of the diagonal is: "<<p+q;
}

int main()
{
    int rows,cols ;
    cout<<"Enter the value n:";
    cin>>rows>>cols;

    int arr[rows][cols];

    for(int i=0 ; i<=rows ; i++){
        for(int j=0; j<=cols ; j++){
            cout<<"Enter the value of arr "<<"["<<i<<"]"<<"["<<j<<"] :";
            cin>>arr[i][j];
        }
    }

    Diagonal_sum(arr ,4 ,4);

    return 0;


}