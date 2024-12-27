#include<iostream>
using namespace std;

void Input_array(int arr[],int n)
{
    for(int i=0; i<n ; i++){
        cin>>arr[i];
    }
}

int best_price(int arr[] , int n)
{
    int sale,buy[100];
    buy[0]= INT16_MAX;

    for(int i=1; i<n ; i++){

        buy[i]= min(buy[i-1],arr[i-1]);
        cout<<buy[i]<<" ";

      }
    int max_profit=INT16_MIN;

    for(int i=1 ; i<n ; i++){
        int profit= arr[i]-buy[i];
        max_profit=  max(profit,max_profit);

    }    
    return max_profit;
    
}

int main()
{
   int n;
   cout<<"Enter the value of n:";
   cin>>n;
   int arr[n];

   cout<<"\nEnter the Elements of the array:";
   Input_array(arr,n);

   int result=best_price(arr,n);

   cout<<"The max_profit is :"<<result<<endl;


   return 0;

}